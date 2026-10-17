#include "structs/datosParque.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirTabla.h"
#include "constantes/matrizConstantes.h"

void imprimirMatriz(DatosParque datos){

    imprimirTitulo("Matriz de ocupantes por franja");

    char* nombresColumnas[FRANJAS_HORARIAS];
    char* nombresFilas[MAX_JUEGOS];

    for (int j = 0; j < datos.datosMatriz.franjas; j++){
        nombresColumnas[j] = (char*)FRANJAS_TEXTO[j];
    }
    for (int i = 0; i < datos.datosMatriz.juegos; i++){
        nombresFilas[i] = datos.juegos[i].nombre;
    }

    Tabla tabla;
    tabla.columnas = datos.datosMatriz.franjas;
    tabla.filas = datos.datosMatriz.juegos;
    tabla.nombresColumnas = nombresColumnas;
    tabla.nombresFilas = nombresFilas;
    tabla.contenido = datos.datosMatriz.matriz;

    imprimirTabla(tabla);
}
