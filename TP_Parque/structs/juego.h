#ifndef JUEGO_H
#define JUEGO_H

const int LARGO_NOMBRE = 32;

struct Juego {
    int codigo;
    char nombre[LARGO_NOMBRE];
    int tipo; 
    float alturaMinima;
    int capacidad;
    bool operativo;
};

#endif