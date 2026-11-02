#include "menu/menuVisitantes/mostrarMenuArchivosVisitantes.h"
#include "logica/archivo/guardarVisitantes.h"
#include "logica/archivo/construirIndice.h"
#include "logica/archivo/buscarPorIndice.h"
#include "structs/indiceVisitante.h"
#include "structs/visitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/outputs/imprimirVisitante.h"
#include "utiles/inputs/leerInputMenu.h"
#include "constantes/generales.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Visitantes > Archivos e indice");
    const char menuLista [4][LARGO_NOMBRE] = {"Guardar visitantes a archivo","Construir y mostrar indice","Buscar visitante por indice","Volver al menu anterior"};
    for (int i = 0; i < 4; i++)
    {
        imprimirConNumero(i+1,menuLista[i]);
    }
}

static void construirArchivoIndice(){
    IndiceVisitante *indice = nullptr;
    int cant = 0;
    construirIndice(indice, cant);
    if (indice != nullptr && cant > 0) {
        imprimirTitulo("Indice de visitantes");
        for (int i = 0; i < cant; i++) {
            cout << "Pulsera " << indice[i].pulsera << " -> posicion " << indice[i].posicion << "\n";
        }
        cout << "\n";
        delete[] indice;
    } else {
        cout << "No hay visitantes para indexar. Guarda los visitantes primero.\n\n";
    }
    return;
}

static void buscarVisitantePorIndice(){
    IndiceVisitante *indice = nullptr;
    int cant = 0;
    construirIndice(indice, cant);
    if (indice == nullptr || cant == 0) {
        cout << "No hay visitantes para indexar. Guarda los visitantes primero.\n\n";
        return;
    }
    int pulsera = 0;
    cout << "Ingrese el numero de pulsera a buscar (0 para terminar): ";
    cin >> pulsera; cout << endl;
    while (pulsera != 0) {
        Visitante visitante;
        if (buscarPorIndice(indice, cant, pulsera, visitante)) {
            imprimirVisitante(visitante);
        } else {
            cout << "No se encontro un visitante con la pulsera " << pulsera << ".\n\n";
        }
        cout << "Ingrese el numero de pulsera a buscar (0 para terminar): ";
        cin >> pulsera; cout << endl;
    }
    delete[] indice;
    return;
}

void mostrarMenuArchivosVisitantes(NodoVisitante *&listaVisitantes){
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
            case 3: {
                buscarVisitantePorIndice();
                break;
            }
            case 4:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
