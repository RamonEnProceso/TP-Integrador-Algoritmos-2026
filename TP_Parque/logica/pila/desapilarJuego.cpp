#include "logica/pila/desapilarJuego.h"
#include "logica/pila/desapilarJuegoVisitado.h"

void desapilarJuego(Visitante &visitante){
    visitante.historial = desapilarJuegoVisitado(visitante.historial);
}
