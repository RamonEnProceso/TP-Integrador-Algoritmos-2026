#include "logica/nodo/agregarVisitanteLista.h"
#include "structs/nodoVisitante.h"
#include "structs/visitante.h"

NodoVisitante* agregarVisitanteLista(Visitante dato, NodoVisitante *lista){
    NodoVisitante *nuevo = new NodoVisitante;
    nuevo->visitante = dato;
    nuevo->siguiente = lista;
    return nuevo;
};
