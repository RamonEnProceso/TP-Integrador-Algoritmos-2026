#include "utiles/inputs/leerInputMenu.h"
#include <iostream>

using namespace std;

void leerInputMenu(int min, int max, int &opcionElegida){
    while (opcionElegida < min || opcionElegida > max) {
            cout << "Ingresa un numero (0 para imprimir menu): ";
            if (!(cin >> opcionElegida)) {
                if (cin.eof()) { opcionElegida = max; return; }
                cin.clear();
                cin.ignore(10000, '\n');
                opcionElegida = min - 1;
            }
            cout << endl;
            if (opcionElegida < min || opcionElegida > max) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
        }
    }
}
