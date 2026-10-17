#include "./utiles/outputs/imprimirTabla.h"
#include <iostream>

using namespace std;

int largoEntero(int n){
    if (n == 0){
        return 1;
    }
    int largo = 0;
    long valor = n;            
    if (valor < 0){
        largo = 1;             
        valor = -valor;
    }
    while (valor > 0){
        largo++;
        valor = valor / 10;
    }
    return largo;
}

int largoTexto(const char* texto){
    int i = 0;
    while (texto[i] != '\0'){
        i++;
    }
    return i;
}

// Funciones para alinear datos
void imprimirIzquierdaChar(const char* texto, int ancho){
    cout << texto;
    for (int i = largoTexto(texto); i < ancho; i++){
        cout << " ";
    }
}
void imprimirDerechaChar(const char* texto, int ancho){
    for (int i = largoTexto(texto); i < ancho; i++){
        cout << " ";
    }
    cout << texto;
}
void imprimirDerechaInt(int n, int ancho){
    for (int i = largoEntero(n); i < ancho; i++){
        cout << " ";
    }
    cout << n;
}


// Funcion principal
void imprimirTabla(Tabla datos){

    // Ancho de celdas
    int anchoCelda = 1;
    for (int j = 0; j < datos.columnas; j++){
        int largo = largoTexto(datos.nombresColumnas[j]);
        if (largo > anchoCelda){
            anchoCelda = largo;
        }
    }
    for (int i = 0; i < datos.filas; i++){
        for (int j = 0; j < datos.columnas; j++){
            int largo = largoEntero(datos.contenido[i][j]);
            if (largo > anchoCelda){
                anchoCelda = largo;
            }
        }
    }

    // Encabezado
    imprimirIzquierdaChar(" ", datos.largoNombre);
    for (int j = 0; j < datos.columnas; j++){
        cout << " | ";
        imprimirDerechaChar(datos.nombresColumnas[j], anchoCelda);
    }
    cout << endl;

    // Linea separadora
    int anchoTotal = datos.largoNombre + datos.columnas * (anchoCelda + 3);
    for (int k = 0; k < anchoTotal; k++){
        cout << "-";
    }
    cout << endl;

    // Filas de datos
    for (int i = 0; i < datos.filas; i++){
        imprimirIzquierdaChar(datos.nombresFilas[i], datos.largoNombre);
        for (int j = 0; j < datos.columnas; j++){
            cout << " | ";
            imprimirDerechaInt(datos.contenido[i][j], anchoCelda);
        }
        cout << endl;
    }
}
