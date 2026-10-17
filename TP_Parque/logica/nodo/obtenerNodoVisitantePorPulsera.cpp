#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"

NodoVisitante* obtenerNodoVisitantePorPulsera(NodoVisitante *lista, int pulseraNum){
    NodoVisitante *actual = lista;
    while (actual != nullptr && actual->visitante.pulsera != pulseraNum){
        actual = actual->siguiente;
    }
    return actual;
}
