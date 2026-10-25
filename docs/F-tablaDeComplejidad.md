## Tabla de complejidad

### 1. Constantes

| Símbolo | Significa |
|---|---|
| **n** | cantidad de juegos en un arreglo o en `juegos.dat` |
| **J** | cantidad de juegos cargados en la matriz de ocupación (`datosMatriz.juegos`) |
| **F** | cantidad de franjas horarias (`FRANJAS_HORARIAS`, constante = 5) |
| **V** | cantidad de visitantes activos en la lista enlazada |
| **H** | cantidad de juegos en el historial (pila) de un visitante |
| **T** | total de nodos de historial de **todos** los visitantes (T ≤ V·H) |
| **Q** | cantidad de visitantes en la fila (cola) de un juego |
| **M** | cantidad de novedades en `novedades.dat` |
| **R** | cantidad de registros en `visitantes.dat` |
| **L** | largo máximo de un texto (`LARGO_NOMBRE`, constante = 32) |

### 2. Funciones del TP
| Estructura | Operación típica | Complejidad |
|---|---|---|
| Arreglo ordenado | búsqueda binaria | O(log n) |
| Arreglo | búsqueda lineal / recorrido | O(n) |
| Arreglo | ordenamiento burbuja | O(n²)|
| Matriz J×F | totales, máximo, impresión | O(J·F) |
| Lista enlazada | insertar al inicio | O(1) |
| Lista enlazada | buscar / eliminar / mostrar | O(V) |
| Pila | apilar, desapilar, tope | O(1) |
| Pila | mostrar o liberar | O(H) |
| Cola | encolar, desencolar | O(1) |
| Cola | buscar, mostrar o liberar | O(Q) |
| Recursión (lista y fila) | tiempo / espacio | O(V) o O(Q) |
| Archivo, acceso directo | `seekg` y `seekp` | O(1) |
| Archivo, apareo | maestro y novedades | O(n + M) |
| Índice sobre `visitantes.dat` | construir / buscar | O(R²) / O(log R) |