#include "menu/menuJuegos/mostrarMenuArchivosJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "logica/archivo/crearArchivoJuegos.h"
#include "logica/archivo/consultarJuegoN.h"
#include "logica/archivo/cambiarEstadoJuegoN.h"
#include "logica/archivo/listadoPorTipoConCorte.h"
#include "logica/archivo/actualizarJuegosConNovedades.h"
#include "utiles/outputs/imprimirJuego.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarMenuArchivosJuegos(Juego *listaJuegos, int cantJuegos) {
    int opcionElegida = 0;

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Administrar archivos de juegos");
        imprimirConNumero(1, "Cargar juegos desde archivos");
        imprimirConNumero(2, "Guardar juegos a archivos");
        imprimirConNumero(3, "Consultar juego N");
        imprimirConNumero(4, "Cambiar estado del juego N");
        imprimirConNumero(5, "Listado por tipo con corte de control");
        imprimirConNumero(6, "Actualizar juegos con novedades");
        imprimirConNumero(7, "Volver al Menu de Juegos");

        while (opcionElegida < 1 || opcionElegida > 7) {
            cout << "Ingresa el numero de opcion elegida: ";
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 7) {
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
            case 3: {
                int n = 0;
                cout << "Ingrese el numero de juego a consultar (N): ";
                cin >> n; cout << endl;
                Juego juego;
                if (consultarJuegoN(n, juego)) {
                    imprimirJuego(juego);
                } else {
                    cout << "No se encontro un juego en la posicion " << n << ".\n\n";
                }
                break;
            }
            case 4: {
                int n = 0, estado = 0;
                cout << "Ingrese el numero de juego a modificar (N): ";
                cin >> n; cout << endl;
                cout << "Nuevo estado (1: operativo / 0: fuera de servicio): ";
                cin >> estado; cout << endl;
                if (cambiarEstadoJuegoN(n, estado == 1)) {
                    cout << "Estado actualizado correctamente.\n\n";
                } else {
                    cout << "No se pudo actualizar el juego en la posicion " << n << ".\n\n";
                }
                break;
            }
            case 5:
                listadoPorTipoConCorte();
                break;
            case 6:
                actualizarJuegosConNovedades();
                break;
            case 7:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
