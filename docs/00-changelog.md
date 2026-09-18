# Historial de Cambios

## v0.0.6 - (18/09/2026)
- Ramón | *Refactorizar matriz y vector de Juegos*
    - Incluir vector de ocupaciones de juegos dentro de esta
    - La matriz solo lee el puntero a los juegos

## v0.0.6 - (17/09/2026)
> Matriz de ocupación, submenús de Juegos y datos unificados
- Ramón | *Unificar el estado del parque en el registro `DatosParque`*
    - Lista de visitantes activos, arreglo de juegos con su cantidad y matriz de ocupación
    - Los datos viajan por parámetro y por referencia: sin variables globales
- Ramón | *Adaptar los menús y las funciones de lógica a la nueva estructura*
- Ramón | *Separar el menú de Juegos en submenús* (`menuJuegos/`: listar, ordenar, buscar, archivos)
- Ramón | *Crear el menú de Ocupación*: matriz por franja, pico máximo, juego más usado y totales del día
- Ramón | *Cargar la matriz de ocupación con datos de prueba* (10 juegos × 5 franjas horarias)
- Ramón | *Corregir la carga de la matriz, la cantidad de juegos usada en listados y búsquedas, y la liberación de la lista de visitantes al salir*
- Ramón | *Corregir la validación del menú de Visitantes (la opción "Volver" no se podía elegir) y el orden del resumen de ocupación*
- Ramón | *Documentar la matriz de ocupación, las decisiones de diseño y las equivalencias con el Sheet* (`05-Decisiones.md`)

## v0.0.5 - (14/09/2026)
> Vectores: ordenamiento, búsquedas y submenú
- Joaquín | *Reescribir `leerArchivoJuegos()` para cargar binario y leerlo*
- Joaquín | *Añadir `ordenarPorCodigo()` y `ordenarPorNombre()`*
- Joaquín | *Añadir `buscarJuegoPorCodigo` por ordenamiento binario*
- Joaquín | *Añadir `buscarJuegoPorNombre()`*
- Joaquín | *Añadir submenú de Juegos*
- Joaquín | *Añadir `seleccionarJuego()` y conectarlo al menú de Visitantes*
- Joaquín | *Corregir rutas*

## v0.0.4 - (13/09/2026)
> Matrices y Vectores
- Ramiro | *Modificar datos de prueba para variar datos*
- Ramiro | *Añadir función para registrar visitante desde menú*
- Ramiro | *Crear registro `MatrizJuegoXFranja` para facilitar manipulación de datos.*
- Ramiro | *Añadir función `swap()` para facilitar el ordenamiento burbuja*
- Ramiro | *Añadir funciones para ordenar dos vectores a la par (`ordenarDatosMinMax`) y encontrar la posición mayor (`devolverMayorPosV`)*

## v0.0.3 - (08/09/2026)
> Pulido, mejor menú y funciones útiles
- Ramón | *Corrección de errores*
    - Dependencias perdidas
    - Variables redundantes
- Ramón | *Creación de funcion para calcular promedio de un vector de enteros*
- Ramón | *Conectar menú con funciones de gestión de Visitante*
    - Generar datos de prueba
    - Mostrar lista
    - Buscar
    - Eliminar

## v0.0.2 - (07/09/2026)
> Creación de lista enlazada
- Ramón | *Creación de Datos de Prueba*
- Ramón | *Creación de funciones para grabar archivo con juegos*
- Ramón | *Creación de lista de Nodos para Visitantes*
- Ramón | *Creación de funciónes agregar y mostrar Visitantes Activos*
- Ramón | *Creación de función eliminar por Visitante mediante número de pulsera*
- Ramón | *Creación de función para liberar lista de Visitantes Activos*

## v0.0.1 - (06/09/2026)
> Inicio
- Ramón | *Creación del Repositorio*
- Ramón | *Armado de arquitectura/ disposición de carpetas*
- Ramón | *Creación de Registros `Juego.h` y `Visitante.h`*
- Ramón | *Creación de Menu Principal y Menu Visitantes*
- Ramón | *Creación de Funciones reutilizables `imprimirConNum` y `imprimirTitulo`*
