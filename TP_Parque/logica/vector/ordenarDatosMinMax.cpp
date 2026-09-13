#include "utiles/swap.h"

void ordenarDatosMinMax(char **nombres, int *datos, int tamaño){
    bool huboCambios = true;
    for (int i = 0; i < tamaño-1 && huboCambios ;i++){
        huboCambios = false;
        for (int j = 0; j < tamaño - i-1; j++){
            if (datos[j] > datos[j+1]){
                swapInt(&datos[j], &datos[j+1]);
                swapString(&nombres[j], &nombres[j+1]);
                huboCambios = true;
            }
        }
    }
}
