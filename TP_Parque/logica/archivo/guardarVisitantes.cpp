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
        archivo.write((char*)&actual->visitante, sizeof(Visitante));
        cantidad++;
        actual = actual->siguiente;
    }

    archivo.close();
    cout << "Se guardaron " << cantidad << " visitantes en visitantes.dat.\n\n";
}
