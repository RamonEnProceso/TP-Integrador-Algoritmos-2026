#include "logica/nodo/nodoVisitante.h"
#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include <iostream>

using namespace std;

NodoVisitante* eliminarVisitanteListaPorPulsera(NodoVisitante *lista, int numPulsera){
    NodoVisitante *anterior = nullptr;
    NodoVisitante *actual = lista;

    while(actual != nullptr && actual->visitante.pulsera != numPulsera){
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr){
        cerr << "No se encontro un visitante con esa numero de pulsera.\n";
        return lista;
    }

    if (anterior==nullptr){
        lista = actual->siguiente;
    } else{
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
    return lista;
};
