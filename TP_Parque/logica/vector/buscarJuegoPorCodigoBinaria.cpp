#include "logica/vector/buscarJuegoPorCodigoBinaria.h"

int buscarJuegoPorCodigoBinaria(Juego juegos[], int n, int codigoBuscado) {
    int inicio = 0;
    int fin = n - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (juegos[medio].codigo == codigoBuscado) {
            return medio; 
        } else if (juegos[medio].codigo < codigoBuscado) {
            inicio = medio + 1; 
        } else {
            fin = medio - 1;    
        }
    }
    return -1; 
}
