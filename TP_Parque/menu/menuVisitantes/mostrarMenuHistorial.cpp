#include "menu/menuVisitantes/mostrarMenuHistorial.h"
#include "menu/seleccionarJuego.h"
#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"
#include "logica/pila/apilarJuego.h"
#include "logica/pila/desapilarJuego.h"
#include "logica/pila/mostrarHistorial.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "structs/juego.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputMenu.h"
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
                cout << "Ingrese el numero de pulsera del visitante: ";
                cin >> pulsera; cout << endl;

                NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(listaVisitantes, pulsera);
                if (nodo == nullptr) {
                    cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
                    break;
                }

                Juego juegos[50];
                int cantJuegos = leerArchivoJuegos(juegos, 50);
                if (cantJuegos == 0) {
                    cout << "No hay juegos cargados en el sistema.\n\n";
                    break;
                }

                cout << "Seleccione el juego que el visitante visito:\n";
                int idxJuego = seleccionarJuego(juegos, cantJuegos);
                if (idxJuego >= 0 && idxJuego < cantJuegos) {
                    apilarJuego(nodo->visitante, juegos[idxJuego]);
                    cout << ">>> " << nodo->visitante.nombre << " visito '"
                         << juegos[idxJuego].nombre << "'. Se apilo en su historial. <<<\n\n";
                }
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
