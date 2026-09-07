## ENTREGA 1

Los números entre paréntesis son los ítems del Sheet.

### Estado
- [ ] [Fase A — Lógica base](#fase-a--lógica-base-ítems-1-6)
- [ ] [Fase B — Registros y arreglos](#fase-b--registros-y-arreglos-ítems-7-16)
- [ ] [Fase C — Archivos](#fase-c--archivos-ítems-17-22)
- [ ] [Fase D — Lista enlazada](#fase-d--lista-enlazada-ítems-23-28)


### Fase A — Lógica base (ítems 1-6)

Struct, menú y datos de prueba.
El objetivo de esta fase es tener **un programa que compile**, aunque no haga nada todavía.

- `registrarVisitante()`, `mostrarVisitante()`, `mostrarJuegosDisponibles()`, `seleccionarJuego()`, `verificarAcceso()` (altura y estado del juego), `generarDatosDePrueba()`.
- `generarDatosDePrueba()` necesita 8-10 juegos y visitantes inventados a mano, con variedad real: juegos operativos y fuera de servicio, distintos tipos, capacidades y alturas mínimas, visitantes aptos y no aptos. Datos al azar sin pensar no sirven para encontrar bugs.

### Fase B — Registros y arreglos (ítems 7-16)

Acá vive también la matriz: en el Sheet están agrupadas porque ambas dependen de tener el arreglo de juegos cargado y funcionando.

- `cargarJuegos()`, `mostrarJuegos()`, `buscarJuegoPorCodigoBinaria()`, `buscarJuegoPorNombre()` (parcial, sin distinguir mayúsculas), `ordenarPorCodigo()`, `ordenarPorNombre()` (dos criterios distintos, con un método propio: burbuja, selección o inserción), `contarJuegosOperativos()`, `obtenerJuegoMasUsado()`.
- `totalesMatrizOcupacion()`, `maximoMatrizOcupacion()` sobre `ocupacion[juego][franjaHoraria]`: total por fila, por columna, y el máximo con su posición.
- La consulta por código del menú tiene que usar la búsqueda **binaria**, no la lineal. Eso lo revisan en la corrección.

### Fase C — Archivos (ítems 17-22)

- `guardarJuegos()` / `leerJuegos()`: binario, se carga al iniciar y se graba al salir.
- `consultarJuegoN()` / `cambiarEstadoJuegoN()` con `seekg`/`seekp`: acceso al registro N sin leer el archivo completo.
- `exportarReporteDia()` (.txt): reporte legible desde un editor.
- `listadoPorTipoConCorte()`: agrupado por tipo de juego, con subtotal de accesos y total general, leyendo el archivo ordenado por esa clave.
- No se olviden de `visitantes.dat`: también tiene que persistir entre ejecuciones.

### Fase D — Lista enlazada (ítems 23-28)

- `crearNodoVisitante()`, `agregarVisitanteActivo()`, `buscarVisitanteActivo()`, `eliminarVisitanteActivo()`, `mostrarVisitantesActivos()`, `liberarListaVisitantes()`.
- Biblioteca propia, separada del programa principal (`.h` con el struct `Nodo` y las declaraciones, `.cpp` con la implementación).
- No alcanza con que la lista esté escrita: tiene que usarse en el flujo real. Acá modela a los visitantes que están dentro del parque en este momento: entran, quedan activos, salen.