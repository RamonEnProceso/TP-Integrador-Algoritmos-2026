#include "menu/mostrarMenuPrincipal.h"
#include "menu/mostrarMenuFilas.h"
#include "menu/mostrarMenuJuegos.h"
#include "menu/mostrarMenuVisitantes.h"
#include "menu/mostrarMenuOcupacion.h"
#include "menu/mostrarMenuHerramientas.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "structs/datosParque.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal");
    imprimirConNumero(1,"Visitantes");
    imprimirConNumero(2,"Juegos");
    imprimirConNumero(3,"Ocupacion");
    imprimirConNumero(4,"Filas de espera");
    imprimirConNumero(5,"Herramientas");
    imprimirConNumero(6,"Salir");
    return;
}

void mostrarMenuPrincipal(DatosParque &datos){
    int opcionElegida = 0;

    imprimirMenu();

    while (opcionElegida != -1)
    {
        opcionElegida = -2;

        while (opcionElegida < 0 || opcionElegida > 6){
            cout << "Ingresa un numero (0 para imprimir menu): "; cin >> opcionElegida; cout<<endl;
            if (opcionElegida < 0 || opcionElegida > 6){
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        };

        switch (opcionElegida)
        {
        case 0:
            imprimirMenu();
            break;
        case 1:
            mostrarMenuVisitantes(datos.listaVisitantes);
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
