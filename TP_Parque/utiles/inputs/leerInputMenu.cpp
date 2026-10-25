#include "utiles/inputs/leerInputMenu.h"
#include <iostream>

using namespace std;

void leerInputMenu(int min, int max, int &opcionElegida){
    while (opcionElegida < min || opcionElegida > max) {
            cout << "Ingresa un numero (0 para imprimir menu): ";
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < min || opcionElegida > max) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
        }
    }
}
