#ifndef DATOS_PARQUE_H
#define DATOS_PARQUE_H
#include "structs/matrizJuegoxHoras.h"
#include "structs/nodoVisitante.h"
#include "structs/juego.h"
#include "structs/cola.h"

struct DatosParque {
    NodoVisitante* listaVisitantes;
    MatrizJuegoXHoras datosMatriz;
    Juego juegos[MAX_JUEGOS];
    Cola filasJuegos[MAX_JUEGOS];
    int cantJuegos;
};

#endif