#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include "logica/nodo/nodoVisitante.h"

bool buscarVisitanteActivoPorPulsera(
    NodoVisitante *lista, int pulseraNum){
    NodoVisitante *actual = lista;
    while (actual != nullptr && actual->visitante.pulsera != pulseraNum)
    {
        actual = actual->siguiente;
    }
    return actual != nullptr;
}