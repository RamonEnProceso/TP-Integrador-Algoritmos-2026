#include "logica/texto/buscarJuegoPorNombre.h"
#include "constantes/generales.h"

char aMinuscula(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

void convertirAMinuscula(char destino[], const char origen[]) {
    int i = 0;
    while (i < LARGO_NOMBRE - 1 && origen[i] != '\0') {
        destino[i] = aMinuscula(origen[i]);
        i++;
    }
    destino[i] = '\0';
}

bool contieneSubtexto(const char* texto, const char* subtexto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        int j = 0;
        while (subtexto[j] != '\0' &&
               texto[i + j] == subtexto[j])
            j++;

        if (subtexto[j] == '\0')
            return true;
    }
    return false;
}

int buscarJuegoPorNombre(Juego juegos[], int n, const char nombreBuscado[]) {
    char buscadoMin[LARGO_NOMBRE];
    convertirAMinuscula(buscadoMin, nombreBuscado);

    for (int j = 0; j < n; j++) {
        char nombreMin[LARGO_NOMBRE];
        convertirAMinuscula(nombreMin, juegos[j].nombre);

        if (contieneSubtexto(nombreMin, buscadoMin))
            return j;
    }
    return -1;
}