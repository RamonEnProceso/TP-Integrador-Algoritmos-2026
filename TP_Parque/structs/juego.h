#ifndef JUEGO_H
#define JUEGO_H
#include "constantes/generales.h"
struct Juego {
    int codigo;
    char nombre[LARGO_NOMBRE];
    int tipo;
    float alturaMinima;
    int capacidad;
    bool operativo;
};

#endif
