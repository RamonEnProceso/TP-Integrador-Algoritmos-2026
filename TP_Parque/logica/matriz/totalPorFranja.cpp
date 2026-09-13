#include "logica/matriz/totalPorFranja.h"
#include "structs/matrizJuegoxHoras.h"

void totalPorFranja(MatrizJuegoXHoras datos,int *vectorSumaFranjas){
    int total;
    for(int i = 0; i<datos.franjas;i++){
        total = 0;
        for(int j = 0; j<datos.juegos;j++){
            total += datos.matriz[j][i];
        }
        vectorSumaFranjas[i] = total;
    }
}
