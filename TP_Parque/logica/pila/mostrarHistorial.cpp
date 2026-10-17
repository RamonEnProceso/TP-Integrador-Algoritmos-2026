#include "logica/pila/mostrarHistorial.h"
#include "logica/pila/mostrarHistorialVisitante.h"

void mostrarHistorial(Visitante visitante){
    mostrarHistorialVisitante(visitante.historial);
}
