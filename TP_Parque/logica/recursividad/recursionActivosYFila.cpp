#include "recursionActivosYFila.h"
#include <iostream>

int contarActivosRec(NodoVisitante* lista) {
    if (lista == nullptr) {
        return 0;
    }
    return 1 + contarActivosRec(lista->siguiente);
}

void atenderFilaRec() {
    std::cout << "\n[Recursividad] Ejecutando atencion recursiva de fila...\n";
}