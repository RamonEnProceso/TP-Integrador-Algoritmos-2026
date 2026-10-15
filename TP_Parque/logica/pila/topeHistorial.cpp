#include "logica/pila/topeHistorial.h"

int topeHistorial(NodoJuegoVisitado *pila){
    if (pila == nullptr){
        return -1;                      // pila vacía: no hay tope
    }
    return pila->codigoJuego;           // solo miro, no saco nada
}