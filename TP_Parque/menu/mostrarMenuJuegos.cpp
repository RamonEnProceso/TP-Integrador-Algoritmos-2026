#include "menu/mostrarMenuJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "menu/menuJuegos/mostrarMenuListaJuegos.h"
#include "menu/menuJuegos/mostrarMenuOrdenarJuegos.h"
#include "menu/menuJuegos/mostrarMenuBuscarJuegos.h"
#include "menu/menuJuegos/mostrarMenuArchivosJuegos.h"
#include "constantes/matrizConstantes.h"
#include "utiles/inputs/leerInputMenu.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Juegos");
    imprimirConNumero(1, "Mostrar juegos");
    imprimirConNumero(2, "Ordenar Juegos");
    imprimirConNumero(3, "Buscar Juego");
    imprimirConNumero(4, "Administrar archivos de juegos");
    imprimirConNumero(5, "Volver al Menu Principal");
    return;
}

void mostrarMenuJuegos(Juego *listaJuegos) {
    int opcionElegida = 0;

    int cantidad = leerArchivoJuegos(listaJuegos, MAX_JUEGOS);

    if (cantidad == 0) {
        cout << "No hay juegos cargados. Genera los datos de prueba desde el Menu Principal.\n\n";
        return;
    }

    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida = -2;;

        leerInputMenu(0, 5, opcionElegida);

        switch (opcionElegida) {

            case 0:
                imprimirMenu();
                break;
            case 1:
                mostrarMenuListaJuegos(listaJuegos, cantidad);
                break;
            case 2:
                mostrarMenuOrdenarJuegos(listaJuegos, cantidad);
                break;
            case 3: {
                mostrarMenuBuscarJuegos(listaJuegos, cantidad);
                break;
            }
            case 4: {
                mostrarMenuArchivosJuegos(listaJuegos, cantidad);
                break;
            }
            case 5:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
