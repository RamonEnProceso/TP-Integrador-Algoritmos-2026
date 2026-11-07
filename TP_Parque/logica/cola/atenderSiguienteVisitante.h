#ifndef ATENDER_SIGUIENTE_VISITANTE_H
#define ATENDER_SIGUIENTE_VISITANTE_H
#include "structs/cola.h"
#include "structs/juego.h"

void atenderSiguienteVisitante(Cola &c, NodoVisitante *lista = nullptr, Juego *juego = nullptr, int franja = 0);

#endif
