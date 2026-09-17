#ifndef MATRIZ_JUEGOXHORAS_H
#define MATRIZ_JUEGOXHORAS_H
#include "constantes/matrizConstantes.h"
#include "structs/juego.h"
struct MatrizJuegoXHoras {
    int matriz[MAX_JUEGOS][FRANJAS_HORARIAS];
    int franjas;
    int cantJuegos;
    Juego listaJuegos;
};

#endif
