#include "menu/mostrarMenuJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/outputs/imprimirJuego.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "menu/menuJuegos/mostrarMenuListaJuegos.h"
#include "menu/menuJuegos/mostrarMenuOrdenarJuegos.h"
#include "menu/menuJuegos/mostrarMenuBuscarJuegos.h"
#include "menu/menuJuegos/mostrarMenuArchivosJuegos.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarMenuJuegos(Juego *listaJuegos, int cantJuegos) {
    int opcionElegida = 0;
    
    int cantidad = leerArchivoJuegos(listaJuegos, cantJuegos);

    if (cantidad == 0) {
        cout << "No hay juegos cargados. Genera los datos de prueba desde el Menu Principal.\n\n";
        return;
    }

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Menu Juegos");
        imprimirConNumero(1, "Mostrar juegos");
        imprimirConNumero(2, "Ordenar Juegos");
        imprimirConNumero(3, "Buscar Juego");
        imprimirConNumero(4, "Administrar archivos de juegos");
        imprimirConNumero(5, "Volver al Menu Principal");

        while (opcionElegida < 1 || opcionElegida > 5) {
            cout << "Ingresa el numero de opcion elegida: "; 
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 5) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {

            case 1:
                mostrarMenuListaJuegos(listaJuegos, cantJuegos);
                break;
            case 2:
                mostrarMenuOrdenarJuegos(listaJuegos, cantJuegos);
                break;
            case 3: {
                mostrarMenuBuscarJuegos(listaJuegos, cantJuegos);
                break;
            }
            case 4: {
                mostrarMenuArchivosJuegos(listaJuegos, cantJuegos);
                break;
            }
            case 5:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
