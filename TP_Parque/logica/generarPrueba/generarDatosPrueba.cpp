#include "logica/generarPrueba/generarDatosPrueba.h"
#include "logica/archivo/crearArchivoJuegos.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "structs/nodoVisitante.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void generarDatosPrueba(DatosParque &datos){
    cout << "Generando datos...\n" ;
    cout << "Generando visitantes...\n" ;

    NodoVisitante *lista = datos.listaVisitantes;

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

    cout << "Generando juegos mecanicos...\n" ;
    datos.juegos[0] = {1, "Montana Rusa", 0, 1.40f, 24, true};
    datos.juegos[1] = {2, "Rueda de la Fortuna", 0, 1.20f, 32, false};
    datos.juegos[2] = {3, "Autitos Chocadores", 0, 1.10f, 20, false};
    datos.juegos[3] = {4, "Barco Pirata", 0, 1.30f, 30, true};
    datos.juegos[4] = {5, "Pendulo Vertigo", 0, 1.20f, 24, false};
    cout << "Generando juegos acuaticos...\n" ;
    datos.juegos[5] = {6, "Tobogan Acuatico", 1, 1.30f, 12, true};
    datos.juegos[6] = {7, "Rio Salvaje", 1, 1.20f, 16, true};
    datos.juegos[7] = {8, "Pileta de Olas", 1, 1.10f, 40, false};
    cout << "Generando juegos infantiles...\n" ;
    datos.juegos[8] = {9, "Calesita", 2, 0.80f, 20, true};
    datos.juegos[9] = {10, "Tazas Locas", 2, 0.90f, 16, true};
    datos.cantJuegos = 10; 
    cout << "Grabandolos en archivo binario...\n" << endl ;
    crearArchivoJuegos(datos.juegos, datos.cantJuegos);
    
    cout << "Generando matriz de ocupacion de Juegos...\n";
    const int OCUPACION_PRUEBA[10][FRANJAS_HORARIAS] = {
        { 2,  6, 18, 12,  8},
        { 3,  5, 10,  9,  4},
        { 1,  4,  8,  7,  3},
        { 2,  7, 14, 10,  6},
        { 0,  2,  6,  5,  2},
        { 0,  3,  9, 11,  7},
        { 1,  4,  7,  8,  5},
        { 0,  1,  5,  6,  3},
        { 4,  8, 12,  9,  5},
        { 2,  5,  7,  6,  3}
    };

    for (int i = 0; i < datos.datosMatriz.juegos; i++){
        for (int j = 0; j < datos.datosMatriz.franjas; j++){
            datos.datosMatriz.matriz[i][j] = OCUPACION_PRUEBA[i][j];
        }
    }

    datos.datosMatriz.juegos = datos.cantJuegos;
    datos.datosMatriz.franjas = FRANJAS_HORARIAS;

    cout << "Datos de prueba generados correctamente.\n\n";
    return;
};
