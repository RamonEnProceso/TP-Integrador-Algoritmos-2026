#include "logica/cola/encolarVisitante.h"

void encolarVisitante(Cola &c, Visitante v) {
    NodoVisitante* nuevo = new NodoVisitante();
    nuevo->visitante = v;
    nuevo->siguiente = nullptr;

    if (c.frente == nullptr) {
        c.frente = nuevo;
    } else {
        c.fin->siguiente = nuevo;
    }
    c.fin = nuevo;
}
