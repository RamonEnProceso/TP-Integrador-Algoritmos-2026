#include "utiles/matematica/calcularPromedio.h"

int calcularPromedio(int vec[], int n){
    int sumaTotal = 0;
    for (int i = 0; i<n;i++){
        sumaTotal += vec[i];
    }
    return sumaTotal/n;
};