#ifndef JUEGO_H
#define JUEGO_H
#include "structs/constante.h"
struct Juego {
    int codigo;
    char nombre[LARGO_NOMBRE];
    int tipo; 
    float alturaMinima;
    int capacidad;
    bool operativo;
};

#endif