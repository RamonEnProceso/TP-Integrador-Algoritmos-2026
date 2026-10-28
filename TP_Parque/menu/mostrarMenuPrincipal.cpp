#include "menu/mostrarMenuPrincipal.h"
#include "menu/mostrarMenuFilas.h"
#include "menu/mostrarMenuJuegos.h"
#include "menu/mostrarMenuVisitantes.h"
#include "menu/mostrarMenuOcupacion.h"
#include "menu/mostrarMenuHerramientas.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "structs/datosParque.h"
#include "utiles/inputs/leerInputMenu.h"
#include "constantes/generales.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal");
    char listaMenu[6][LARGO_NOMBRE] = {"Visitantes","Juegos","Ocupacion","Fila de Espera","Herramientas","Salir"};
    for (int i = 0; i < 6; i++){
        imprimirConNumero(i+1,listaMenu[i]);
    }
    return;
}

void mostrarMenuPrincipal(DatosParque &datos){
    int opcionElegida = 0;

    imprimirMenu();

    while (opcionElegida != -1)
    {
        opcionElegida = -2;

        leerInputMenu(0, 6, opcionElegida);

        switch (opcionElegida)
        {
        case 0:
            imprimirMenu();
            break;
        case 1:
            mostrarMenuVisitantes(datos);
            break;
        case 2:
            mostrarMenuJuegos(datos.juegos);
            break;
        case 3:
            mostrarMenuOcupacion(datos);
            break;
        case 4:
            mostrarMenuFilas(datos);
            break;
        case 5:
            mostrarMenuHerramientas(datos);
            break;
        case 6:
            cout << "\nHasta luego ;)\n\n";
            opcionElegida = -1;
            break;
        }
    }

    return;
};
