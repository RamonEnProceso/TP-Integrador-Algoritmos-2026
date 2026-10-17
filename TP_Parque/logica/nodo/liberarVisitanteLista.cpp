#include "logica/nodo/liberarVisitanteLista.h"
#include "logica/pila/liberarHistorial.h"
#include "structs/nodoVisitante.h"

NodoVisitante* liberarVisitanteLista(NodoVisitante *lista){
    while (lista != nullptr){
        NodoVisitante *aux = lista;
        lista = lista->siguiente;
        liberarHistorial(aux->visitante);
        delete aux;
    }
    return nullptr;
};
