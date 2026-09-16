#include <iostream>
#include "menu/seleccionarJuego.h"
#include "logica/vector/buscarJuegoPorCodigoBinaria.h"
#include "logica/texto/buscarJuegoPorNombre.h"
#include "logica/vector/ordenarPorCodigo.h"
#include "utiles/outputs/imprimirJuego.h"
#include "utiles/outputs/imprimirTitulo.h"

using namespace std;

int seleccionarJuego(Juego juegos[], int n) {
    imprimirTitulo("SELECCIONAR JUEGO");
    cout << "1. Buscar por Codigo\n";
    cout << "2. Buscar por Nombre\n";
    cout << "3. Cancelar\n";
    cout << "Opcion: ";
    
    int opcion;
    cin >> opcion;

    int indiceEncontrado = -1;

    if (opcion == 1) {
        cout << "Ingrese el codigo: ";
        int cod;
        cin >> cod;
        ordenarPorCodigo(juegos, n);
        indiceEncontrado = buscarJuegoPorCodigoBinaria(juegos, n, cod);
    } 
    else if (opcion == 2) {
        cout << "Ingrese el nombre (puede ser parcial): ";
        char nom[32];
        cin.ignore(); 
        cin.getline(nom, 32);
        indiceEncontrado = buscarJuegoPorNombre(juegos, n, nom);
    } 
    else {
        return -1;
    }

    if (indiceEncontrado != -1) {
        cout << "\nJuego encontrado:\n";
        imprimirJuego(juegos[indiceEncontrado]); 

        if (juegos[indiceEncontrado].operativo) {
            return indiceEncontrado;
        } else {
            cout << "\nEl juego se encuentra FUERA DE SERVICIO.\n";
            return -1;
        }
    } else {
        cout << "\nJuego no encontrado.\n";
        return -1;
    }
}
