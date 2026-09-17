#include "menu/menuJuegos/mostrarMenuListaJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/vector/mostrarListaJuegos.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarMenuListaJuegos(Juego *listaJuegos, int cantJuegos) {
    int opcionElegida = 0;

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Mostrar lista de Juegos");
        imprimirConNumero(1, "Completa");
        imprimirConNumero(2, "Solo disponibles");
        imprimirConNumero(3, "Volver al Menu de Juegos");

        while (opcionElegida < 1 || opcionElegida > 3) {
            cout << "Ingresa el numero de opcion elegida: "; 
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 3) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {
            case 1:
                mostrarListaJuegos(listaJuegos, cantJuegos);
                break;
            case 2:
                mostrarListaJuegosDisponibles(listaJuegos, cantJuegos);
                break;
            case 3:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}