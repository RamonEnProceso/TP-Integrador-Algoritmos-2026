#ifndef VISITANTE_H
#define VISITANTE_H

const int LARGO_NOMBRE = 32;

struct Visitante {
    int pulsera;
    char nombre[LARGO_NOMBRE];
    int edad;
    float altura;
};

#endif