#include "menu/mostrarMenuPrincipal.h"
#include "logica/nodo/crearListaNodo.h"
#include "logica/nodo/nodoVisitante.h"

int main(){
    NodoVisitante *listaVisitantes = crearLista();
    mostrarMenuPrincipal();
    return 0;
}