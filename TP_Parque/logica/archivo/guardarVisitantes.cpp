#include "logica/archivo/guardarVisitantes.h"
#include "constantes/rutasArchivos.h"
#include <fstream>
#include <iostream>

using namespace std;

void guardarVisitantes(NodoVisitante *lista) {
    ofstream archivo(rutaArchivoVisitantes, ios::binary);
    if (!archivo) {
        cerr << "No se pudo crear visitantes.dat.\n";
        return;
    }


    NodoVisitante *actual = lista;
    int cantidad = 0;
    while (actual != nullptr) {
        VisitanteArchivo reg;
        reg.pulsera = actual->visitante.pulsera;
        for (int k = 0; k < LARGO_NOMBRE; k++) {
            reg.nombre[k] = actual->visitante.nombre[k];
        }
        reg.edad = actual->visitante.edad;
        reg.altura = actual->visitante.altura;
        archivo.write((char*)&reg, sizeof(VisitanteArchivo));
        cantidad++;
        actual = actual->siguiente;
    }

    archivo.close();
    cout << "Se guardaron " << cantidad << " visitantes en visitantes.dat.\n\n";
}
