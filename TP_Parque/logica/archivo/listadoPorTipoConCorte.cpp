#include "logica/archivo/listadoPorTipoConCorte.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "structs/juego.h"
#include "constantes/matrizConstantes.h"

#include <iostream>

using namespace std;

void listadoPorTipoConCorte() {

    const char* tiposJuegos[3] = {
        "Mecanico",
        "Acuatico",
        "Infantil"
    };

    Juego juegos[MAX_JUEGOS];

    int cantidad = leerArchivoJuegos(juegos, MAX_JUEGOS);

    if (cantidad == 0) {
        return;
    }

    int tipoActual = juegos[0].tipo;
    int subtotal = 0;
    int totalGeneral = 0;

    cout << "\n========== LISTADO DE JUEGOS POR TIPO ==========\n";

    for (int i = 0; i < cantidad; i++) {

        if (juegos[i].tipo != tipoActual) {

            cout << "Subtotal de accesos: " << subtotal << "\n";

            totalGeneral += subtotal;
            subtotal = 0;

            tipoActual = juegos[i].tipo;

            cout << "\nTIPO: " << tiposJuegos[tipoActual] << "\n";
        }

        if (i == 0 || juegos[i].tipo != juegos[i - 1].tipo) {
            if (i == 0) {
                cout << "\nTIPO: " << tiposJuegos[tipoActual] << "\n";
            }
        }

        cout << " - " << juegos[i].nombre << "\n";

        for (int j = 0; j < FRANJAS_HORARIAS; j++) {
            subtotal += juegos[i].franjas[j];
        }
    }

    cout << "Subtotal de accesos: " << subtotal << "\n";

    totalGeneral += subtotal;

    cout << "\nTOTAL GENERAL: " << totalGeneral << "\n";

    cout << "\n===============================================\n";
}