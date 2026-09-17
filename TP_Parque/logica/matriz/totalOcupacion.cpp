#include "logica/matriz/totalOcupacion.h"
#include "logica/matriz/totalPorJuego.h"
#include "structs/matrizJuegoxHoras.h"
#include "utiles/matematica/sumaTotal.h"

int totalOcupacion(MatrizJuegoXHoras datos){
    int* vector = new int[datos.juegos];
    totalPorJuego(datos, vector);
    int sumaTotal = sumaTotalV(vector, datos.juegos);
    delete[] vector;
    return sumaTotal;
}
