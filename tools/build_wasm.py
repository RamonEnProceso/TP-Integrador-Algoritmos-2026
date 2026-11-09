#!/usr/bin/env python3
"""
build_wasm.py - Compila el TP de C++ (solo iostream/fstream) a WebAssembly.

Hace tres cosas por vos:
  1. Valida que solo uses <iostream> y <fstream>.
  2. Genera un "puente" para que cin NO se cuelgue en el navegador (sin tocar tu código).
  3. Genera una página con una terminal, y guarda tus archivos de datos en localStorage.

Uso (desde la raíz del repo):
    python build_wasm.py                    # compila TP_Parque -> carpeta web/
    python build_wasm.py TP_Parque --salida docs/parque
    python build_wasm.py --dry-run          # genera todo pero NO llama a em++
"""

import argparse
import json
import re
import shutil
import subprocess
import sys
from pathlib import Path

HEADERS_PERMITIDOS = {"iostream", "fstream"}
EXTENSIONES_CODIGO = {".cpp", ".h", ".hpp"}

# Prefijo de las claves en localStorage, para no pisar otras cosas de tu portfolio.
PREFIJO_STORAGE = "tpParque:"

# ---------------------------------------------------------------------------
# PLANTILLAS: el contenido de los archivos que el script va a generar.
# ---------------------------------------------------------------------------

SHIM_H = r"""
#ifndef WASM_SHIM_H
#define WASM_SHIM_H

// Este header se inyecta en TODOS tus .cpp con -include (no tocás tu código).
#include <iostream>
#include <streambuf>

// La implementación real vive en wasm_shim.cpp (una sola vez, para evitar duplicados).
extern "C" int web_leer_linea(char* destino, int maximo);

// Un "streambuf" es la pieza que le dice a un istream de dónde sacar los caracteres.
// Cuando se queda sin caracteres llama a underflow(): ahí pedimos una línea a la página.
class WebStdinBuf : public std::streambuf {
    char buffer[1024];

protected:
    int_type underflow() override {
        if (gptr() < egptr()) {
            return traits_type::to_int_type(*gptr());
        }
        std::cout.flush();  // que el prompt aparezca ANTES de esperar al usuario
        int n = web_leer_linea(buffer, static_cast<int>(sizeof(buffer)));
        if (n <= 0) {
            return traits_type::eof();
        }
        setg(buffer, buffer, buffer + n);
        return traits_type::to_int_type(*gptr());
    }
};

// 'inline' (C++17) = una única instancia compartida por todos los .cpp.
inline WebStdinBuf web_stdin_buf;
inline std::istream web_cin(&web_stdin_buf);

// Desde acá en adelante, cada 'cin' de tu código pasa a ser 'web_cin'.
#define cin web_cin

#endif
"""

SHIM_CPP = r"""
#include "wasm_shim.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>

// EM_ASYNC_JS: una función C++ cuyo cuerpo es JavaScript y que puede ESPERAR (await).
// Con -sASYNCIFY, el programa entero se "congela" acá hasta que el usuario apriete Enter.
EM_ASYNC_JS(int, web_leer_linea, (char* destino, int maximo), {
    const linea = await window.tpParque.leerLinea();   // incluye el '\n' final
    const bytes = new TextEncoder().encode(linea);
    const n = Math.min(bytes.length, maximo);
    HEAPU8.set(bytes.subarray(0, n), destino);
    return n;
});

#else
// Versión nativa: SOLO para probar este puente en tu PC con g++ (lee del teclado real).
#include <cstdio>
extern "C" int web_leer_linea(char* destino, int maximo) {
    if (!std::fgets(destino, maximo, stdin)) {
        return 0;
    }
    int n = 0;
    while (destino[n] != '\0') {
        n++;
    }
    return n;
}
#endif
"""

HTML = r"""<!doctype html>
<html lang="es">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>TP Parque de Diversiones</title>
<style>
  body { margin: 0; background: #0d1117; color: #e6edf3; font-family: ui-monospace, Consolas, monospace; }
  #app { max-width: 900px; margin: 0 auto; padding: 16px; }
  #salida { height: 70vh; overflow-y: auto; margin: 0; padding: 12px; background: #010409;
            border: 1px solid #30363d; border-radius: 6px; white-space: pre-wrap; word-break: break-word; }
  #entrada { display: flex; gap: 8px; margin-top: 8px; }
  #linea { flex: 1; padding: 8px; background: #161b22; color: inherit; border: 1px solid #30363d;
           border-radius: 6px; font: inherit; }
  button { padding: 8px 14px; background: #238636; color: #fff; border: 0; border-radius: 6px; font: inherit; cursor: pointer; }
  button.peligro { background: #8b1d1d; }
  button.descarga { background: #1f6feb; }
  #acciones { display: flex; gap: 8px; margin-top: 8px; flex-wrap: wrap; }
  button:disabled, #linea:disabled { opacity: .5; cursor: not-allowed; }
</style>
</head>
<body>
<div id="app">
  <pre id="salida"></pre>
  <form id="entrada" autocomplete="off">
    <input id="linea" type="text" placeholder="Escribí acá y apretá Enter" disabled>
    <button type="submit">Enviar</button>
  </form>
  <div id="acciones">
    <button class="descarga" id="descargar" type="button" disabled>Descargar reporte</button>
    <button class="peligro" id="borrar" type="button">Borrar datos guardados y reiniciar</button>
  </div>
</div>

<script>
// ---- Configuración que completa el script de Python ----
const PREFIJO = __PREFIJO__;
const EXCLUIDOS = new Set(__EXCLUIDOS__);   // archivos que NO se guardan en localStorage
const REPORTE = __REPORTE__;                // archivo que se puede descargar a la PC
const CARPETA = "/datos";

const botonDescarga = document.getElementById("descargar");
const salida = document.getElementById("salida");
const form = document.getElementById("entrada");
const campo = document.getElementById("linea");

// ---- Salida: el C++ escribe BYTE por BYTE; los juntamos y decodificamos como UTF-8 ----
const decodificador = new TextDecoder("utf-8");
let pendientes = [];

function escribirByte(byte) { pendientes.push(byte & 255); }

function vaciarSalida() {
  if (pendientes.length === 0) return;
  salida.textContent += decodificador.decode(new Uint8Array(pendientes), { stream: true });
  pendientes = [];
  salida.scrollTop = salida.scrollHeight;
}

// ---- Persistencia: archivos binarios <-> texto base64 (localStorage solo guarda texto) ----
function aBase64(bytes) {
  let binario = "";
  const trozo = 0x8000;                       // de a pedazos, para no reventar la pila
  for (let i = 0; i < bytes.length; i += trozo) {
    binario += String.fromCharCode.apply(null, bytes.subarray(i, i + trozo));
  }
  return btoa(binario);
}

function desdeBase64(texto) {
  const binario = atob(texto);
  const bytes = new Uint8Array(binario.length);
  for (let i = 0; i < binario.length; i++) bytes[i] = binario.charCodeAt(i);
  return bytes;
}

function cargarDatos() {                      // corre ANTES de main()
  const FS = Module.FS;
  try { FS.mkdir(CARPETA); } catch (e) { /* ya existía */ }
  try {
    for (let i = 0; i < localStorage.length; i++) {
      const clave = localStorage.key(i);
      if (!clave.startsWith(PREFIJO)) continue;
      const nombre = clave.slice(PREFIJO.length);
      FS.writeFile(CARPETA + "/" + nombre, desdeBase64(localStorage.getItem(clave)));
    }
  } catch (e) { console.warn("No pude cargar datos guardados:", e); }
}

function persistir() {                        // copia el sistema de archivos virtual -> localStorage
  try {
    const FS = Module.FS;
    const existentes = new Set();
    for (const nombre of FS.readdir(CARPETA)) {
      if (nombre === "." || nombre === ".." || EXCLUIDOS.has(nombre)) continue;
      existentes.add(nombre);
      localStorage.setItem(PREFIJO + nombre, aBase64(FS.readFile(CARPETA + "/" + nombre)));
    }
    // Si el programa borró un archivo, lo borramos también de localStorage.
    for (let i = localStorage.length - 1; i >= 0; i--) {
      const clave = localStorage.key(i);
      if (clave.startsWith(PREFIJO) && !existentes.has(clave.slice(PREFIJO.length))) {
        localStorage.removeItem(clave);
      }
    }
  } catch (e) { console.warn("No pude guardar en localStorage:", e); }
}

// ---- Descarga: del sistema de archivos virtual a la carpeta Descargas de la PC ----
function actualizarBotonReporte() {
  let existe = false;
  try { Module.FS.readFile(CARPETA + "/" + REPORTE); existe = true; } catch (e) { /* todavía no existe */ }
  botonDescarga.disabled = !existe;
}

botonDescarga.addEventListener("click", () => {
  try {
    const bytes = Module.FS.readFile(CARPETA + "/" + REPORTE);
    const blob = new Blob([bytes], { type: "text/plain;charset=utf-8" });
    const url = URL.createObjectURL(blob);
    const enlace = document.createElement("a");
    enlace.href = url;
    enlace.download = REPORTE;                // el nombre con el que se guarda
    document.body.appendChild(enlace);
    enlace.click();                           // simula el clic en un enlace de descarga
    enlace.remove();
    setTimeout(() => URL.revokeObjectURL(url), 1000);   // liberar la memoria del Blob
  } catch (e) {
    alert("Todavía no se generó " + REPORTE + ". Generalo desde el menú del programa.");
  }
});

// ---- Entrada: el C++ llama a leerLinea() y se queda esperando la Promise ----
let resolverLinea = null;

window.tpParque = {
  leerLinea() {
    vaciarSalida();
    persistir();                              // cada vez que el programa espera, guardamos
    actualizarBotonReporte();
    campo.disabled = false;
    campo.focus();
    return new Promise((resolver) => { resolverLinea = resolver; });
  }
};

form.addEventListener("submit", (evento) => {
  evento.preventDefault();
  if (resolverLinea === null) return;
  const linea = campo.value;
  campo.value = "";
  campo.disabled = true;
  salida.textContent += linea + "\n";         // "eco", como haría una consola real
  const resolver = resolverLinea;
  resolverLinea = null;
  resolver(linea + "\n");                     // despierta al C++
});

document.getElementById("borrar").addEventListener("click", () => {
  for (let i = localStorage.length - 1; i >= 0; i--) {
    const clave = localStorage.key(i);
    if (clave.startsWith(PREFIJO)) localStorage.removeItem(clave);
  }
  location.reload();
});

// ---- Configuración que lee Emscripten (tiene que existir ANTES de cargar parque.js) ----
window.Module = {
  stdout: escribirByte,
  stderr: escribirByte,
  preRun: [cargarDatos],
  onExit() {
    vaciarSalida();
    persistir();
    actualizarBotonReporte();
    salida.textContent += "\n[Programa finalizado]\n";
    campo.disabled = true;
  }
};
</script>
<script src="parque.js"></script>
</body>
</html>
"""

# ---------------------------------------------------------------------------
# FUNCIONES
# ---------------------------------------------------------------------------


def escribir_texto(ruta: Path, contenido: str):
    """Escribe un archivo de texto y lo cierra SIEMPRE, pase lo que pase."""
    f = open(ruta, "w", encoding="utf-8", newline="\n")
    try:
        f.write(contenido)
    finally:
        f.close()


def encontrar_archivos(carpeta: Path, ignorar: Path):
    """Devuelve (fuentes .cpp, todos los archivos de código), ignorando la carpeta de salida."""
    todos = []
    for p in sorted(carpeta.rglob("*")):
        if not p.is_file() or p.suffix not in EXTENSIONES_CODIGO:
            continue
        if ignorar.resolve() in p.resolve().parents:
            continue
        todos.append(p)
    fuentes = [p for p in todos if p.suffix == ".cpp"]
    return fuentes, todos


def validar_includes(archivos):
    """Busca '#include <algo>' y marca los que no estén en HEADERS_PERMITIDOS."""
    patron = re.compile(r"^\s*#\s*include\s*<([^>]+)>")
    problemas = []

    for ruta in archivos:
        f = open(ruta, "r", encoding="utf-8", errors="replace")
        try:
            for numero, linea in enumerate(f, start=1):
                coincidencia = patron.match(linea)
                if coincidencia and coincidencia.group(1) not in HEADERS_PERMITIDOS:
                    problemas.append(f"{ruta}:{numero} -> <{coincidencia.group(1)}>")
        finally:
            f.close()

    return problemas


def generar_puente(puente: Path, salida: Path, excluidos, reporte: str):
    """Escribe el shim de C++ y la página web."""
    puente.mkdir(parents=True, exist_ok=True)
    escribir_texto(puente / "wasm_shim.h", SHIM_H.lstrip())
    escribir_texto(puente / "wasm_shim.cpp", SHIM_CPP.lstrip())

    pagina = HTML.replace("__PREFIJO__", json.dumps(PREFIJO_STORAGE))
    pagina = pagina.replace("__EXCLUIDOS__", json.dumps(sorted(excluidos)))
    pagina = pagina.replace("__REPORTE__", json.dumps(reporte))
    escribir_texto(salida / "index.html", pagina)


def armar_comando(compilador: str, fuentes, carpeta_fuente: Path, salida: Path, puente: Path):
    """Arma la lista de argumentos para em++ (el 'g++' de Emscripten: enlaza la biblioteca de C++)."""
    comando = [compilador]
    comando += [str(p) for p in fuentes]
    comando += [str(puente / "wasm_shim.cpp")]
    comando += [
        "-I", str(carpeta_fuente),
        "-include", str((puente / "wasm_shim.h").resolve()),   # inyecta el puente en cada .cpp
        "-std=c++17", "-O2", "-Wall", "-Wextra",
        "-sASYNCIFY",                       # permite que el programa "espere" sin colgar el navegador
        "-sASYNCIFY_STACK_SIZE=65536",      # espacio para guardar el estado mientras espera
        "-sALLOW_MEMORY_GROWTH=1",
        "-sEXIT_RUNTIME=1",
        "-sFORCE_FILESYSTEM=1",
        "-sEXPORTED_RUNTIME_METHODS=FS",    # para que la página pueda leer/escribir archivos
        "-o", str(salida / "parque.js"),
    ]
    return comando


def main() -> int:
    parser = argparse.ArgumentParser(description="C++ -> WebAssembly con Emscripten")
    parser.add_argument("fuente", type=Path, nargs="?", default=Path("TP_Parque"),
                        help="carpeta con el código C++ (por defecto TP_Parque)")
    parser.add_argument("--salida", type=Path, default=Path("web"), help="carpeta de salida")
    parser.add_argument("--reporte", default="reporte_dia.txt",
                        help="archivo que se descarga con un botón y NO se guarda en localStorage")
    parser.add_argument("--excluir", action="append", default=[],
                        help="otro archivo que NO se guarda en localStorage (repetible)")
    parser.add_argument("--dry-run", action="store_true",
                        help="genera los archivos y muestra el comando, pero no ejecuta em++")
    args = parser.parse_args()

    # El reporte siempre queda excluido: se descarga, no se persiste.
    excluidos = set(args.excluir) | {args.reporte}

    # which() devuelve la ruta completa (en Windows, con su .bat), así subprocess no se pierde.
    compilador = shutil.which("em++")
    if compilador is None:
        if not args.dry_run:
            print("ERROR: no encuentro 'em++'. Instalá emsdk y activá el entorno (emsdk_env).")
            return 1
        compilador = "em++"

    if not args.fuente.is_dir():
        print(f"ERROR: '{args.fuente}' no es una carpeta.")
        return 1
    fuentes, todos = encontrar_archivos(args.fuente, args.salida)
    if not fuentes:
        print(f"ERROR: no hay archivos .cpp en '{args.fuente}'.")
        return 1

    problemas = validar_includes(todos)
    if problemas:
        print("ATENCIÓN: includes fuera de la lista permitida:")
        for p in problemas:
            print("  ", p)
        return 1

    args.salida.mkdir(parents=True, exist_ok=True)
    puente = args.salida / "_puente"
    generar_puente(puente, args.salida, excluidos, args.reporte)

    comando = armar_comando(compilador, fuentes, args.fuente, args.salida, puente)
    print(f"{len(fuentes)} archivos .cpp encontrados.")

    if args.dry_run:
        print("\n[dry-run] Comando que se ejecutaría:\n", " ".join(comando))
        print(f"[dry-run] Archivos generados en '{args.salida}/' (incluye _puente/).")
        return 0

    try:
        print("Ejecutando em++...")
        resultado = subprocess.run(comando)
    finally:
        # El puente solo se necesita para compilar: no hace falta subirlo a tu portfolio.
        shutil.rmtree(puente, ignore_errors=True)

    if resultado.returncode != 0:
        print("La compilación falló. Leé los errores de arriba.")
        return resultado.returncode

    print(f"\nListo. Archivos en '{args.salida}/': index.html, parque.js, parque.wasm")
    print(f"Probalo con:  python -m http.server -d {args.salida} 8000")
    print("y abrí http://localhost:8000")
    return 0


if __name__ == "__main__":
    sys.exit(main())