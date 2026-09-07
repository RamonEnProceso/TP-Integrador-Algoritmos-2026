#include "datos/prueba/generarDatosPrueba.h"
#include "structs/visitante.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void generarDatosPrueba(){
    cout << "Generando datos...\n" ;
    cout << "Generando visitantes...\n" ;
    /*Visitante juan = { 0, "Ramón Ramirez", 23, 1.83 };
    Visitante joaquin = { 0, "Joaquin Orsini", 23, 1.83 };
    Visitante ramiro = { 0, "Ramiro Szrebka", 23, 1.83 };
    Visitante nahuel = { 0, "Ignacio Segovia", 23, 1.83 };
    Visitante manuel = { 0, "Manuel Guevara", 23, 1.83 };
    Visitante sebas = { 0, "Sebastian Longo ", 23, 1.83 };
    Visitante cristian = { 0, "Cristian ", 23, 1.83 };
    Visitante alexis = { 0, "Alexis Nogueira", 23, 1.83 };
    Visitante rigo = { 0, "Rigo ", 23, 1.83 };
    Visitante lucas = { 0, "Lucas ", 23, 1.83 };
    
    Falta crear una función para meter esto como Nodo

    */

    cout << "Generando juegos...\n" ;
    Juego listaJuegos[9];
    cout << "Generando juegos mecanicos...\n" ;
    listaJuegos[0] = {1, "Montana Rusa", 0, 1.40, 24, true};
    listaJuegos[1] = {2, "Rueda de la Fortuna", 0, 1.20, 32, true};
    listaJuegos[2] = {3, "Autitos Chocadores", 0, 1.10, 20, true};
    listaJuegos[3] = {4, "Barco Pirata", 0, 1.30, 30, true};
    listaJuegos[4] = {5, "Vuelta al Mundo", 0, 1.20, 24, true};
    cout << "Generando juegos acuaticos...\n" ;
    listaJuegos[5] = {6, "Tobogan Acuatico", 1, 1.30, 12, true};
    listaJuegos[6] = {7, "Rio Salvaje", 1, 1.20, 16, true};
    listaJuegos[7] = {8, "Pileta de Olas", 1, 1.10, 40, true};
    cout << "Generando juegos infantiles...\n" ;
    listaJuegos[8] = {9, "Calesita", 2, 0.80, 20, true};
    listaJuegos[9] = {10, "Tazas Locas", 2, 0.90, 16, true};
    return;
};