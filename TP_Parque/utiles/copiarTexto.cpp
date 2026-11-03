#include "utiles/copiarTexto.h"
#include "constantes/generales.h"

void copiarTexto(char* origen, char* destino){
    for (int i = 0; i < LARGO_NOMBRE; i++){
        destino[i] = origen[i];
    }
}