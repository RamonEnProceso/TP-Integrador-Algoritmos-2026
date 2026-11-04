#include "menu/menuJuegos/mostrarMenuListaJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/vector/mostrarListaJuegos.h"
#include "utiles/inputs/leerInputMenu.h"
#include "constantes/generales.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Juegos > Mostrar");
    char listaMenu[3][LARGO_NOMBRE] = {"Completa","Solo disponibles", "Volver al Menu de Juegos"};
    for (int i = 0; i < 3; i++){
        imprimirConNumero(i+1, listaMenu[i]);
    }
}

void mostrarMenuListaJuegos(Juego *listaJuegos, int cantJuegos) {
    int opcionElegida = 0;
    imprimirMenu();
    while (opcionElegida != -1) {
        opcionElegida  = -2;
        leerInputMenu(0,3,opcionElegida);
        switch (opcionElegida) {
            case 0:
                imprimirMenu();
                break;
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