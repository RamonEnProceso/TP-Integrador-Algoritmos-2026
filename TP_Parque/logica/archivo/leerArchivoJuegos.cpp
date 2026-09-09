#include "logica/archivo/leerArchivoJuegos.h"
#include "logica/archivo/rutasArchivos.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "structs/juego.h"
#include <fstream>
#include <iostream>

using namespace std;

int leerArchivoJuegos(){
    ifstream arch(rutaArchivoJuegos, ios::binary);
    if (!arch){cerr<<"Error al leer el archvio juegos.dat"; return 1;}

    Juego juegoLeido;

    imprimirTitulo("Lista de Juegos");
    while (arch.read((char*)&juegoLeido,sizeof(juegoLeido))){
        imprimirConNumero(juegoLeido.codigo,juegoLeido.nombre);
    }

    cout << "Fin de la lista de juegos.\n\n";

    arch.close();

    return 0;
}