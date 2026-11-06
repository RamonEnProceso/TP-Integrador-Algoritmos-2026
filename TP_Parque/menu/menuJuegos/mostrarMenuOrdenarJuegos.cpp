#include "menu/menuJuegos/mostrarMenuOrdenarJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/vector/ordenarPorCodigo.h"
#include "logica/vector/ordenarPorNombre.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarMenuOrdenarJuegos(Juego *listaJuegos, int cantJuegos, Cola *filas) {
    int opcionElegida = 0;

    while (opcionElegida != -1) {
        opcionElegida  = -2;;
        imprimirTitulo("Ordenar Juegos de Menor a Mayor");
        imprimirConNumero(1, "Por Codigo");
        imprimirConNumero(2, "Alfabeticamente");
        imprimirConNumero(3, "Volver al Menu de Juegos");

        while (opcionElegida < 1 || opcionElegida > 3) {
            cout << "Ingresa el numero de opcion elegida: "; 
            if (!(cin >> opcionElegida)) { if (cin.eof()) return; cin.clear(); cin.ignore(10000, '\n'); opcionElegida = -2; }
            cout << endl;
            if (opcionElegida < 1 || opcionElegida > 3) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {
            case 1:
                ordenarPorCodigo(listaJuegos, cantJuegos, filas);
                cout << "Juegos ordenados por codigo exitosamente.\n\n";
                break;
            case 2:
                ordenarPorNombre(listaJuegos, cantJuegos, filas);
                cout << "Juegos ordenados alfabeticamente exitosamente.\n\n";
                break;
            case 3:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}