#include "menu/mostrarMenuPrincipal.h"
#include "menu/mostrarMenuJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "menu/mostrarMenuVisitantes.h"
#include "structs/datosParque.h"
#include "logica/generarPrueba/generarDatosPrueba.h"
#include <iostream>

using namespace std;

void mostrarMenuPrincipal(DatosParque &datos){
    int opcionElegida = 0;

    while (opcionElegida != -1)
    {
        opcionElegida = 0;
        imprimirTitulo("Menu Principal");
        imprimirConNumero(1,"Gestionar Visitantes");
        imprimirConNumero(2,"Gestionar Juegos");
        imprimirConNumero(3,"Generar Datos De Prueba");
        imprimirConNumero(4,"Salir del programa");

        while (opcionElegida < 1 || opcionElegida > 4){
            cout << "Ingresa el numero de opcion elegida: "; cin >> opcionElegida; cout<<endl;
            if (opcionElegida < 1 || opcionElegida > 4){
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        };


        switch (opcionElegida)
        {
        case 1:
            mostrarMenuVisitantes(datos.listaVisitantes);
            break;
        case 2:
            mostrarMenuJuegos(datos.juegos, datos.cantJuegos);
            break;
        case 3:
            generarDatosPrueba(datos.listaVisitantes);
            break;
        case 4:
            cout << "\nHasta luego ;)\n\n";
            opcionElegida = -1;
            break;
        }
    }

    return;
};
