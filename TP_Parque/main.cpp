#include "menu/mostrarMenuPrincipal.h"
#include "logica/nodo/crearListaNodo.h"
#include "structs/nodoVisitante.h"

int main(){
    NodoVisitante *listaVisitantes = crearLista();
    mostrarMenuPrincipal(listaVisitantes);
    return 0;
}