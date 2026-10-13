#include "logica/cola/atenderSiguienteVisitante.h"
#include "logica/cola/desencolarVisitante.h"
#include <iostream>

using namespace std;

void atenderSiguienteVisitante(Cola &c) {
    Visitante v;
    if (desencolarVisitante(c, v)) {
        cout << ">>> Atendiendo al visitante: " << v.nombre 
             << " (Pulsera: " << v.pulsera << ") <<<\n\n";
    } else {
        cout << "No hay visitantes en la fila para atender.\n\n";
    }
}
