#include "logica/pila/mostrarHistorialVisitante.h"
#include "logica/pila/topeHistorial.h"
#include "logica/vector/buscarJuegoPorCodigoBinaria.h"
#include "logica/vector/ordenarPorCodigo.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarHistorialVisitante(NodoJuegoVisitado *pila, Juego juegos[], int cantidad){
    if (topeHistorial(pila) == -1){
        cout << "El visitante todavia no uso ningun juego.\n\n";
        return;
    }

    Juego ordenados[MAX_JUEGOS];
    for (int i = 0; i < cantidad; i++) ordenados[i] = juegos[i];
    ordenarPorCodigo(ordenados, cantidad);

    cout << "Historial (del mas reciente al mas viejo):\n";
    NodoJuegoVisitado *actual = pila; 
    while (actual != nullptr){
        int idx = buscarJuegoPorCodigoBinaria(ordenados, cantidad, actual->codigoJuego);
        if (idx != -1) {
            cout << " - Juego: " << ordenados[idx].nombre << endl;
        }
        actual = actual->siguiente;
    }
    cout << endl;
}
