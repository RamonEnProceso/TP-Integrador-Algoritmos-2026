#include "logica/pila/obtenerHistorialVisitante.h"
#include "structs/nodoVisitante.h"
#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"
#include "logica/pila/mostrarHistorial.h"
#include <iostream>

using namespace std;

void obtenerHistorialVisitante(NodoVisitante *&listaVisitantes, int &pulsera){
    cout << "Ingrese el numero de pulsera del visitante: ";
    cin >> pulsera; cout << endl;

    NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(listaVisitantes, pulsera);
    if (nodo == nullptr) {
        cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
        return;
    }
    mostrarHistorial(nodo->visitante);
    return;
}