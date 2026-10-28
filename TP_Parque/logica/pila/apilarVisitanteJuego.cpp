#include "logica/pila/apilarVisitanteJuego.h"
#include "structs/nodoVisitante.h"
#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "menu/menuJuegos/seleccionarJuego.h"
#include "logica/pila/apilarJuego.h"
#include <iostream>

using namespace std;

void apilarVisitanteJuego(NodoVisitante *&listaVisitantes, int &pulsera){
    cout << "Ingrese el numero de pulsera del visitante: ";
    cin >> pulsera; cout << endl;

    NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(listaVisitantes, pulsera);
    if (nodo == nullptr) {
        cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
        return;
    }

    Juego juegos[50];
    int cantJuegos = leerArchivoJuegos(juegos, 50);
    if (cantJuegos == 0) {
         cout << "No hay juegos cargados en el sistema.\n\n";
       return;
    }

    cout << "Seleccione el juego que el visitante visito:\n";
    int idxJuego = seleccionarJuego(juegos, cantJuegos);
    if (idxJuego >= 0 && idxJuego < cantJuegos) {
        apilarJuego(nodo->visitante, juegos[idxJuego]);
        cout << ">>> " << nodo->visitante.nombre << " visito '"
        << juegos[idxJuego].nombre << "'. Se apilo en su historial. <<<\n\n";
    }
    return;
}