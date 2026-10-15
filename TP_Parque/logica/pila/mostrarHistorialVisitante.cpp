#include "logica/pila/mostrarHistorialVisitante.h"
#include <iostream>

using namespace std;

void mostrarHistorialVisitante(NodoJuegoVisitado *pila){
    if (pila == nullptr){
        cout << "El visitante todavia no uso ningun juego.\n\n";
        return;
    }

    cout << "Historial (del mas reciente al mas viejo):\n";
    NodoJuegoVisitado *actual = pila;       // recorro con otro puntero, el tope no se mueve
    while (actual != nullptr){
        cout << " - Juego codigo " << actual->codigoJuego << endl;
        actual = actual->siguiente;
    }
    cout << endl;
}