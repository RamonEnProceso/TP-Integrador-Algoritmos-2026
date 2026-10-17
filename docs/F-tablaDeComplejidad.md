## Complejidad
| Operación | Complejidad | Justificación |
|---|---|---|
| Búsqueda lineal (arreglo) | O(n) | Recorre el arreglo hasta encontrar el elemento (o agotarlo). |
| Búsqueda binaria (arreglo) | O(log n) | En cada paso reduce el rango de búsqueda a la mitad (requiere arreglo ordenado). |
| Ordenamiento (burbuja) | O(n²) | Dos bucles anidados; con bandera de corte el mejor caso es O(n). |
| Búsqueda en la lista | O(n) | Recorre los nodos hasta encontrar la pulsera. |
| Inserción en la lista | O(1) | Se inserta al inicio de la lista (cabeza). |
| Apilar / Desapilar | O(1) | Operan sobre el tope (LIFO). |
| Encolar / Desencolar | O(1) | Encolar al final (puntero a `final`) y desencolar del frente. |
| Apareo | O(n + m) | Recorre los dos archivos de entrada una sola vez. |
| Acceso por índice | O(log n) | Búsqueda binaria sobre el índice ordenado; luego acceso directo O(1) con `seekg`. |