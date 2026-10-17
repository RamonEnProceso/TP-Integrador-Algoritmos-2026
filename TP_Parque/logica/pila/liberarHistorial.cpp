#include "logica/pila/liberarHistorial.h"
#include "logica/pila/desapilarJuegoVisitado.h"

void liberarHistorial(Visitante &visitante){
    while (visitante.historial != nullptr){
        visitante.historial = desapilarJuegoVisitado(visitante.historial);
    }
}
