#include "logica/matriz/devolverMayorOcupacion.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "structs/mayorOcupacion.h"
#include <iostream>

using namespace std;

MayorOcupacion devolverMayorOcupacion(MatrizJuegoXHoras datosMatriz){

    int mayor = -1;
    int juegoMasUsado = -1;
    int franjaMasConcurrida = -1;

    for (int i = 0; i < datosMatriz.juegos; i++)
    {
        for (int j = 0; j < datosMatriz.franjas; j++)
        {
            if (datosMatriz.matriz[i][j] > mayor){
                mayor = datosMatriz.matriz[i][j];
                juegoMasUsado = i;
                franjaMasConcurrida = j;
            }
        }
        
    }
    return {mayor, juegoMasUsado, franjaMasConcurrida};   
}