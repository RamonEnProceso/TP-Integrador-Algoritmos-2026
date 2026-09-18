# Decisiones
> Elecciones de diseño, organización e ideas.

---

## Arquitectura
Se optó por organizar las funciones del programa a partir de su propósito.
Existen 5 carpetas:
### `\utiles`
> **Funciones reutilizables a lo largo de otros archivos.**
> Código que se separó para repetir sin tener que escribirlo siempre.
- `\inputs` y `outputs`
    > Código reutilizable para **imprimir y leer** en la consola.
- `\matematica`
    > Código reutilizable para realizar **cálculos**.

### `\logica`
> **Funciones vinculadas al manejo de datos.**
> Crea, lee, modifica y elimina datos del programa.


### `\menu`
> **Funciones vinculadas al menú de la aplicación.**
> Conecta el input del usuario con los datos a mostrar/modificar.

### `\structs`
> **Resgistros.**
> Registros utilizados por otras funciones.

### `\constantes`
> **Constantes.**
> Variables fijas que leen otras funciones.

### `\datos`
> **Archivos generados por el programa**
> Datos guardados por el programa en `.txt` y `.dat`.

---

## Matriz de ocupación
> `ocupacion[juego][franjaHoraria]`. Es la matriz obligatoria de la consigna.

- Se representa con el registro `MatrizJuegoXHoras`, que guarda el arreglo **fijo**
  `int matriz[MAX_JUEGOS][FRANJAS_HORARIAS]` junto con sus dimensiones usadas (`juegos` y `franjas`).
- `MAX_JUEGOS` es la **capacidad** del arreglo (50); `juegos` es **cuántos juegos hay cargados** (10). No son lo mismo: la capacidad sirve para leer el archivo y dimensionar; la cantidad, para recorrer, ordenar, buscar y grabar.
- No se usó `int**`: un arreglo bidimensional **no** es un puntero a puntero. `int m[50][5]` es memoria contigua de 250 enteros y `m` decae a `int (*)[5]`, mientras que un `int**` es un arreglo de punteros a filas reservadas aparte con `new`. Son layouts distintos e incompatibles.
- Al ser un arreglo fijo dentro del registro no hace falta `new`/`delete`: las celdas se inicializan y se cargan en `generarDatosPrueba()`.
- La ocupación **no se guarda en archivo**: la consigna sólo pide persistir `juegos.dat` y `visitantes.dat`. Se regenera junto con los datos de prueba.

## Nombres del Sheet vs. código
> La consigna permite cambiar nombres mientras se conserven las responsabilidades.
> Esta tabla es la equivalencia para la corrección.

| Función del Sheet | Nombre en el código |
|---|---|
| `cargarJuegos()` | `leerArchivoJuegos()` |
| `leerJuegos()` | `leerArchivoJuegos()` |
| `guardarJuegos()` | `crearArchivoJuegos()` |
| `mostrarJuegos()` | `mostrarListaJuegos()` |
| `mostrarJuegosDisponibles()` | `mostrarListaJuegosDisponibles()` |
| `totalesMatrizOcupacion()` | `totalPorJuego()` + `totalPorFranja()` (+ `totalOcupacion()`) |
| `maximoMatrizOcupacion()` | `devolverMayorOcupacion()` (devuelve valor **y** posición) |
| `obtenerJuegoMasUsado()` | `devolverMasUsado()` |
| `registrarVisitante()` | `leerInputVisitante()` |
| `mostrarVisitante()` | `imprimirVisitante()` |
| `buscarJuegoPorCodigoBinaria()` / `buscarJuegoPorNombre()` | mismos nombres |
| `ordenarPorCodigo()` / `ordenarPorNombre()` | mismos nombres (burbuja con bandera de corte) |

## Estado del parque
> Los datos viajan por parámetro: sin variables globales.

El registro `DatosParque` agrupa el estado completo del sistema y se pasa **por referencia** a
los menús y a toda función que lo modifique:
- la lista enlazada de visitantes activos;
- el arreglo de juegos y **cuántos** hay cargados (`cantJuegos`);
- la matriz de ocupación `ocupacion[juego][franja]`.
