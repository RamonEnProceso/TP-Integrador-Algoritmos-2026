#include "structs/juego.h"
#include "utiles/outputs/imprimirConNum.h"
#include <iostream>

using namespace std;

void mostrarListaJuegos(Juego *listaJuegos, int cantJuegos){
    if(cantJuegos < 1){cout<<"No hay juegos en lista.\n";}
    for (int i; i<cantJuegos; i++){
        imprimirConNumero(i,listaJuegos[i].nombre);}
    return;
}