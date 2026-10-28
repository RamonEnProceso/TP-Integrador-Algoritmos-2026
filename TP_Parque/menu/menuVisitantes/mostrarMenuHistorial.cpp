#include "menu/menuVisitantes/mostrarMenuHistorial.h"
#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"
#include "logica/pila/desapilarJuego.h"
#include "logica/pila/mostrarHistorial.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputMenu.h"
#include "logica/pila/apilarVisitanteJuego.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Visitantes > Historial de juegos");
    imprimirConNumero(1, "Apilar juego visitado");
    imprimirConNumero(2, "Deshacer ultimo juego (desapilar)");
    imprimirConNumero(3, "Ver historial");
    imprimirConNumero(4, "Volver al menu anterior");
}


void mostrarMenuHistorial(NodoVisitante *&listaVisitantes){
    int opcionElegida = 0, pulsera = 0;

    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida = -2; pulsera = 0;

        leerInputMenu(0, 4, opcionElegida);

        switch (opcionElegida) {
            case 0:
                imprimirMenu();
                break;
            case 1: {
                apilarVisitanteJuego(listaVisitantes, pulsera);
                break;
            }
            case 2: {
                cout << "Ingrese el numero de pulsera del visitante: ";
                cin >> pulsera; cout << endl;

                NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(listaVisitantes, pulsera);
                if (nodo == nullptr) {
                    cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
                    break;
                }
                desapilarJuego(nodo->visitante);
                cout << "Se deshizo el ultimo juego del historial.\n\n";
                break;
            }
            case 3: {
                cout << "Ingrese el numero de pulsera del visitante: ";
                cin >> pulsera; cout << endl;

                NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(listaVisitantes, pulsera);
                if (nodo == nullptr) {
                    cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
                    break;
                }
                mostrarHistorial(nodo->visitante);
                break;
            }
            case 4:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
