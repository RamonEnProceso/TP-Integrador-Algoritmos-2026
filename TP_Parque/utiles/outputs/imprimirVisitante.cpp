#include "utiles/outputs/imprimirVisitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "structs/visitante.h"
#include <iostream>

using namespace std;

void imprimirVisitante(Visitante datos){
    imprimirTitulo("Datos del Visitante");
    cout << "Nombre: " << datos.nombre << endl;
    cout << "Numero de pulsera: " << datos.pulsera << endl;
    cout << "Edad: " << datos.edad << endl;
    cout << "Altura: " << datos.altura << endl;
    cout << "\n";
    return;
};
