## ENTREGA FINAL
> 31/10/2026

### Qué tiene que estar
- [x] Entrega 1 completa y corregida.
- [x] Entrega 2 completa y corregida.
- [x] Flujo completo: registrar visitante → fila → atender → historial → ocupación → reporte.
- [x] Memoria liberada (`delete` de todos los `new`).
- [x] Archivos cerrados.
- [x] Compila limpio con `g++ -std=c++17 -Wall -Wextra`.
- [x] `README` actualizado (qué hace, compilar, ejecutar, módulos, integrantes).
- [ ] Demo grupal.

### Tabla de complejidad
Ver [F-tablaDeComplejidad.md](F-tablaDeComplejidad.md). Debe cubrir: búsqueda lineal y
binaria, ordenamiento elegido, búsqueda e inserción en lista, apilar/desapilar,
encolar/desencolar, apareo (o novedades) y acceso por índice.

### Preguntas de diseño
Ver [F-preguntaDeDiseño.md](F-preguntaDeDiseño.md). Justificar por qué cada estructura
representa su funcionalidad (arreglo, matriz, lista, cola, pila, archivo binario, índice).

### Demo
Recorrer el flujo completo en vivo: generar datos → mostrar visitantes/juegos →
seleccionar juego (verificando acceso) → entrar a la fila → atender → historial →
ocupación → cambiar estado de un juego → reporte del día → salir (liberando memoria).