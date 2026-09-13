#ifndef NODO_VISITANTE_H
#define NODO_VISITANTE_H
#include "structs/visitante.h"

struct NodoVisitante {
    Visitante visitante;
    NodoVisitante *siguiente;
};

#endif