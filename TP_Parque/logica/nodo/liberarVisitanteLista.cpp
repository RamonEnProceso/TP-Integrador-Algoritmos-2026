#include "logica/nodo/liberarVisitanteLista.h"
#include "logica/nodo/nodoVisitante.h"

NodoVisitante* liberarVisitanteLista(NodoVisitante *lista){
    while (lista != nullptr){
        NodoVisitante *aux = lista;
        lista = lista->siguiente;
        delete aux;
    }
    return nullptr;
};