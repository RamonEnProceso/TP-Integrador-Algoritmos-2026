#include "logica/archivo/leerArchivoJuegos.h"
#include "constantes/rutasArchivos.h"
#include <fstream>
#include <iostream>

using namespace std;

int leerArchivoJuegos(Juego juegos[], int n) {
    ifstream arch(rutaArchivoJuegos, ios::binary);
    if (!arch) {
        cerr<<"Error al leer archivo de Juegos.";
        return 0; 
    }

    Juego juegoLeido;
    int cantidad = 0;

    while (cantidad < n && arch.read((char*)&juegoLeido, sizeof(juegoLeido))) {
        juegos[cantidad] = juegoLeido;
        cantidad++;
    }

    if (cantidad == 0){
        cout<<"No se encontraron juegos guardados";
    }

    arch.close();
    return cantidad; 
}
