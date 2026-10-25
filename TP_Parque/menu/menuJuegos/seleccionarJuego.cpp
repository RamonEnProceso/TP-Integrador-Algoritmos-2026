#include <iostream>
#include "menu/menuJuegos/seleccionarJuego.h"
#include "logica/vector/buscarJuegoPorCodigoBinaria.h"
#include "logica/texto/buscarJuegoPorNombre.h"
#include "logica/vector/ordenarPorCodigo.h"
#include "utiles/outputs/imprimirJuego.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputMenu.h"

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("SELECCIONAR JUEGO");
    char listaMenu[3][LARGO_NOMBRE] = {"Buscar por Codigo","Buscar por Nombre", "Cancelar"};
    for (int i = 0; i < 3; i++){
        imprimirConNumero(i+1, listaMenu[i]);
    }
}

int seleccionarJuego(Juego juegos[], int n) {
    int opcionElegida = 0;
    int indiceEncontrado = -1;

    imprimirMenu();

    while (opcionElegida != -1) {
        int opcionElegida = -2;
        leerInputMenu(0, 3, opcionElegida);

        switch (opcionElegida) {
            case 0: {
                imprimirMenu();
                break;
            }
            case 1: {
                cout << "Ingrese el codigo: ";
                int cod;
                cin >> cod;
                ordenarPorCodigo(juegos, n);
                indiceEncontrado = buscarJuegoPorCodigoBinaria(juegos, n, cod);
                break;
            }

            case 2: {
                cout << "Ingrese el nombre (puede ser parcial): ";
                char nom[LARGO_NOMBRE];
                cin.ignore();
                cin.getline(nom, LARGO_NOMBRE);
                indiceEncontrado = buscarJuegoPorNombre(juegos, n, nom);
                break;
            }

            case 3:
                cout << "Cancelando seleccion...\n";
                return -1;
        }

        if (indiceEncontrado != -1) {
            cout << "\nJuego encontrado:\n";
            imprimirJuego(juegos[indiceEncontrado]);

            if (juegos[indiceEncontrado].operativo) {
                return indiceEncontrado;
            }

            cout << "\nEl juego se encuentra FUERA DE SERVICIO.\n";
        } else {
            cout << "\nJuego no encontrado.\n";
        }
    }

    return -1;
}