
#include "menu/menuVisitantes/mostrarMenuArchivosVisitantes.h"
#include "logica/archivo/guardarVisitantes.h"
#include "logica/indice/construirIndice.h"
#include "logica/indice/buscarPorIndice.h"
#include "structs/visitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/outputs/imprimirVisitante.h"
#include "utiles/inputs/leerInputMenu.h"
#include "constantes/generales.h"
#include "logica/indice/mostrarIndice.h"
#include <iostream>
#include <fstream>

using namespace std;

static void imprimirMenu() {
    imprimirTitulo("Menu Principal > Visitantes > Archivos e indice");
    const char menuLista[4][LARGO_NOMBRE] = {"Guardar visitantes a archivo","Construir y mostrar indice","Buscar visitante por indice","Volver al menu anterior"};
    for (int i = 0; i < 4; i++) {
        imprimirConNumero(i + 1, menuLista[i]);}
}

static void construirArchivoIndice() {
    if (construirIndice()) {
        mostrarIndice();}
    else {
        cout << "No se pudo construir el indice.\n\n";}
}

static void buscarVisitantePorIndice() {
    int pulsera = 0;
    cout << "Ingrese el numero de pulsera a buscar (0 para terminar): ";
    if (!(cin >> pulsera)) { cin.clear(); cin.ignore(10000, '\n'); pulsera = 0; }

    while (pulsera != 0) {
        Visitante visitante;
        if (buscarPorIndice(pulsera, visitante)) {
            imprimirVisitante(visitante);}
        else {
            cout << "No se encontro un visitante con la pulsera " << pulsera << ".\n\n";}
        cout << "Ingrese el numero de pulsera a buscar (0 para terminar): ";
        if (!(cin >> pulsera)) { cin.clear(); cin.ignore(10000, '\n'); pulsera = 0; }
    }
    cout << "\n";
}

void mostrarMenuArchivosVisitantes(NodoVisitante*& listaVisitantes) {
    int opcionElegida = 0;
    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida = -2;
        leerInputMenu(0, 4, opcionElegida);
        switch (opcionElegida) {
            case 0:
                imprimirMenu();
                break;
            case 1:
                guardarVisitantes(listaVisitantes);
                break;
            case 2:
                construirArchivoIndice();
                break;
            case 3:
                buscarVisitantePorIndice();
                break;
            case 4:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
