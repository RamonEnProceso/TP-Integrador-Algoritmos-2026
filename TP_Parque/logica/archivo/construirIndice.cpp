#include "logica/archivo/construirIndice.h"
#include "constantes/rutasArchivos.h"
#include "structs/visitante.h"
#include <fstream>
#include <iostream>

using namespace std;


static void ordenarIndicePorPulsera(IndiceVisitante indice[], int cantidad) {
    bool huboCambios = true;
    for (int i = 0; i < cantidad - 1 && huboCambios; i++) {
        huboCambios = false;
        for (int j = 0; j < cantidad - 1 - i; j++) {
            if (indice[j].pulsera > indice[j + 1].pulsera) {
                IndiceVisitante aux = indice[j];
                indice[j] = indice[j + 1];
                indice[j + 1] = aux;
                huboCambios = true;
            }
        }
    }
}

void construirIndice(IndiceVisitante*& indice, int &cantidad) {


    ifstream archivo(rutaArchivoVisitantes, ios::binary | ios::ate);
    if (!archivo) {
        indice = nullptr;
        cantidad = 0;
        cerr << "No se pudo abrir visitantes.dat. Genera los datos y guarda los visitantes primero.\n\n";
        return;
    }


    cantidad = (int)(archivo.tellg() / sizeof(VisitanteArchivo));
    archivo.seekg(0);


    indice = new IndiceVisitante[cantidad];

    VisitanteArchivo reg;
    for (int i = 0; i < cantidad; i++) {
        archivo.read((char*)&reg, sizeof(VisitanteArchivo));
        indice[i].pulsera = reg.pulsera;
        indice[i].posicion = i;
    }

    archivo.close();


    ordenarIndicePorPulsera(indice, cantidad);
}
