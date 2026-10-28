#include "logica/pila/desapilarJuego.h"
#include "logica/pila/desapilarJuegoVisitado.h"
#include "logica/pila/topeHistorial.h"
#include <iostream>

using namespace std;

void desapilarJuego(Visitante &visitante){
    int ultimo = topeHistorial(visitante.historial);
    if (ultimo == -1){
        cout << "El visitante no tiene juegos por deshacer.\n\n";
        return;
    }
    visitante.historial = desapilarJuegoVisitado(visitante.historial);
    cout << "Se deshizo el ultimo juego del historial.\n\n";
}
