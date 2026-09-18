#ifndef MATRIZ_JUEGOXHORAS_H
#define MATRIZ_JUEGOXHORAS_H
#include "constantes/matrizConstantes.h"
#include "structs/juego.h"
struct MatrizJuegoXHoras {
    int *matriz[MAX_JUEGOS];
    int franjas;
    int juegos;
};

#endif
