#include "logica/pila/desapilarJuegoVisitado.h"

NodoJuegoVisitado* desapilarJuegoVisitado(NodoJuegoVisitado *pila){
    if (pila == nullptr){
        return nullptr;
    }
    NodoJuegoVisitado *aux = pila;    
    pila = pila->siguiente;             
    delete aux;                         
    return pila;                        
}
