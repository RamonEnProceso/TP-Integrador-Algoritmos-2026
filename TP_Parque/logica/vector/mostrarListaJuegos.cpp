#include "structs/juego.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/outputs/imprimirTitulo.h"
#include <iostream>

using namespace std;

void mostrarListaJuegos(Juego *listaJuegos, int cantJuegos){
    imprimirTitulo("Lista de Juegos");
    if(cantJuegos < 1){cout<<"No hay juegos en lista.\n";}
    for (int i; i<cantJuegos; i++){
        imprimirConNumero(i,listaJuegos[i].nombre);}
    cout <<"Fin de lista de Juegos.\n\n";
    return;
}