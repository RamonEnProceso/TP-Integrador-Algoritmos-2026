#include "logica/cola/mostrarFilaJuego.h"
#include "utiles/outputs/imprimirTitulo.h"
#include <iostream>

using namespace std;

void mostrarFilaJuego(Cola c) {
    imprimirTitulo("FILA ACTUAL DEL JUEGO");
    if (c.frente == nullptr) {
        cout << "La fila esta actualmente vacia.\n\n";
        return;
    }

    NodoVisitante* aux = c.frente;
    int posicion = 1;
    
    while (aux != nullptr) {
        cout << posicion << ". " << aux->visitante.nombre 
             << " (Pulsera: " << aux->visitante.pulsera << ")\n";
        aux = aux->siguiente;
        posicion++;
    }
    cout << "\n";
}
