#include "logica/matriz/devolverJuegoMasUsado.h"
#include "logica/matriz/totalPorJuego.h"
#include "logica/vector/devolverMayorPosV.h"

int devolverMasUsado(MatrizJuegoXHoras datosMatriz){
    int* totalJuegos = new int[datosMatriz.juegos];
    totalPorJuego(datosMatriz, totalJuegos);
    int mayorPos = devolverMayorPosV(totalJuegos, datosMatriz.juegos);
    delete[] totalJuegos;
    return mayorPos;
}
