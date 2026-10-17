#include "logica/texto/buscarJuegoPorNombre.h"
#include "constantes/generales.h"

char aMinuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

bool contieneSubtexto(const char* texto, const char* subtexto) {
    int i = 0;
    while (texto[i] != '\0') {
        int j = 0;
        while (subtexto[j] != '\0' && texto[i + j] != '\0' && texto[i + j] == subtexto[j]) {
            j++;
        }
        if (subtexto[j] == '\0') {
            return true;
        }
        i++;
    }
    return false;
}

int buscarJuegoPorNombre(Juego juegos[], int n, const char nombreBuscado[]) {
    char buscadoMin[LARGO_NOMBRE];
    int i = 0;
    while (nombreBuscado[i] != '\0' && i < LARGO_NOMBRE - 1) {
        buscadoMin[i] = aMinuscula(nombreBuscado[i]);
        i++;
    }
    buscadoMin[i] = '\0';

    for (int j = 0; j < n; j++) {
        char nombreJuegoMin[LARGO_NOMBRE];
        int k = 0;
        while (juegos[j].nombre[k] != '\0' && k < LARGO_NOMBRE - 1) {
            nombreJuegoMin[k] = aMinuscula(juegos[j].nombre[k]);
            k++;
        }
        nombreJuegoMin[k] = '\0';

        if (contieneSubtexto(nombreJuegoMin, buscadoMin)) {
            return j; 
        }
    }
    return -1; 
}
