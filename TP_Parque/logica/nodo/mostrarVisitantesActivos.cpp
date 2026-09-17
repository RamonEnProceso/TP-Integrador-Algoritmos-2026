#include "logica/nodo/mostrarVisitantesActivos.h"
#include "structs/nodoVisitante.h"
#include "structs/visitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include <iostream>

using namespace std;

void mostrarVisitantesActivos(NodoVisitante *lista){
    NodoVisitante *actual = lista;
    imprimirTitulo("Lista de Visitantes Activos");
    int contador = 0;
    while (actual != nullptr){
        contador++;
        imprimirConNumero(actual->visitante.pulsera, actual->visitante.nombre);
        actual = actual->siguiente;
    }
    if(contador=0){
        cout<<"No se encontraron visitantes.\n\n";
    }else{
        cout<<"Fin de la lista.\n\n";
    }
}
