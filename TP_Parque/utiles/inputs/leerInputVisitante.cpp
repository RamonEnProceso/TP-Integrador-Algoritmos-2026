#include "utiles/inputs/leerInputVisitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "structs/visitante.h"
#include <iostream>

using namespace std;

Visitante leerInputVisitante(){
    Visitante nuevo;
    imprimirTitulo("Ingrese los datos del visitante");
    cout << "Nombre: "; cin >> nuevo.nombre; cout << "\n";
    cout << "Numero de pulsera: "; cin >> nuevo.pulsera; cout << "\n";
    cout << "Edad: "; cin >> nuevo.edad; cout << "\n";
    cout << "Altura: "; cin >> nuevo.altura; cout << "\n";
    cout << "\nLeyendo datos...\n";
    return nuevo;
};
