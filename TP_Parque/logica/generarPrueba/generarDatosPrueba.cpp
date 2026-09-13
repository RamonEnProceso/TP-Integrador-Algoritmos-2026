#include "logica/generarPrueba/generarDatosPrueba.h"
#include "logica/archivo/crearArchivoJuegos.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "structs/nodoVisitante.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void generarDatosPrueba(NodoVisitante*& lista){
    cout << "Generando datos...\n" ;
    cout << "Generando visitantes...\n" ;

    lista = agregarVisitanteLista({ 1000, "Ramon Ramirez", 23, 1.83f }, lista);
    lista = agregarVisitanteLista({ 1001, "Joaquin Orsini",   23, 1.83f }, lista);
    lista = agregarVisitanteLista({ 1002, "Ramiro Szrebka",   27, 1.79f }, lista);
    lista = agregarVisitanteLista({ 1003, "Ignacio Segovia",  19, 1.71f }, lista);
    lista = agregarVisitanteLista({ 1004, "Manuel Guevara",   34, 1.68f }, lista);
    lista = agregarVisitanteLista({ 1005, "Sebastian Longo",  16, 1.65f }, lista);
    lista = agregarVisitanteLista({ 1006, "Cristian Alvarez", 42, 1.76f }, lista);
    lista = agregarVisitanteLista({ 1007, "Alexis Nogueira",  22, 1.80f }, lista);
    lista = agregarVisitanteLista({ 1008, "Rigo Morel",       29, 1.74f }, lista);
    lista = agregarVisitanteLista({ 1009, "Lucas More",       14, 1.55f }, lista);

    cout << "Cargando en memoria...\n" ;

    cout << "Generando juegos...\n" ;
    Juego listaJuegos[10];
    cout << "Generando juegos mecanicos...\n" ;
    listaJuegos[0] = {1, "Montana Rusa", 0, 1.40f, 24, true};
    listaJuegos[1] = {2, "Rueda de la Fortuna", 0, 1.20f, 32, false};
    listaJuegos[2] = {3, "Autitos Chocadores", 0, 1.10f, 20, false};
    listaJuegos[3] = {4, "Barco Pirata", 0, 1.30f, 30, true};
    listaJuegos[4] = {5, "Pendulo Vertigo", 0, 1.20f, 24, false};
    cout << "Generando juegos acuaticos...\n" ;
    listaJuegos[5] = {6, "Tobogan Acuatico", 1, 1.30f, 12, true};
    listaJuegos[6] = {7, "Rio Salvaje", 1, 1.20f, 16, true};
    listaJuegos[7] = {8, "Pileta de Olas", 1, 1.10f, 40, false};
    cout << "Generando juegos infantiles...\n" ;
    listaJuegos[8] = {9, "Calesita", 2, 0.80f, 20, true};
    listaJuegos[9] = {10, "Tazas Locas", 2, 0.90f, 16, true};
    cout << "Grabandolos en archivo binario...\n" << endl ;
    crearArchivoJuegos(listaJuegos, 10);

    return;
};
