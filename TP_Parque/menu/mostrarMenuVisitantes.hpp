#ifndef MOSTRAR_MENU_VISITANTES_H
#define MOSTRAR_MENU_VISITANTES_H
#include "utiles/outputs/imprimirConNum.hpp"
#include "menu/mostrarMenuPrincipal.hpp"
#include <iostream>

using namespace std;

void mostrarMenuVisitantes(){
    int opcionElegida = 0;

    imprimirConNumero(1,"Mostrar Visitantes");
    imprimirConNumero(2,"Registrar Visitante");
    imprimirConNumero(3,"Buscar Visitante (Pulsera / Nombre)");
    imprimirConNumero(4,"Ver Historial de juegos de Visitante (Pulsera / Nombre)");
    imprimirConNumero(5,"Eliminar Visitante");
    imprimirConNumero(6,"Volver al Menú Principal");
    
    while (opcionElegida < 1 || opcionElegida > 6){
        cout << "Ingresa el numero de opcion elegida: "; cin >> opcionElegida; cout<<endl;
        if (opcionElegida < 1 || opcionElegida > 6){
            cout << "Numero incorrecto. Ingrese uno correcto.\n";
        }
    };

    switch (opcionElegida)
    {
    case 1:
        /* Mostrar Visitantes */
        break;
    case 2:
        /* Registrar Visitante */
        break;
    case 3:
        /* Buscar Visitante (Pulsera / Nombre) */
        break;    
    case 4:
        /* Ver Historial de juegos de Visitante (Pulsera / Nombre) */
        break;
    case 5:
        /* Eliminar Visitante */
        break;
    case 6:
        mostrarMenuPrincipal();
        break;
    }

    return;
};

#endif