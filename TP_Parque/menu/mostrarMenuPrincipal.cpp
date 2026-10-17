#include "menu/mostrarMenuPrincipal.h"
#include "menu/mostrarMenuFilas.h"
#include "menu/mostrarMenuJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "menu/mostrarMenuVisitantes.h"
#include "menu/mostrarMenuOcupacion.h"
#include "structs/datosParque.h"
#include "logica/generarPrueba/generarDatosPrueba.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal");
    imprimirConNumero(1,"Gestionar Visitantes");
    imprimirConNumero(2,"Gestionar Juegos");
    imprimirConNumero(3,"Gestionar Ocupacion de juegos");
    imprimirConNumero(4,"Generar Datos De Prueba");
    imprimirConNumero(5,"Salir del programa");
    return;
}

void mostrarMenuPrincipal(DatosParque &datos){
    int opcionElegida = 0;

    imprimirMenu();

    while (opcionElegida != -1)
    {
        opcionElegida = 0;

        while (opcionElegida < 1 || opcionElegida > 6){
            cout << "Ingresa el numero de opcion elegida: "; cin >> opcionElegida; cout<<endl;
            if (opcionElegida < 1 || opcionElegida > 6){
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
            generarDatosPrueba(datos);
            break;
        case 6:
            cout << "\nHasta luego ;)\n\n";
            opcionElegida = -1;
            break;
        }
    }

    return;
};

