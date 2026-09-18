#ifndef JUEGO_H
#define JUEGO_H
#include "constantes/generales.h"
#include "constantes/matrizConstantes.h"
struct Juego {
    int codigo;
    char nombre[LARGO_NOMBRE];
    int tipo;
    float alturaMinima;
    int capacidad;
    bool operativo;
    int franjas[FRANJAS_HORARIAS];
};

#endif
