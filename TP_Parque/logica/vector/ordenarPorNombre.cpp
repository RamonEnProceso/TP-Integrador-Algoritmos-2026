#include "logica/vector/ordenarPorNombre.h"

int compararTextos(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        i++;
    }
    return a[i] - b[i];
}

void ordenarPorNombre(Juego juegos[], int n) {
    bool huboCambios = true;
    for (int i = 0; i < n - 1 && huboCambios; i++) {
        huboCambios = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (compararTextos(juegos[j].nombre, juegos[j + 1].nombre) > 0) {
                Juego aux = juegos[j];
                juegos[j] = juegos[j + 1];
                juegos[j + 1] = aux;
                huboCambios = true;
            }
        }
    }
}
