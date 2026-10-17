#include "logica/archivo/buscarPorIndice.h"
#include "constantes/rutasArchivos.h"
#include <fstream>

using namespace std;



static int buscarBinariaIndice(const IndiceVisitante indice[], int cantidad, int pulsera) {
    int inicio = 0;
    int fin = cantidad - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (indice[medio].pulsera == pulsera) {
            return medio;
        } else if (indice[medio].pulsera < pulsera) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return -1;
}

bool buscarPorIndice(const IndiceVisitante indice[], int cantidad, int pulsera, Visitante &visitante) {
    int posIndice = buscarBinariaIndice(indice, cantidad, pulsera);
    if (posIndice == -1) {
        return false;
    }

    ifstream archivo(rutaArchivoVisitantes, ios::binary);
    if (!archivo) {
        return false;
    }


    VisitanteArchivo reg;
    archivo.seekg(indice[posIndice].posicion * sizeof(VisitanteArchivo), ios::beg);
    archivo.read((char*)&reg, sizeof(VisitanteArchivo));
    archivo.close();

    visitante.pulsera = reg.pulsera;
    for (int k = 0; k < LARGO_NOMBRE; k++) {
        visitante.nombre[k] = reg.nombre[k];
    }
    visitante.edad = reg.edad;
    visitante.altura = reg.altura;
    visitante.historial = nullptr;

    return true;
}
