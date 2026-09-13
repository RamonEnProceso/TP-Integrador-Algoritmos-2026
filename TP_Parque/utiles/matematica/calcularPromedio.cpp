#include "utiles/matematica/calcularPromedio.h"
#include "utiles/matematica/sumaTotal.h"

int calcularPromedio(int vec[], int n){
    int total = sumaTotalV(vec, n);
    return total/n;
};
