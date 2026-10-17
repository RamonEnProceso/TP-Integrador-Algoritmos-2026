#include "logica/cola/estaEnCola.h"

bool estaEnCola(const Cola &c, int pulsera) {
    NodoVisitante* actual = c.frente;
    while (actual != nullptr) {
        if (actual->visitante.pulsera == pulsera) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}
