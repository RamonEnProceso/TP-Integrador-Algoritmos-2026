#include "logica/verificador/verificarAcceso.h"
#include <iostream>

using namespace std;

bool verificarAcceso(const Juego &juego, const Visitante &visitante) {
    if (!juego.operativo) {
        cout << "[ACCESO DENEGADO] El juego '" << juego.nombre
             << "' se encuentra FUERA DE SERVICIO.\n\n";
        return false;
    }

    if (visitante.altura < juego.alturaMinima) {
        cout << "[ACCESO DENEGADO] El visitante " << visitante.nombre
             << " tiene una altura de " << visitante.altura
             << "m y la altura minima requerida para '" << juego.nombre
             << "' es de " << juego.alturaMinima << "m.\n\n";
        return false;
    }

    cout << "[ACCESO PERMITIDO] " << visitante.nombre
         << " cumple los requisitos para ingresar a la fila de '" << juego.nombre << "'.\n\n";
    return true;
}
