#include "logica/cola/liberarCola.h"

void liberarCola(Cola &c) {
    NodoVisitante* actual = c.frente;
    while (actual != nullptr) {
        NodoVisitante* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    c.frente = nullptr;
    c.fin = nullptr;
}
