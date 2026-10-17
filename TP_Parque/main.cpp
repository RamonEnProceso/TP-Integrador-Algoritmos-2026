#include "menu/mostrarMenuPrincipal.h"
#include "logica/nodo/crearListaNodo.h"
#include "logica/nodo/liberarVisitanteLista.h"
#include "logica/cola/liberarCola.h"
#include "structs/datosParque.h"

int main(){
    DatosParque datos;
    datos.listaVisitantes = crearLista();
    datos.cantJuegos = 0;

    for (int i = 0; i < MAX_JUEGOS; i++) {
        datos.filasJuegos[i] = {nullptr, nullptr};
    }

    mostrarMenuPrincipal(datos);

    for (int i = 0; i < MAX_JUEGOS; i++) {
        liberarCola(datos.filasJuegos[i]);
    }

    datos.listaVisitantes = liberarVisitanteLista(datos.listaVisitantes);
    return 0;
}

