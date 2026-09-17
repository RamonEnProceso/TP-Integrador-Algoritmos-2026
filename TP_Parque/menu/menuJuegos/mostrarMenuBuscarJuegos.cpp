#include "menu/menuJuegos/mostrarMenuBuscarJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/outputs/imprimirJuego.h"
#include "logica/vector/ordenarPorCodigo.h"
#include "logica/vector/buscarJuegoPorCodigoBinaria.h"
#include "logica/texto/buscarJuegoPorNombre.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarMenuBuscarJuegos(Juego *listaJuegos, int cantJuegos) {
    int opcionElegida = 0;

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Buscar Juego");
        imprimirConNumero(1, "Por Codigo");
        imprimirConNumero(2, "Por Nombre");
        imprimirConNumero(3, "Volver al Menu de Juegos");

        while (opcionElegida < 1 || opcionElegida > 3) {
            cout << "Ingresa el numero de opcion elegida: "; 
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 3) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {
            case 1: {
                cout << "Ingrese el codigo a buscar: ";
                int cod;
                cin >> cod;
                ordenarPorCodigo(listaJuegos, cantJuegos); 
                int posCod = buscarJuegoPorCodigoBinaria(listaJuegos, cantJuegos, cod);
                if (posCod != -1) {
                    imprimirJuego(listaJuegos[posCod]);
                } else {
                    cout << "Juego no encontrado.\n\n";
                }
                break;
            }
            case 2: {
                cout << "Ingrese el nombre a buscar (parcial): ";
                char nom[LARGO_NOMBRE];
                cin.ignore();
                cin.getline(nom, LARGO_NOMBRE);
                int posNom = buscarJuegoPorNombre(listaJuegos, cantJuegos, nom);
                if (posNom != -1) {
                    imprimirJuego(listaJuegos[posNom]);
                } else {
                    cout << "Juego no encontrado.\n\n";
                }
                break;
            }
            case 3:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}