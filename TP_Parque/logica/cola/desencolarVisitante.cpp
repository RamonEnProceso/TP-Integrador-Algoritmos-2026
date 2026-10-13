#include "logica/cola/desencolarVisitante.h"

bool desencolarVisitante(Cola &c, Visitante &v) {
    if (c.frente == nullptr) {
        return false;
    }

    NodoVisitante* aux = c.frente;
    v = aux->visitante;
    c.frente = aux->siguiente;

    if (c.frente == nullptr) {
        c.fin = nullptr;
    }

    delete aux;
    return true;
}
