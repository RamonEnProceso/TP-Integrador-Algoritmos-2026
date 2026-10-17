#include "logica/archivo/cambiarEstadoJuegoN.h"
#include "constantes/rutasArchivos.h"
#include "structs/juego.h"
#include <fstream>

using namespace std;

bool cambiarEstadoJuegoN(int n, bool nuevoEstado) {
    if (n <= 0) {
        return false;
    }



    fstream archivo(rutaArchivoJuegos, ios::binary | ios::in | ios::out);
    if (!archivo) {
        return false;
    }

    Juego juego;


    archivo.seekg((n - 1) * sizeof(Juego), ios::beg);
    if (!archivo.read((char*)&juego, sizeof(Juego))) {
        archivo.close();
        return false;
    }

    juego.operativo = nuevoEstado;



    archivo.seekp((n - 1) * sizeof(Juego), ios::beg);
    archivo.write((char*)&juego, sizeof(Juego));

    archivo.close();
    return true;
}
