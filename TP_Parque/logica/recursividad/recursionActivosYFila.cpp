#include "recursionActivosYFila.h"
#include "logica/cola/atenderSiguienteVisitante.h"

int contarActivosRec(NodoVisitante* lista) {
    if (lista == nullptr) {
        return 0;
    }
    return 1 + contarActivosRec(lista->siguiente);
}

void atenderFilaRec(Cola &c, NodoVisitante *lista, Juego *juego, int franja) {
    // caso base: fila vacia, no hay nada que atender
    if (c.frente == nullptr) {
        return;
    }
    // atiendo al visitante que esta al frente
    atenderSiguienteVisitante(c, lista, juego, franja);
    // caso recursivo: atiendo el resto de la fila
    atenderFilaRec(c, lista, juego, franja);
}
