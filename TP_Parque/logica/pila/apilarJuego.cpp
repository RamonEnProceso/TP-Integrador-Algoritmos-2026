#include "logica/pila/apilarJuego.h"
#include "logica/pila/apilarJuegoVisitado.h"

void apilarJuego(Visitante &visitante, Juego juego){
    visitante.historial = apilarJuegoVisitado(visitante.historial, juego.codigo);
}
