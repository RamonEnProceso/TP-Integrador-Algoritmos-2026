#include "structs/nodoVisitante.h"
#include "logica/pila/desapilarJuego.h"
#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"
#include "logica/pila/desapilarVisitanteJuego.h"
#include <iostream>

using namespace std;

void desapilarVisitanteJuego(NodoVisitante *&listaVisitantes,int &pulsera){
    cout << "Ingrese el numero de pulsera del visitante: ";
    cin >> pulsera; cout << endl;
    NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(listaVisitantes, pulsera);
    if (nodo == nullptr) {
        cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
        return;
    }
    desapilarJuego(nodo->visitante);
   return;
}