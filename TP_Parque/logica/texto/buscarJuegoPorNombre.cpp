#include "logica/texto/buscarJuegoPorNombre.h"
#include <cstring>
#include <cctype>

int buscarJuegoPorNombre(Juego juegos[], int n, const char nombreBuscado[]) {
    char buscadoMin[32];
    int i = 0;
    while (nombreBuscado[i] != '\0' && i < 31) {
        buscadoMin[i] = tolower(nombreBuscado[i]);
        i++;
    }
    buscadoMin[i] = '\0';

    for (int j = 0; j < n; j++) {
        char nombreJuegoMin[32];
        int k = 0;
        while (juegos[j].nombre[k] != '\0' && k < 31) {
            nombreJuegoMin[k] = tolower(juegos[j].nombre[k]);
            k++;
        }
        nombreJuegoMin[k] = '\0';

        if (strstr(nombreJuegoMin, buscadoMin) != NULL) {
            return j; 
        }
    }
    return -1; 
}
