#include "logica/nodo/obtenerVisitantePorPulsera.h"

bool obtenerVisitantePorPulsera(NodoVisitante *lista, int pulseraNum, Visitante &v) {
    NodoVisitante *actual = lista;
    while (actual != nullptr) {
        if (actual->visitante.pulsera == pulseraNum) {
            v = actual->visitante;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}
