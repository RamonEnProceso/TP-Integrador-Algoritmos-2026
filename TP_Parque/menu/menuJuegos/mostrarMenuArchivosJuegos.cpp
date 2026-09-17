#include "menu/menuJuegos/mostrarMenuArchivosJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "logica/archivo/crearArchivoJuegos.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarMenuListaJuegos(Juego *listaJuegos, int cantJuegos) {
    int opcionElegida = 0;

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Administrar archivos de juegos");
        imprimirConNumero(1, "Cargar juegos desde archivos");
        imprimirConNumero(2, "Guardar juegos a archivos");
        imprimirConNumero(3, "Volver al Menu de Juegos");

        while (opcionElegida < 1 || opcionElegida > 3) {
            cout << "Ingresa el numero de opcion elegida: "; 
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 3) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {
            case 1:
                leerArchivoJuegos(listaJuegos,cantJuegos);
                break;
            case 2:
                crearArchivoJuegos(listaJuegos,cantJuegos);
                break;
            case 3:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}