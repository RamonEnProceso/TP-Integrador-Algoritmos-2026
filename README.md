# 🎢 TP Integrador — Parque de Diversiones

>UTN FRBA · Algoritmos y Estructuras de Datos · Cátedra Ing. Ariel García

## ¿Qué Hace?

## Cómo compilar y ejecutar

Los siguientes pasos son para compilar el `main.cpp` desde la raíz del proyecto. Para hacerlo, se tiene que tener instalado el compilador `g++` en cualquiera de los dos sistemas operativos.

### Windows 

Para compilar el proyecto, respetando la consigna del trabajo, se debe insertar los siguientes comandos en `Powershell` desde la raíz:

```powershell
cd .\TP_Parque\
$archivos = (Get-ChildItem -Recurse -Filter *.cpp).FullName
g++ -std=c++17 -Wall -Wextra -I . $archivos -o parque
.\parque.exe
```
- `cd .\TP_Parque\` es para ingresar a la carpeta donde se encuentran los distintos archivos `.cpp` y `.h`.
- `$archivos = (Get-ChildItem -Recurse -Filter *.cpp).FullName` hace una búsqueda recursiva y guarda sus rutas.
- `g++ -std=c++17 -Wall -Wextra -I . $archivos -o parque` compila el programa en un ejecutable llamado `parque.exe`.
- `.\parque.exe` inicializas el ejecutable del TP.

### Linux -> Debian

Para compilar el proyecto en una distribución basada en Debian, se debe insertar los siguientes comandos en `Bash` desde la raíz:

`
cd TP_Parque/
g++ -std=c++17 -Wall -Wextra -I. $(find . -name "*.cpp") -o parque.exe
./parque.exe
`

## Módulos



## Integrantes y responsabilidades
1. **Ramírez, Juan Ramón Agustín**
    > *Encargado, Arquitecura del proyecto, Interfaz, Nodos, Datos de prueba, creación y lectura de archivos de Juegos*...
2. **Orsini, Joaquín**
    > *Ordenamiento de Juegos, búsqueda de Juegos por Código o Nombre*...
3. **Szrebka, Ramiro Agustín**
    > *Lógica de gestión de Visitantes, Cargar juegos e imprimirlos, filtrar juegos más usados, matrices*...
4. **Segovia Soler, Ignacio Matias**
    > ...
