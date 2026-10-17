# INFORME ENTREGA 2 — Parque de Diversiones

> Autor: Ramón. Documento generado leyendo el repo real (git log / git diff + código).
> Alcance: desde el último commit de la Entrega 1 hasta el estado actual (HEAD + cambios sin commitear).
>
> **Referencia de commits** (usada para el "antes"): el último commit de código de la Entrega 1 es
> `02c4d5a` (2026-09-19, *"fix: Arreglar puntero a lista de visitantes"*). El estado actual es HEAD
> `a000e08` más todo lo que está sin commitear (working tree). El commit `da3a5e1` (2026-09-20,
> *"refactor: Eliminar funcion nunca utilizada"*) es el último ajuste post-Entrega 1 y también entra
> en el diff: borró `calcularPromedio`.

---

## 1. Resumen de cambios desde la Entrega 1

### Qué se agregó (commiteado, `02c4d5a..HEAD`)
- **Colas** (Joaquín): 6 funciones en `logica/cola/` (`encolarVisitante`, `desencolarVisitante`,
  `atenderSiguienteVisitante`, `estaEnCola`, `liberarCola`, `mostrarFilaJuego`), el struct `Cola`
  (`structs/cola.h`), el nuevo campo `Cola filasJuegos[MAX_JUEGOS]` en `DatosParque`, y un menú
  nuevo `menu/mostrarMenuFilas.cpp`.
- **Pilas** (Ramiro): 4 funciones en `logica/pila/` (`apilarJuegoVisitado`, `desapilarJuegoVisitado`,
  `mostrarHistorialVisitante`, `topeHistorial`) y el struct `NodoJuegoVisitado`.
- **`obtenerVisitantePorPulsera`** (`logica/nodo/`): búsqueda lineal de un visitante en la lista por pulsera.
- **`imprimirTabla`** (Ramón): `utiles/outputs/imprimirTabla.cpp/.h` + struct `Tabla`.
- En el menú principal se agregó la opción **"Gestionar Filas de Juegos (Colas)"**.

### Qué se agregó (sin commitear, working tree)
- **Novedades / apareo** (Ramón): `actualizarJuegosConNovedades`, `generarNovedadesDePrueba` y el
  struct `Novedad`.
- **Índice** (Ramón): `construirIndice`, `buscarPorIndice`, el struct `IndiceVisitante` y el soporte
  `guardarVisitantes` (necesario porque `visitantes.dat` no se escribía).
- **Verificador consolidado**: `logica/verificador/verificarAcceso.cpp/.h`.
- **Archivos de Nacho** (Entrega 1, recién ahora integrados): `consultarJuegoN`, `cambiarEstadoJuegoN`,
  `exportarReporteDia`, `listadoPorTipoConCorte`.
- **Recursión** (Nacho): `contarActivosRec`, `atenderFilaRec` (`logica/recursividad/`).
- Dos rutas nuevas en `constantes/rutasArchivos.h`: `novedades.dat` y `juegos_act.dat`.

### Qué se movió
- `verificarAcceso` estaba en `logica/cola/` (con una copia duplicada en `logica/comparador/`).
  Se movió a **`logica/verificador/`** y quedó una sola versión con la firma
  `verificarAcceso(const Juego&, const Visitante&)`.

### Qué se borró y por qué
- `logica/comparador/` completo: era una **copia duplicada** del verificador → símbolos duplicados al linkear.
- `logica/cola/verificarAcceso.cpp/.h`: tercera copia del verificador → también duplicada.
- `utiles/matematica/calcularPromedio.cpp/.h` (commit `da3a5e1`): función que quedó sin uso tras el refactor.

### Qué NO se tocó
- `docs/CSVs/` (solo lectura por regla del proyecto). El cambio que aparece en
  `docs/CSVs/Entrega-2.csv` lo hicieron compañeros (marcaron pila y recursión en `TRUE`).
- El `.md` de la materia (`ALGORITMOS_Y_ESTRUCTURA_DE_DATOS_COMPLETO.md`), `/.claude`, y el código
  ya commiteado de compañeros.

---

## 2. Funciones nuevas

La materia está en `.claude/ALGORITMOS_Y_ESTRUCTURA_DE_DATOS_COMPLETO.md`. Las secciones citadas
abajo son las clases de ese archivo (índice al principio del archivo).

### 2.1 Cola (Joaquín) — tema: *Clase 16 — Colas*

**`encolarVisitante(Cola &c, Visitante v)`** — `logica/cola/encolarVisitante.cpp`
- Recibe: una cola por referencia y un visitante por valor. Devuelve: nada (`void`).
- Pasos: 1) crea un `NodoVisitante` con `new`; 2) le guarda el visitante y pone `siguiente = nullptr`;
  3) si la cola está vacía, `frente` apunta al nuevo nodo; si no, el nodo que era `fin` apunta al nuevo;
  4) `fin` pasa a ser el nuevo nodo (se encola al final).
- Tema: *Clase 16 — Colas* (FIFO, inserción al final).

**`desencolarVisitante(Cola &c, Visitante &v)`** — `logica/cola/desencolarVisitante.cpp`
- Recibe: la cola por referencia y un visitante por referencia (para devolverlo). Devuelve: `bool` (true si salió uno).
- Pasos: 1) si `frente == nullptr` devuelve `false`; 2) guarda el nodo del frente en `aux` y copia su
  visitante a `v`; 3) `frente` avanza al siguiente; 4) si la cola quedó vacía, `fin = nullptr`;
  5) `delete aux`; devuelve `true`.
- Tema: *Clase 16 — Colas* (FIFO, remoción del frente).

**`atenderSiguienteVisitante(Cola &c)`** — `logica/cola/atenderSiguienteVisitante.cpp`
- Recibe: la cola. Devuelve: nada. Llama a `desencolarVisitante`; si devuelve `true` imprime
  "Atendiendo al visitante …", si no avisa que la fila está vacía.
- Tema: *Clase 16 — Colas*.

**`estaEnCola(const Cola &c, int pulsera)`** — `logica/cola/estaEnCola.cpp`
- Recibe: la cola (const) y un número de pulsera. Devuelve: `bool`.
- Pasos: recorre desde `frente` hasta `nullptr` comparando `pulsera`; devuelve `true` si lo encuentra.
- Tema: *Clase 16 — Colas* (recorrido sobre nodos).

**`liberarCola(Cola &c)`** — `logica/cola/liberarCola.cpp`
- Recibe: la cola. Devuelve: nada. Recorre todos los nodos con `delete` y deja `frente = fin = nullptr`.
- Tema: *Clase 16 — Colas* + *Clase 11 — Punteros* (liberación de memoria con `delete`).

**`mostrarFilaJuego(Cola c)`** — `logica/cola/mostrarFilaJuego.cpp`
- Recibe: la cola por valor (no la modifica). Devuelve: nada. Recorre desde `frente` imprimiendo
  posición + nombre + pulsera de cada visitante; avisa si está vacía.
- Tema: *Clase 16 — Colas*.

### 2.2 Pila (Ramiro) — tema: *Clase 15 — Pilas*

**`apilarJuegoVisitado(NodoJuegoVisitado *pila, int codigoJuego)`** — `logica/pila/apilarJuegoVisitado.cpp`
- Recibe: el tope de la pila y un código de juego. Devuelve: el nuevo tope (`NodoJuegoVisitado*`).
- Pasos: 1) `new` un nodo; 2) guarda el código; 3) su `siguiente` apunta al tope anterior; 4) devuelve el nuevo nodo.
- Tema: *Clase 15 — Pilas* (push, LIFO).

**`desapilarJuegoVisitado(NodoJuegoVisitado *pila)`** — `logica/pila/desapilarJuegoVisitado.cpp`
- Recibe: el tope. Devuelve: el nuevo tope.
- Pasos: 1) si es `nullptr` devuelve `nullptr`; 2) guarda el tope en `aux`; 3) el tope pasa al siguiente;
  4) `delete aux`; devuelve el nuevo tope.
- Tema: *Clase 15 — Pilas* (pop, LIFO).

**`mostrarHistorialVisitante(NodoJuegoVisitado *pila)`** — `logica/pila/mostrarHistorialVisitante.cpp`
- Recibe: el tope. Devuelve: nada. Recorre desde el tope (más reciente) hasta abajo imprimiendo cada código.
- Tema: *Clase 15 — Pilas* (recorrido desde el tope).

**`topeHistorial(NodoJuegoVisitado *pila)`** — `logica/pila/topeHistorial.cpp`
- Recibe: el tope. Devuelve: `int` (el código del tope) o `-1` si está vacía. No desapila.
- Tema: *Clase 15 — Pilas* (peek/tope).

### 2.3 Verificador (Nacho, consolidado por Ramón) — tema: registros + decisión

**`verificarAcceso(const Juego &juego, const Visitante &visitante)`** — `logica/verificador/verificarAcceso.cpp`
- Recibe: un juego y un visitante (por referencia constante). Devuelve: `bool`.
- Pasos: 1) si `!juego.operativo` → imprime "ACCESO DENEGADO … FUERA DE SERVICIO" y devuelve `false`;
  2) si `visitante.altura < juego.alturaMinima` → imprime "ACCESO DENEGADO" con las alturas y devuelve `false`;
  3) si pasa ambas → imprime "ACCESO PERMITIDO" y devuelve `true`.
- Tema: *Clase 2 — Tipos de datos* (registros `Juego` y `Visitante`) + condicionales. (Ítem 7 de la Entrega 1.)

### 2.4 Nodo / lista (helper) — tema: *Clase 13 — Listas*

**`obtenerVisitantePorPulsera(NodoVisitante *lista, int pulseraNum, Visitante &v)`** — `logica/nodo/obtenerVisitantePorPulsera.cpp`
- Recibe: la lista, una pulsera y un `Visitante` por referencia. Devuelve: `bool`.
- Pasos: recorre la lista; si encuentra la pulsera copia el visitante a `v` y devuelve `true`; si no, `false`.
- Tema: *Clase 13 — Listas Completa* (recorrido de lista enlazada).

### 2.5 Tablas (Ramón) — tema: *Clase 10 — Matrices* + *Clase 4 — Vectores*

**`imprimirTabla(Tabla datos)`** — `utiles/outputs/imprimirTabla.cpp` (ver sección 4)
- Recibe: un `Tabla` (matriz `int**` de contenido + arreglos de encabezados/filas). Devuelve: nada.
- Tema: *Clase 10 — Matrices* (arreglo bidimensional) + *Clase 4 — Vectores* (arreglos de `char*`).
- Helpers internos: `largoEntero(int)`, `imprimirIzquierdaChar`, `imprimirDerechaChar`, `imprimirDerechaInt`.

### 2.6 Archivos de Nacho (Entrega 1, integrados recién ahora)

**`consultarJuegoN(int n, Juego& juego)`** — `logica/archivo/consultarJuegoN.cpp` (ítem 21)
- Recibe: un número de registro `n` y un `Juego` por referencia. Devuelve: `bool`.
- Pasos: 1) abre `juegos.dat` en binario; 2) si no abrió o `n <= 0` devuelve `false`;
  3) `seekg((n-1)*sizeof(Juego))`; 4) `read` de un `Juego`; devuelve `true` si leyó, si no `false`.
- Tema: *Clase 8 — Binarios* (acceso directo con `seekg`).

**`cambiarEstadoJuegoN(int n, bool nuevoEstado)`** — `logica/archivo/cambiarEstadoJuegoN.cpp` (ítem 22)
- Recibe: posición `n` y el nuevo valor de `operativo`. Devuelve: `bool`.
- Pasos: 1) valida `n > 0`; 2) abre con `fstream` en `in | out`; 3) `seekg` al registro, lo lee;
  4) cambia `juego.operativo`; 5) `seekp` a la misma posición y reescribe. (No reescribe todo el archivo.)
- Tema: *Clase 8 — Binarios* (`seekg`/`seekp` sobre un mismo archivo).

**`exportarReporteDia(DatosParque &datos)`** — `logica/archivo/exportarReporteDia.cpp` (ítem 23)
- Recibe: `DatosParque` por referencia. Devuelve: nada.
- Pasos: 1) abre `reporte_dia.txt` (texto); 2) calcula `totalPorJuego` y `totalPorFranja`;
  3) escribe "VISITAS POR JUEGO" (nombre + total), luego "VISITAS POR FRANJA" (franja + total),
  4) escribe el "TOTAL DE VISITAS DEL DIA" con `totalOcupacion`; cierra.
- Tema: *Clase 7 — Archivos* (escritura de archivo de texto).

**`listadoPorTipoConCorte()`** — `logica/archivo/listadoPorTipoConCorte.cpp` (ítem 24)
- Recibe: nada. Devuelve: nada. Lee `juegos.dat` y hace **corte de control** por `tipo`.
- Pasos: 1) `leerArchivoJuegos`; 2) recorre; al cambiar de `tipo` imprime el subtotal del tipo anterior,
  lo suma al total general, reinicia subtotal y cambia el tipo actual; 3) suma las franjas de cada juego
  al subtotal; 4) al final imprime subtotal y TOTAL GENERAL.
- Tema: *Clase 7 — Archivos* (corte de control).

### 2.7 Novedades e índice (Ramón — los dos puntos de la Entrega 2)

**`actualizarJuegosConNovedades()`** — `logica/archivo/actualizarJuegosConNovedades.cpp` (ítem 8)
- Recibe/Devuelve: nada.
- Pasos: 1) abre maestro `juegos.dat` y `novedades.dat` (ambos ordenados por `codigo`); 2) abre un
  temporal `juegos_act.dat` para no leer/escribir el mismo archivo; 3) **apareo**: lee un registro de
  cada archivo y avanza el de clave menor: si el maestro es menor lo copia tal cual; si la novedad es
  menor llama a `sinMaestro` (solo vale alta `'A'`); si son iguales llama a `conMaestro` (baja `'B'`
  elimina, modificación `'M'` graba los datos nuevos, `'A'` sobre un código existente es error y conserva
  el viejo); 4) copia los restos del maestro y procesa las novedades que sobren; 5) copia `juegos_act.dat`
  encima de `juegos.dat` (sin `remove`/`rename`).
- Tema: *Clase 12 — Apareo* + *Clase 14 — Novedades/Índices*.

**`construirIndice(IndiceVisitante*& indice, int &cantidad)`** — `logica/archivo/construirIndice.cpp` (ítem 9)
- Recibe: un puntero por referencia y un entero por referencia (para devolver el índice y su tamaño).
- Pasos: 1) abre `visitantes.dat` con `ios::ate` (cursor al final); 2) `cantidad = tellg()/sizeof(Visitante)`
  para saber cuántos registros hay; 3) `seekg(0)` y reserva `new IndiceVisitante[cantidad]`;
  4) lee cada visitante y guarda `{pulsera, posicion=i}`; 5) ordena el índice por pulsera con
  **burbuja + bandera de corte**.
- Tema: *Clase 14 — Novedades/Índices* + *Clase 6 — Ordenamiento* + *Clase 11 — Punteros*.

**`buscarPorIndice(const IndiceVisitante indice[], int cantidad, int pulsera, Visitante &visitante)`** — `logica/archivo/buscarPorIndice.cpp` (ítem 10)
- Recibe: el índice ordenado, su tamaño, la pulsera y un `Visitante` por referencia. Devuelve: `bool`.
- Pasos: 1) **búsqueda binaria** sobre el índice (por pulsera); 2) si no está devuelve `false`;
  3) abre `visitantes.dat` y hace `seekg(posicion * sizeof(Visitante))` (salto directo);
  4) lee el registro y devuelve `true`.
- Tema: *Clase 5 — Búsqueda* (binaria) + *Clase 14 — Novedades/Índices*.

**`guardarVisitantes(NodoVisitante *lista)`** — `logica/archivo/guardarVisitantes.cpp` (soporte)
- Recibe: la lista enlazada de visitantes. Devuelve: nada. Recorre la lista y escribe cada visitante en
  `visitantes.dat` (binario), contando cuántos guardó. Es el paso previo necesario para poder indexar.
- Tema: *Clase 8 — Binarios* + *Clase 13 — Listas*.

**`generarNovedadesDePrueba()`** — `logica/archivo/generarNovedadesDePrueba.cpp` (soporte)
- Recibe/Devuelve: nada. Escribe `novedades.dat` con 4 novedades ordenadas por código: baja del código 2,
  modificación del 3, alta del 11 y una modificación inválida (código 99).
- Tema: *Clase 8 — Binarios*.

### 2.8 Recursión (Nacho) — sin sección en el material

**`contarActivosRec(NodoVisitante* lista)`** — `logica/recursividad/recursionActivosYFila.cpp` (ítem 11)
- Recibe: la lista. Devuelve: `int`. Caso base: `nullptr` → 0; caso recursivo: `1 + contarActivosRec(lista->siguiente)`.
- Tema: recursión (ver nota en "Limitaciones").

**`atenderFilaRec(void* cola)`** — `logica/recursividad/recursionActivosYFila.cpp` (ítem 12)
- Recibe: un `void*` (genérico). Devuelve: nada. **Solo imprime un mensaje**; no atiende la fila de forma
  recursiva (está incompleto). Ver "Limitaciones".
- Tema: recursión (ver nota en "Limitaciones").

---

## 3. Cambios en el menú

### Menú Principal

**Antes** (Entrega 1):
```
1. Gestionar Visitantes          -> mostrarMenuVisitantes()
2. Gestionar Juegos              -> mostrarMenuJuegos()
3. Gestionar Ocupacion de juegos -> mostrarMenuOcupacion()
4. Generar Datos De Prueba       -> generarDatosPrueba()
5. Salir del programa
```

**Después**:
```
1. Gestionar Visitantes          -> mostrarMenuVisitantes()
2. Gestionar Juegos              -> mostrarMenuJuegos()
3. Gestionar Ocupacion de juegos -> mostrarMenuOcupacion()
4. Gestionar Filas de Juegos (Colas) -> mostrarMenuFilas()   <-- NUEVO
5. Generar Datos De Prueba       -> generarDatosPrueba()
6. Salir del programa
```

### Menú Juegos (sin cambio de opciones; se agregó "0 para imprimir menú")
```
1. Mostrar juegos                -> mostrarMenuListaJuegos()
2. Ordenar Juegos                -> mostrarMenuOrdenarJuegos()
3. Buscar Juego                  -> mostrarMenuBuscarJuegos()
4. Administrar archivos de juegos-> mostrarMenuArchivosJuegos()
5. Volver
```

### Submenú "Administrar archivos de juegos"

**Antes** (Entrega 1):
```
1. Cargar juegos desde archivos  -> leerArchivoJuegos()
2. Guardar juegos a archivos     -> crearArchivoJuegos()
3. Volver
```

**Después**:
```
1. Cargar juegos desde archivos          -> leerArchivoJuegos()
2. Guardar juegos a archivos             -> crearArchivoJuegos()
3. Consultar juego N                     -> consultarJuegoN()        <-- NUEVO
4. Cambiar estado del juego N            -> cambiarEstadoJuegoN()    <-- NUEVO
5. Listado por tipo con corte de control -> listadoPorTipoConCorte() <-- NUEVO
6. Actualizar juegos con novedades       -> actualizarJuegosConNovedades() <-- NUEVO
7. Volver
```

### Menú Visitantes

**Antes** (Entrega 1):
```
1. Mostrar Visitantes
2. Registrar Visitante
3. Buscar Visitante
4. Seleccionar Juego
5. Eliminar Visitante
6. Liberar Visitantes
7. Volver
```

**Después**:
```
1. Mostrar Visitantes
2. Registrar Visitante
3. Buscar Visitante
4. Seleccionar Juego
5. Eliminar Visitante
6. Liberar Visitantes
7. Guardar visitantes a archivo             -> guardarVisitantes()   <-- NUEVO
8. Construir y mostrar indice de visitantes -> construirIndice()     <-- NUEVO
9. Buscar visitante por indice              -> buscarPorIndice()     <-- NUEVO
10. Volver
```

### Menú Ocupación (opción 5 estaba vacía; ahora funciona)
```
1. Mostrar ocupacion por franja    -> imprimirMatriz()
2. Mostrar pico maximo             -> devolverMayorOcupacion()
3. Mostrar juego mas usado         -> devolverMasUsado()
4. Mostrar total de visitas        -> totalOcupacion() + totalPorJuego() + totalPorFranja()
5. Exportar Reporte del dia        -> exportarReporteDia()   <-- ANTES vacío (/**/), ahora conectado
6. Volver
```

### Menú Filas (nuevo en la Entrega 2)
```
1. Encolar visitante en un juego    -> obtenerVisitantePorPulsera() + estaEnCola() + verificarAcceso() + encolarVisitante()
2. Ver fila de un juego             -> mostrarFilaJuego()
3. Atender siguiente visitante      -> atenderSiguienteVisitante()
4. Ver estado de todas las filas    -> (recorrido inline de filasJuegos[])
5. Volver
```

### Qué NO está conectado al menú (verificado por grep)
- Las 4 funciones de **pila** (`apilarJuegoVisitado`, `desapilarJuegoVisitado`, `mostrarHistorialVisitante`,
  `topeHistorial`) están definidas pero **no se llaman desde ningún menú**.
- Las 2 funciones de **recursión** (`contarActivosRec`, `atenderFilaRec`) tampoco se llaman desde ningún menú.

---

## 4. Cómo funcionan las tablas (`imprimirTabla.cpp`)

`imprimirTabla` recibe un `Tabla` (definido en `imprimirTabla.h`):
```cpp
struct Tabla {
    int largoNombre = LARGO_NOMBRE;   // ancho fijo de la columna de nombres de fila
    int columnas;
    int filas;
    char** nombresColumnas;           // encabezados de columnas
    char** nombresFilas;              // nombre de cada fila
    int**  contenido;                 // matriz de enteros (filas x columnas)
};
```

### Cómo se calculan los anchos
- Se busca un único `anchoCelda` para todas las columnas de datos:
  1. Se recorre `nombresColumnas[j]` y se toma el largo del encabezado más largo (`strlen`).
  2. Se recorre toda la matriz `contenido[i][j]` y se toma el mayor `largoEntero()` de cada celda.
  3. `anchoCelda = max(encabezado más largo, celda más ancha)`.
- La columna de nombres de fila usa un ancho fijo `largoNombre` (por defecto `LARGO_NOMBRE = 32`).
- `largoEntero(n)` cuenta los dígitos manualmente (divide por 10 en un `while`), sumando 1 extra si es negativo.

### Cómo se alinean las columnas
- Texto a la izquierda (`imprimirIzquierdaChar`): escribe el texto y rellena con espacios a la derecha.
- Texto a la derecha (`imprimirDerechaChar`): rellena con espacios a la izquierda y escribe el texto.
- Entero a la derecha (`imprimirDerechaInt`): igual que el anterior pero usando `largoEntero`.

### Cómo se arma cada fila
- **Encabezado**: se imprime un espacio rellenado a `largoNombre` (columna de nombres vacía), y por cada
  columna se imprime `" | "` seguido del encabezado alineado a la derecha.
- **Separador**: una línea de guiones de largo `largoNombre + columnas * (anchoCelda + 3)`.
- **Filas de datos**: se imprime `nombresFilas[i]` alineado a la izquierda a `largoNombre`, y por cada
  columna `" | "` + `contenido[i][j]` alineado a la derecha a `anchoCelda`.

### Por qué se imprime en forma de matriz
- El contenido es una matriz `int**` (`contenido[filas][columnas]`), que es la representación natural de
  una tabla bidimensional. El código recorre `i` (filas) y `j` (columnas) con dos bucles anidados, igual
  que se recorre una matriz. Los encabezados y los nombres de fila se guardan aparte en arreglos de `char*`
  para no mezclarlos con los datos numéricos.

> Nota de auditoría: este archivo usa `strlen` de `<cstring>` (ver "Limitaciones").

---

## 5. Guion para explicar el TP en clase (5 minutos)

1. **Qué es** (30 s): un sistema de consola que administra un parque de diversiones: juegos, visitantes,
   filas, ocupación e historial. Se compila con `g++ -std=c++17 -Wall -Wextra` y solo usa `<iostream>`/`<fstream>`.

2. **Datos** (30 s): dos archivos binarios (`juegos.dat`, `visitantes.dat`) con registros de tamaño fijo
   (`Juego`, `Visitante`). En memoria: una lista enlazada de visitantes activos, un arreglo de juegos y una
   matriz de ocupación `juego × franja`.

3. **Lista enlazada** (40 s): los visitantes se guardan en nodos (`agregarVisitanteLista` al inicio,
   `buscar`, `eliminar`, `liberar`). Sirve para que insertar y borrar no mueva todos los demás.

4. **Archivos y acceso directo** (40 s): `consultarJuegoN` salta al registro N con `seekg(N*sizeof)` sin
   recorrer todo. `cambiarEstadoJuegoN` lee, cambia el campo `operativo` y reescribe en el mismo lugar con `seekp`.

5. **Cola** (40 s): cada juego tiene una `Cola` con `frente` y `fin`. `encolarVisitante` agrega al final y
   `desencolarVisitante` saca del frente (FIFO). El menú "Filas" encola, muestra y atiende.

6. **Novedades / apareo** (60 s): `novedades.dat` trae altas/bajas/modificaciones ordenadas por código.
   `actualizarJuegosConNovedades` hace un apareo: avanza el de clave menor y aplica A/B/M; escribe a un
   temporal y lo copia encima del maestro.

7. **Índice** (60 s): `construirIndice` arma un arreglo `{pulsera, posición}` ordenado por pulsera.
   `buscarPorIndice` hace búsqueda binaria (O(log n)) y salta directo al registro con `seekg`.

8. **Cierre** (20 s): la matriz de ocupación se reconstruye leyendo las franjas de cada juego, y el reporte
   del día se exporta a `reporte_dia.txt`.

---

## 6. Diez preguntas que el docente podría hacer (y su respuesta)

1. **¿Por qué el apareo y no reescribir el maestro buscando cada novedad?**
   Porque maestro y novedades están ordenados por `codigo`; el apareo recorre ambos una sola vez (O(n+m))
   en lugar de buscar cada novedad en el maestro (O(n·m)).

2. **¿Qué pasa si una novedad es una baja de un código que no existe en el maestro?**
   `sinMaestro` solo graba si la operación es `'A'`; para `'B'` (o `'M'`) imprime `[ERROR]` y no graba nada.

3. **¿Cómo se construye el índice y cómo acelera la búsqueda?**
   Se leen todos los visitantes una vez guardando `{pulsera, posición}` y se ordena por pulsera. Luego la
   búsqueda es binaria (O(log n)) y el salto al registro es directo con `seekg`, en vez de recorrer el archivo.

4. **¿Cómo sabés cuántos registros tiene `visitantes.dat`?**
   Abro con `ios::ate` (cursor al final) y hago `tellg() / sizeof(Visitante)`.

5. **¿Por qué ordenás el índice?**
   Porque la búsqueda binaria exige un arreglo ordenado; se ordena por pulsera con burbuja + bandera.

6. **¿Qué es un corte de control (en `listadoPorTipoConCorte`)?**
   Agrupar registros por una clave (`tipo`); cuando la clave cambia se cierra el grupo anterior
   (imprimo subtotal) y se abre uno nuevo.

7. **¿Por qué la cola usa dos punteros (`frente` y `fin`)?**
   Para encolar al final en O(1) (sin recorrer) y desencolar del frente en O(1).

8. **¿Por qué `seekg(pos * sizeof(Juego))` es acceso directo?**
   Porque todos los registros miden lo mismo (`sizeof` fijo), así la posición del registro N se calcula
   aritméticamente y no hay que leer los anteriores.

9. **¿Qué valida `verificarAcceso` antes de dejar pasar a un visitante?**
   Que el juego esté `operativo` y que `visitante.altura >= juego.alturaMinima`; si falla cualquiera devuelve `false`.

10. **¿Por qué el apareo escribe a un archivo temporal y después lo copia?**
    Porque no conviene leer y escribir el mismo archivo al mismo tiempo; se genera `juegos_act.dat` y se
    copia encima de `juegos.dat` (evitando `remove`/`rename`, que no están permitidos).

---

## 7. Limitaciones conocidas

1. **`actualizarJuegosConNovedades` actualiza el archivo, no la copia en memoria.**
   Modifica `juegos.dat`, pero el arreglo `datos.juegos` en memoria queda desactualizado hasta volver a
   llamar `leerArchivoJuegos` / regenerar. Los menús que leen de archivo ven el cambio; los que usan
   `datos.juegos` en memoria, no.

2. **La pila (historial) no está integrada.** Las 4 funciones de pila existen y compilan, pero ninguna
   opción de menú las llama; no hay un historial persistente por visitante en `DatosParque`.

3. **La recursión no está integrada y `atenderFilaRec` es un stub.** `contarActivosRec` funciona
   recursivamente, pero `atenderFilaRec(void* cola)` solo imprime un mensaje y no atiende la fila; además
   ninguna de las dos se llama desde el menú.

4. **`structs/nodoJuegoVisitado.h` no está commiteado.** Los `.h` de pila (que sí están commiteados) hacen
   `#include "structs/nodoJuegoVisitado.h"`, pero ese archivo está sin commitear. Un `git clone` limpio no
   compilaría la pila hasta commitear ese header.

5. **Librerías/funciones prohibidas en código commiteado** (no son de esta entrega, pero hay que avisar):
   - `utiles/outputs/imprimirTabla.cpp` → `<cstring>`, `strlen`.
   - `logica/texto/buscarJuegoPorNombre.cpp` → `<cstring>` (`strstr`) y `<cctype>` (`tolower`).
   - `logica/vector/ordenarPorNombre.cpp` → `<cstring>` (`strcmp`).

6. **Menú principal con menú residual.** En `mostrarMenuPrincipal.cpp` quedó un `imprimirMenu()` estático
   con las 5 opciones viejas (sin "Filas") que ya no se usa en el bucle real (que muestra 6 opciones). No
   rompe nada, pero es código muerto.

7. **`exportarReporteDia` depende de la matriz ya reconstruida.** Usa `datos.datosMatriz`, que debe estar
   al día (`reconstruirMatriz` se llama al entrar al menú de ocupación); si no, los totales podrían quedar viejos.

---

## No pude verificar

- **Que el flujo completo funcione de punta a punta interactivamente.** La compilación completa dio
  `EXIT=0` (66 archivos) y las funciones nuevas se probaron aisladas con un harness, pero no se ejecutó
  el menú completo de forma interactiva en esta sesión.
- **El estado real de `docs/CSVs/Entrega-2.csv`.** El CSV marca pila (5-7) y recursión (11-12) en `TRUE`,
  pero en el código la pila y la recursión no están conectadas al menú; no puedo confirmar si eso es un
  estado pretendido o pendiente.
- **La sección de recursión del material.** El índice del `.md` de la materia termina en *Clase 16 — Colas*
  (la última diapositiva dice "La próxima: Recursividad"), así que no hay sección de recursión para citar
  en los ítems 11-12.
