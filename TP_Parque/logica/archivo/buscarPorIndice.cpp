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


    archivo.seekg(indice[posIndice].posicion * sizeof(Visitante), ios::beg);
    archivo.read((char*)&visitante, sizeof(Visitante));
    archivo.close();

    return true;
}
