#include "menu/menuVisitantes/mostrarMenuEliminarLiberar.h"
#include "logica/nodo/eliminarVisitanteListaPorPulsera.h"
#include "logica/nodo/liberarVisitanteLista.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Visitantes > Eliminar y liberar");
    imprimirConNumero(1, "Eliminar visitante");
    imprimirConNumero(2, "Liberar visitantes");
    imprimirConNumero(3, "Volver al menu anterior");
}

void mostrarMenuEliminarLiberar(NodoVisitante *&listaVisitantes){
    int opcionElegida = 0, numeroIngresado = 0;

    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida = -2; numeroIngresado = 0;

        while (opcionElegida < 0 || opcionElegida > 3) {
            cout << "Ingresa un numero (0 para imprimir menu): ";
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 0 || opcionElegida > 3) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

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
