#ifndef IMPRIMIR_TABLA_H
#define IMPRIMIR_TABLA_H
#include "constantes/generales.h"

struct Tabla{
    int largoNombre = LARGO_NOMBRE;
    int columnas;
    int filas;
    char** nombresColumnas;
    char** nombresFilas;
    int** contenido;
};


void imprimirTabla(Tabla datos);

void imprimirTablaMonoColum(const char* encabezado, char nombres[][LARGO_NOMBRE], int* num, int cant);

#endif