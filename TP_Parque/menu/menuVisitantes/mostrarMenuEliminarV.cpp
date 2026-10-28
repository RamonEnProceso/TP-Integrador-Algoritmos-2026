#include "menu/menuVisitantes/mostrarMenuEliminarV.h"
#include "logica/nodo/eliminarVisitanteListaPorPulsera.h"
#include "logica/nodo/liberarVisitanteLista.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputMenu.h"
#include "constantes/generales.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Visitantes > Eliminar y liberar");
    const char listaMenu[3][LARGO_NOMBRE] = {"Eliminar un visitante", "Liberar todos los visitantes", "Volver al menu anterior"};
    for (size_t i = 0; i < 3; i++){
        imprimirConNumero(i+1, listaMenu[i]);
    }
}

void mostrarMenuEliminarV(NodoVisitante *&listaVisitantes){
    int opcionElegida = 0, numeroIngresado = 0;

    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida = -2; numeroIngresado = 0;

        leerInputMenu(0, 3, opcionElegida);

        switch (opcionElegida) {
            case 0:
                imprimirMenu();
                break;
            case 1:
                cout << "Ingrese el numero de pulsera del visitante que desea eliminar: ";
                cin >> numeroIngresado; cout << endl;
                listaVisitantes = eliminarVisitanteListaPorPulsera(listaVisitantes, numeroIngresado);
                break;
            case 2:
                listaVisitantes = liberarVisitanteLista(listaVisitantes);
                cout << "Liberando lista de visitantes...\n\n";
                opcionElegida = -1;
                break;
            case 3:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
