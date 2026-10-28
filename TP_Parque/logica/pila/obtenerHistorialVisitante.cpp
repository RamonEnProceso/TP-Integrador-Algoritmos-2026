#include "logica/pila/obtenerHistorialVisitante.h"
#include "structs/nodoVisitante.h"
#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"
#include "logica/pila/mostrarHistorialVisitante.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "structs/visitante.h"
#include "structs/datosParque.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void obtenerHistorialVisitante(DatosParque &datos, int &pulsera){
    cout << "Ingrese el numero de pulsera del visitante: ";
    cin >> pulsera; cout << endl;

    NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(datos.listaVisitantes, pulsera);
    if (nodo == nullptr) {
        cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
        return;
    }
    if (datos.cantJuegos == 0) {
        datos.cantJuegos = leerArchivoJuegos(datos.juegos, MAX_JUEGOS);
    }
    mostrarHistorialVisitante(nodo->visitante.historial, datos.juegos, datos.cantJuegos);
    return;
}
