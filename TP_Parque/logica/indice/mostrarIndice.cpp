#include "logica/indice/mostrarIndice.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "constantes/rutasArchivos.h"
#include "constantes/visitantes.h"
#include <iostream>
#include <fstream>

using namespace std;

void mostrarIndice() {
    ifstream archivoIndice(rutaArchivoIndice, ios::binary);
    if (!archivoIndice) {
        cout << "No se pudo abrir pulseras.idx.\n\n";return;}

    imprimirTitulo("Indice de visitantes");
    int posicion;

    for (int i = 0; i < MAX_PULSERAS; i++) {
        archivoIndice.read((char*)&posicion,sizeof(int));

        if (!archivoIndice) {
            cout << "Error al leer el indice.\n\n";
            archivoIndice.close();return;}

        if (posicion != -1) {
            cout << "Pulsera " << i + 1 << " -> posicion " << posicion << "\n";}
    }

    cout << "\n";
    archivoIndice.close();
}