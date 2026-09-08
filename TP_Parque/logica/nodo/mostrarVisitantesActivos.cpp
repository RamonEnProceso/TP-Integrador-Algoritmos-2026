#include "logica/nodo/mostrarVisitantesActivos.h"
#include "logica/nodo/nodoVisitante.h"
#include "structs/visitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include <iostream>

using namespace std;

void mostrarVisitantesActivos(NodoVisitante *lista){
    NodoVisitante *actual = lista;
    int contador = 0;
    imprimirTitulo("Lista de Visitantes Activos");
    while (actual != nullptr){
        imprimirConNumero(actual->visitante.pulsera, actual->visitante.nombre);
        contador++;
        actual = actual->siguiente;
    }
    cout<<"Fin de la lista.\n";
}
