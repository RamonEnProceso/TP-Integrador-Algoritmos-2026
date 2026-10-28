#include "menu/menuVisitantes/mostrarMenuHistorial.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputMenu.h"
#include "logica/pila/apilarVisitanteJuego.h"
#include "logica/pila/desapilarVisitanteJuego.h"
#include "logica/pila/obtenerHistorialVisitante.h"
#include "structs/datosParque.h"
#include "structs/nodoVisitante.h"
#include "constantes/generales.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Visitantes > Historial de juegos");
    char listaMenu[4][LARGO_NOMBRE] = {"Apilar juego visitado","Deshacer ultimo juego", "Ver historial","Volver al menu anterior"};
    for (size_t i = 0; i < 3; i++){
        imprimirConNumero(i+1, listaMenu[i]);
    }
}

void mostrarMenuHistorial(DatosParque &datos){
    int opcionElegida = 0, pulsera = 0;
    NodoVisitante *&listaVisitantes = datos.listaVisitantes;
    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida = -2; pulsera = 0;

        leerInputMenu(0, 4, opcionElegida);

        switch (opcionElegida) {
            case 0:
                imprimirMenu();
                break;
            case 1: {
                apilarVisitanteJuego(listaVisitantes, pulsera);
                break;
            }
            case 2: {
                desapilarVisitanteJuego(listaVisitantes, pulsera);
                break;
            }
            case 3: {
                obtenerHistorialVisitante(datos, pulsera);
                break;
            }
            case 4:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
