#include "logica/pila/desapilarJuegoVisitado.h"

NodoJuegoVisitado* desapilarJuegoVisitado(NodoJuegoVisitado *pila){
    if (pila == nullptr){
        return nullptr;                 // pila vacía: no hay nada que sacar
    }
    NodoJuegoVisitado *aux = pila;      // guardo el tope para poder liberarlo
    pila = pila->siguiente;             // el de abajo pasa a ser el nuevo tope
    delete aux;                         // libero el nodo que saqué
    return pila;                        // devuelvo el nuevo tope
}