# construirIndice() y buscarPorIndice()

**Puntos 9 y 10 de la Entrega 2 — Índice en memoria sobre `visitantes.dat`.**

## Qué hacen

- **`construirIndice()`** lee `datos/visitantes.dat` y arma en memoria un
  arreglo de entradas `{ pulsera, posicion }`, ordenado por `pulsera`.
- **`buscarPorIndice()`** busca una `pulsera` en ese índice con **búsqueda
  binaria** y, con la `posicion`, salta directo al registro usando `seekg`.

## Por qué un índice

Sin índice, buscar un visitante obliga a recorrer el archivo completo
(O(n)). Con el índice ordenado, la búsqueda es **O(log n)** y la lectura del
registro es **directa** (`seekg(posicion * sizeof(Visitante))`), sin recorrer
nada.

## Paso a paso — construirIndice

1. Abrir `visitantes.dat` con `ios::ate` para quedar parado al final.
2. `cantidad = tellg() / sizeof(Visitante)` → cuántos registros hay.
3. `seekg(0)` y reservar memoria con `new IndiceVisitante[cantidad]`.
4. Leer cada `Visitante` y guardar `pulsera = v.pulsera` y `posicion = i`.
5. Ordenar el índice por `pulsera` con **burbuja + bandera de corte**.

## Paso a paso — buscarPorIndice

1. **Búsqueda binaria** sobre el índice ordenado por `pulsera`.
2. Si no está, devolver `false`.
3. Si está, abrir el archivo y hacer
   `seekg(indice[pos].posicion * sizeof(Visitante))`.
4. Leer el `Visitante` y devolverlo.

## Dependencia

`visitantes.dat` no existía porque nadie lo escribía. Se agregó
**`guardarVisitantes()`**, que recorre la lista enlazada de visitantes y graba
cada uno en el archivo binario. `generarDatosPrueba()` ahora lo llama, y en el
menú hay una opción para guardar en cualquier momento.

## Archivos que toca

- `logica/archivo/construirIndice.cpp/.h`
- `logica/archivo/buscarPorIndice.cpp/.h`
- `logica/archivo/guardarVisitantes.cpp/.h`
- `structs/indiceVisitante.h` (struct `IndiceVisitante { int pulsera; int posicion; }`)

## Cómo se probó

Con 10 visitantes guardados: el índice queda con 10 entradas ordenadas por
pulsera, y `buscarPorIndice(1005)` devuelve "Sebastian Longo", mientras que una
pulsera inexistente devuelve `false`.
