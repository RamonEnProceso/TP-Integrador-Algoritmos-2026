
#include "logica/indice/construirIndice.h"
#include "constantes/rutasArchivos.h"
#include "constantes/visitantes.h"
#include "structs/visitante.h"
#include <fstream>
#include <iostream>

using namespace std;

bool construirIndice() {

    ifstream archivo(rutaArchivoVisitantes, ios::binary);
    if (!archivo) {cerr << "No se pudo abrir visitantes.dat.\n\n";return false;}

    ofstream archivoIndice(rutaArchivoIndice,ios::binary | ios::trunc);
    if (!archivoIndice) {cerr << "No se pudo crear pulseras.idx.\n\n";archivo.close();return false;}

    int vacio = -1;

    for (int k = 0; k < MAX_PULSERAS; k++) {
        archivoIndice.write((char*)&vacio,sizeof(int));}

    if (!archivoIndice) {
        cerr << "Error al inicializar el indice.\n\n";
        archivo.close();archivoIndice.close();return false;
    }

    VisitanteArchivo reg;
    int posicion = 0;

    while (archivo.read((char*)&reg,sizeof(VisitanteArchivo))) {
        // Verificar que la pulsera sea válida.
        if (reg.pulsera < 1 || reg.pulsera > MAX_PULSERAS) {
            cerr << "Numero de pulsera fuera de rango.\n\n";
            archivo.close();archivoIndice.close();return false;
        }

        int fila = reg.pulsera - 1;
        archivoIndice.seekp(fila * sizeof(int),ios::beg);
        archivoIndice.write((char*)&posicion,sizeof(int));

        if (!archivoIndice) {
            cerr << "Error al escribir en pulseras.idx.\n\n";
            archivo.close();archivoIndice.close();return false;
        }

        posicion++;
    }

    archivo.close();archivoIndice.close();

    cout << "Indice construido correctamente.\n";
    cout << "Visitantes indexados: " << posicion << "\n\n";

    return true;
}
