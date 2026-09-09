#include "structs/juego.h"
#include <iostream>

using namespace std;

void imprimirJuego (Juego juego){
    cout << "Nombre: " << juego.nombre << endl;
    cout << "Codigo: " << juego.codigo << endl;
    cout << "Tipo de Juego: " << juego.tipo << endl;
    cout << "Capacidad: " << juego.capacidad << endl;
    cout << "Altura Minima: " << juego.alturaMinima << endl;
    cout << "Estado: " << devolverOperativo(juego.operativo) << endl;
}

const char* devolverOperativo (bool estado){
    if(estado){
        return "Funcionando";
    }else{
        return "No disponible";
    }
}