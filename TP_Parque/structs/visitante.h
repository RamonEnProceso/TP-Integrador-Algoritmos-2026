#ifndef VISITANTE_H
#define VISITANTE_H
#include "constantes/generales.h"

struct NodoJuegoVisitado;

struct Visitante {
    int pulsera;
    char nombre[LARGO_NOMBRE];
    int edad;
    float altura;
    NodoJuegoVisitado* historial = nullptr;
};

struct VisitanteArchivo {
    int pulsera;
    char nombre[LARGO_NOMBRE];
    int edad;
    float altura;
};

#endif
