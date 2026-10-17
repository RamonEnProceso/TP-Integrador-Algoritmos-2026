#include "logica/recursividad/mostrarVisitantesActivosRec.h"
#include "logica/recursividad/recursionActivosYFila.h"
#include <iostream>

using namespace std;

void mostrarVisitantesActivosRec(NodoVisitante *lista){
    cout << "Cantidad de visitantes activos (recursivo): " << contarActivosRec(lista) << "\n\n";
}
