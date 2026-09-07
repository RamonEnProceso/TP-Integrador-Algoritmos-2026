#ifndef MOSTRAR_MENU_H
#define MOSTRAR_MENU_H
#include "utiles/outputs/imprimirConNum.hpp"
#include "menu/mostrarMenuVisitantes.hpp"
#include <iostream>

using namespace std;

void mostrarMenuPrincipal(){
    int opcionElegida = 0;

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
        mostrarMenuVisitantes();
        break;
    case 2:
        /* Menu Juegos */
        break;
    case 3:
        /* Generar Datos de Prueba */
        break;
    case 4:
        cout << "\n¡Hasta luego! ;)\n";
        break;
    }

    return;
};

#endif