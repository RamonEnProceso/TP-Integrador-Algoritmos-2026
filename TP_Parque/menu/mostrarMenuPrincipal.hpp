#ifndef MOSTRAR_MENU_H
#define MOSTRAR_MENU_H
#include "utiles/outputs/imprimirConNum.hpp"
#include <iostream>

using namespace std;

void mostrarMenuPrincipal(){
    int opcionElegida = 0;

    imprimirConNumero(1,"Gestionar Visitantes");
    imprimirConNumero(2,"Gestionar Juegos");
    imprimirConNumero(3,"Generar Datos De Prueba");
    
    while (opcionElegida < 1 || opcionElegida > 3){
        cout << "Ingresa el numero de opcion elegida: "; cin >> opcionElegida; cout<<endl;
        if (opcionElegida < 1 || opcionElegida > 3){
            cout << "Numero incorrecto. Ingrese uno correcto.\n";
        }
    };

    return;
};

#endif