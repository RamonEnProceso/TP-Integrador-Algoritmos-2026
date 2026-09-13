#include "logica/matriz/totalPorJuego.h"
#include "structs/matrizJuegoxHoras.h"

void totalPorJuego(MatrizJuegoXHoras datos,int *vectorSumaJuego){
    int total;
    for(int i = 0; i<datos.juegos;i++){
        total = 0;
        for(int j = 0; j<datos.franjas;j++){
            total += datos.matriz[i][j];
        }
        vectorSumaJuego[i] = total;
    }
}
