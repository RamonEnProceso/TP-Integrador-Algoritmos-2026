#include "menu/mostrarMenuPrincipal.h"
#include "logica/nodo/crearListaNodo.h"
#include "logica/nodo/liberarVisitanteLista.h"
#include "structs/datosParque.h"

int main(){
    DatosParque datos;
    datos.listaVisitantes = crearLista();
    datos.cantJuegos = 0;

    mostrarMenuPrincipal(datos);

    datos.listaVisitantes = liberarVisitanteLista(datos.listaVisitantes);
    return 0;
}
