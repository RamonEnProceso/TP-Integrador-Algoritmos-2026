#include "logica/pila/apilarJuegoVisitado.h"

NodoJuegoVisitado* apilarJuegoVisitado(NodoJuegoVisitado *pila, int codigoJuego){
    NodoJuegoVisitado *nuevo = new NodoJuegoVisitado;  // creo el nodo nuevo
    nuevo->codigoJuego = codigoJuego;                  // le guardo el juego
    nuevo->siguiente = pila;                           // lo pongo arriba de lo que había
    return nuevo;                                      // el nuevo es el nuevo tope
}