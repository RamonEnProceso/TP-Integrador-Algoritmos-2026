
#include "logica/archivo/guardarVisitantes.h"
#include "constantes/rutasArchivos.h"
#include "utiles/copiarTexto.h"
#include <fstream>
#include <iostream>

using namespace std;

void guardarVisitantes(NodoVisitante* lista) {

    ofstream archivo(rutaArchivoVisitantes, ios::binary | ios::trunc);
    if (!archivo) {cerr << "No se pudo crear visitantes.dat.\n"; return;}

    NodoVisitante* actual = lista;
    int cantidad = 0;

    while (actual != nullptr) {
        VisitanteArchivo reg{};
        reg.pulsera = actual->visitante.pulsera;
        copiarTexto(actual->visitante.nombre, reg.nombre);
        reg.edad = actual->visitante.edad;
        reg.altura = actual->visitante.altura;

        archivo.write((char*)&reg,sizeof(VisitanteArchivo));
        cantidad++;
        actual = actual->siguiente;
    }

    archivo.close();

    ofstream archivoIndice(rutaArchivoIndice, ios::binary | ios::trunc);
    if (!archivoIndice) { cerr << "No se pudo invalidar pulseras.idx.\n";return;}
    
    archivoIndice.close();

    cout << "Se guardaron " << cantidad << " visitantes en visitantes.dat.\n";
    cout << "Debe generarse nuevamente el indice.\n\n";
}
