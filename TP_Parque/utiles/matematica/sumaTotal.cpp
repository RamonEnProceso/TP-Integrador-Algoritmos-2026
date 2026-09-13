#include "utiles/matematica/sumaTotal.h"

int sumaTotalV(int vec[], int n){
    int total = 0;
    for (int i = 0; i<n;i++){
        total += vec[i];
    }
    return total;
}
