# Preguntas de diseño

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