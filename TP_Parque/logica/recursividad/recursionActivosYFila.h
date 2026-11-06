#ifndef RECURSION_ACTIVOS_Y_FILA_H
#define RECURSION_ACTIVOS_Y_FILA_H


#include "structs/nodoVisitante.h"
#include "structs/cola.h"
#include "structs/juego.h"

int contarActivosRec(NodoVisitante* lista);

void atenderFilaRec(Cola &c, NodoVisitante *lista = nullptr, Juego *juego = nullptr, int franja = 0);

#endif
