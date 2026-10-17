#include "logica/archivo/consultarJuegoN.h"
#include "constantes/rutasArchivos.h"
#include "structs/juego.h"

#include <fstream>

using namespace std;

bool consultarJuegoN(int n, Juego& juego) {

    ifstream archivo(rutaArchivoJuegos, ios::binary);

    if (!archivo || n <= 0) {
        return false;
    }

    archivo.seekg((n - 1) * sizeof(Juego), ios::beg);

    if (!archivo.read((char*)&juego, sizeof(Juego))) {
        archivo.close();
        return false;
    }

    archivo.close();

    return true;
}