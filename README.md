# 🎢 TP Integrador — Parque de Diversiones

>UTN FRBA · Algoritmos y Estructuras de Datos · Cátedra Ing. Ariel García

## ¿Qué Hace?

Es un programa que simula la administración de un parque de diversiones: juegos, visitantes, filas, ocupación, historial. Permite ver y registrar datos de los visitantes y también la ocupación de los juegos.

## Cómo compilar y ejecutar

Los siguientes pasos son para compilar el `main.cpp` desde la raíz del proyecto.
Para hacerlo, se tiene que tener instalado el compilador `g++`.
Se debe insertar los siguientes comandos en `Powershell` desde la raíz:

```powershell
cd .\TP_Parque\
$archivos = (Get-ChildItem -Recurse -Filter *.cpp).FullName
g++ -std=c++17 -Wall -Wextra -I . $archivos -o parque
.\parque.exe
```
- `cd .\TP_Parque\` es para ingresar a la carpeta donde se encuentran los distintos archivos `.cpp` y `.h`.
- `$archivos = (Get-ChildItem -Recurse -Filter *.cpp).FullName` hace una búsqueda recursiva y guarda sus rutas.
- `g++ -std=c++17 -Wall -Wextra -I . $archivos -o parque` compila el programa en un ejecutable llamado `parque.exe`.
- `.\parque.exe` inicializa el ejecutable del TP.

## Módulos
Se optó por organizar las funciones del programa a partir de su propósito.
Existen 5 carpetas padre:
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

## Preguntas de diseño

### ¿Por qué los datos del parque están en un registro?
> struct DatosParque

Se compacto las variables importantes del proyectos en un solo registro para pasarlo por referencia a los menús y a toda función que lo modifique:
- la lista enlazada de visitantes activos;
- el arreglo de juegos y **cuántos** hay cargados (`cantJuegos`);
- la matriz de ocupación `ocupacion[juego][franja]`.
- las filas de los juegos

Así se evitan tener que pasar como parametro muchas variables en cada menu y en cada funcion. Solo se llama lo necesario. Por ejemplo: `seleccionarJuego(datos.juegos, datos.cantJuegos)`

### ¿Por qué la matriz se genera en el momento?
> reconstruirMatriz()

Crear una matriz con datos no relacionados con la lista de Juegos, es insostenible. Si la ordenamos, cambiamos nombres, agregamos o quitamos uno; la matriz no lo sabrá.

Por ello, se decidió colocar el vector de ocupación por franja dentro de cada Juego y luego la matriz se reconstruye leyendo el orden de la lista de juegos y sus respectivos ocupantes por franja cada vez que se quiere saber los datos de ocupación de todo el parque.

Como resultado, ahora si se ordena la lista, la matriz también. Si se elimina o se agrega un juego, en la matriz también.

### ¿Por qué crear una función para mostrar tablas?
> imprimirTabla()

Facilita la forma de mostrar datos para el usuario.

### ¿Por qué tantos menús?
> /menu

Facilita la legibilidad para el usuario, separando tareas por su funcionalidad. Así en vez de tener 20 funciones en una sola pantalla, se distribuyen en menús secundarios.

##### ¿Por qué el menú se imprime una sola vez por ingreso?

Nuevamente, por un tema de experiencia de usuario. Estar reimprimiendo el menu al terminar cada función, no permite al usuario leer correctamente lo que pidio. Para ello, se decidió que el mismo usuario pueda reimprimir el menu ingresando `0` a la consola.

## Integrantes y responsabilidades
1. **Ramírez, Juan Ramón Agustín**
    > *Encargado, Arquitecura del proyecto, Interfaz, Nodos, Datos de prueba, creación y lectura de archivos de Juegos, Indices e Interfaz (menu)*.
2. **Orsini, Joaquín**
    > *Ordenamiento de Juegos, búsqueda de Juegos por Código o Nombre y Colas*.
3. **Szrebka, Ramiro Agustín**
    > *Lógica de gestión de Visitantes, Cargar juegos e imprimirlos, Filtrar juegos más usados, Matriz de visitas y Pilas*.
4. **Segovia Soler, Ignacio Matias**
    > *Verificar altura, Cambiar estado de Juego, Reporte del día y Recursión*.
