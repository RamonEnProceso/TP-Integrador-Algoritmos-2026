#include "logica/cola/atenderSiguienteVisitante.h"
#include "logica/cola/desencolarVisitante.h"
#include "logica/nodo/obtenerNodoVisitantePorPulsera.h"
#include "logica/pila/apilarJuego.h"
#include <iostream>

using namespace std;

void atenderSiguienteVisitante(Cola &c, NodoVisitante *lista, Juego *juego, int franja) {
    Visitante v;
    if (desencolarVisitante(c, v)) {
        if (juego != nullptr) {
            if (franja >= 0 && franja < FRANJAS_HORARIAS) juego->franjas[franja]++;
            NodoVisitante *nodo = obtenerNodoVisitantePorPulsera(lista, v.pulsera);
            if (nodo != nullptr) apilarJuego(nodo->visitante, *juego);
        }
        cout << ">>> Atendiendo al visitante: " << v.nombre 
             << " (Pulsera: " << v.pulsera << ") <<<\n\n";
    } else {
        cout << "No hay visitantes en la fila para atender.\n\n";
    }
}
