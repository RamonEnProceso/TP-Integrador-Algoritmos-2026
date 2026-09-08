#include "logica/nodo/nodoVisitante.h"
#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include <iostream>

using namespace std;

NodoVisitante* eliminarVisitanteListaPorPulsera(NodoVisitante *lista, int numPulsera){
    NodoVisitante *anterior = nullptr;
    NodoVisitante *actual = lista;

    cout << "Buscando Visitante...\n";

    while(actual != nullptr && actual->visitante.pulsera != numPulsera){
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr){
        cerr << "No se encontro un visitante con esa numero de pulsera.\n\n";
        return lista;
    }

    if (anterior==nullptr){
        lista = actual->siguiente;
    } else{
        anterior->siguiente = actual->siguiente;
    }

    cout << "Se procederá a eliminar al visitante " << actual->visitante.nombre << endl;

    delete actual;

    cout << "Visitante eliminado correctamente.\n\n";

    return lista;
};
