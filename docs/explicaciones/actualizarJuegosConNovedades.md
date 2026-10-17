# actualizarJuegosConNovedades()

**Punto 8 de la Entrega 2 — Apareo maestro/novedades (A/B/M).**

## Qué hace

Actualiza el archivo maestro `datos/juegos.dat` aplicando las novedades de
`datos/novedades.dat`. Cada novedad lleva un `Juego` completo más una
operación:

| Op | Significado |
|----|-------------|
| `A` | **Alta**: agrega un juego nuevo. |
| `B` | **Baja**: elimina un juego existente. |
| `M` | **Modificación**: reemplaza el registro por la versión nueva. |

## Por qué funciona (idea clave)

Los dos archivos están **ordenados por `codigo`**. Eso permite recorrerlos
una sola vez, en paralelo, avanzando por el que tenga la clave menor. Es el
mismo razonamiento que el merge de dos listas ordenadas: complejidad
**O(n + m)** en lugar de buscar cada novedad en el maestro (que sería O(n·m)).

## Paso a paso

1. **Abrir** el maestro, el archivo de novedades y un archivo nuevo
   (`juegos_act.dat`) donde se escribe el resultado. No se lee y escribe el
   mismo archivo a la vez.
2. **Lectura adelantada**: se lee un registro de cada archivo y se guardan
   las banderas `hayMaestro` / `hayNovedad`.
3. **Apareo** (mientras haya registros en ambos):
   - `m.codigo < n.codigo` → el maestro no tiene novedad, se **copia tal cual**.
   - `n.codigo < m.codigo` → la novedad es de un código que **no está** en el
     maestro: se llama a `sinMaestro`.
   - Iguales → se llama a `conMaestro`.
4. **`sinMaestro`**: si la operación es `A` se graba el registro nuevo; si es
   `B` o `M` es un **error** (no existe el código) y no se graba nada.
5. **`conMaestro`**: `B` no graba nada (desaparece el registro), `M` graba la
   versión nueva, `A` es error (el código ya existe) y conserva el viejo.
6. **Restos**: lo que sobra del maestro se copia; las novedades que sobran
   pasan por `sinMaestro`.
7. **Reemplazo**: se copia `juegos_act.dat` encima de `juegos.dat` (así se
   evita `remove`/`rename`, que no están permitidos).

## Archivos que toca

- `logica/archivo/actualizarJuegosConNovedades.cpp/.h`
- `logica/archivo/generarNovedadesDePrueba.cpp/.h` (genera un caso de cada op)
- `structs/novedad.h` (struct `Novedad { Juego datos; char op; }`)
- `constantes/rutasArchivos.h` (rutas `novedades.dat` y `juegos_act.dat`)

## Cómo se probó

Con datos de prueba se aplican 4 novedades y se verifica:
- **Baja** del código 2 → desaparece.
- **Modificación** del código 3 → cambia capacidad y queda operativo.
- **Alta** del código 11 → se agrega.
- **Error** del código 99 → no existe, se avisa.
