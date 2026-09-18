#include "matriz/reconstruirMatriz.h"

void reconstruirMatriz(DatosParque &datos) {
    datos.datosMatriz.juegos = datos.cantJuegos;
    datos.datosMatriz.franjas = FRANJAS_HORARIAS;
    for (int i = 0; i < datos.cantJuegos; i++){
        datos.datosMatriz.matriz[i] = datos.juegos[i].franjas;}
}