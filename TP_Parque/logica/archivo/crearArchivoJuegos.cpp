#include "logica/archivo/crearArchivoJuegos.h"
#include "constantes/rutasArchivos.h"
#include "structs/juego.h"
#include <fstream>
#include <iostream>

using namespace std;

int crearArchivoJuegos(Juego juegos[], int n){
    ofstream arch(rutaArchivoJuegos, ios::binary);
    if (!arch){cerr<<"Error al crear el archvio juegos.dat"; return 1;}

    for (int i = 0; i < n; i++){
        arch.write((char*)&juegos[i],sizeof(juegos[i]));
    }

    arch.close();

    return 0;
}
