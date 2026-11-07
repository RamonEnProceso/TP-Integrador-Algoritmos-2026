#include "menu/mostrarMenuJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "menu/menuJuegos/mostrarMenuListaJuegos.h"
#include "menu/menuJuegos/mostrarMenuOrdenarJuegos.h"
#include "menu/menuJuegos/mostrarMenuBuscarJuegos.h"
#include "menu/menuJuegos/mostrarMenuArchivosJuegos.h"
#include "utiles/inputs/leerInputMenu.h"
#include "constantes/generales.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Juegos");
    char listaMenu[5][LARGO_NOMBRE] = {"Mostrar juegos", "Ordenar Juegos", "Buscar Juego", "Administrar archivos de juegos", "Volver al Menu Principal"};
    for (int i = 0; i < 5; i++){
        imprimirConNumero(i+1, listaMenu[i]);}
    return;
}

void mostrarMenuJuegos(Juego *listaJuegos, int &cantidad, Cola *filas) {
    int opcionElegida = 0;

    if (cantidad == 0) {
        cantidad = leerArchivoJuegos(listaJuegos);
    }

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
                mostrarMenuOrdenarJuegos(listaJuegos, cantidad, filas);
                break;
            case 3: {
                mostrarMenuBuscarJuegos(listaJuegos, cantidad, filas);
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
