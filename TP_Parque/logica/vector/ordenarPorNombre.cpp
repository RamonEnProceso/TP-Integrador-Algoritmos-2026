#include "logica/vector/ordenarPorNombre.h"
#include <cstring>

void ordenarPorNombre(Juego juegos[], int n) {
    bool huboCambios = true;
    for (int i = 0; i < n - 1 && huboCambios; i++) {
        huboCambios = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(juegos[j].nombre, juegos[j + 1].nombre) > 0) {
                Juego aux = juegos[j];
                juegos[j] = juegos[j + 1];
                juegos[j + 1] = aux;
                huboCambios = true;
            }
        }
    }
}
