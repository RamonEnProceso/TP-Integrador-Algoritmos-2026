#ifndef DATOS_PARQUE_H
#define DATOS_PARQUE_H
#include "structs/matrizJuegoxHoras.h"
#include "structs/nodoVisitante.h"
#include "structs/juego.h"

struct DatosParque {
    NodoVisitante* listaVisitantes;
    MatrizJuegoXHoras datosMatriz;
    Juego juegos[MAX_JUEGOS];
    int cantJuegos;
};

#endif