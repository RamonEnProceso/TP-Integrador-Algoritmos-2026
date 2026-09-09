#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include "logica/nodo/nodoVisitante.h"
#include "utiles/outputs/imprimirVisitante.h"
#include <iostream>

using namespace std;

void buscarVisitanteActivoPorPulsera(NodoVisitante *lista, int pulseraNum){
    NodoVisitante *actual = lista;
    while (actual != nullptr && actual->visitante.pulsera != pulseraNum)
    {
        actual = actual->siguiente;
    }

    if(actual != nullptr){
        imprimirVisitante(actual->visitante);
        return;
    }

    cout << "No se encontró a un Visitante con esa pulsera.\n\n";
    
    return;
}