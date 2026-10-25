#include "menu/mostrarMenuVisitantes.h"
#include "menu/seleccionarJuego.h"
#include "menu/menuVisitantes/mostrarMenuEliminarLiberar.h"
#include "menu/menuVisitantes/mostrarMenuHistorial.h"
#include "menu/menuVisitantes/mostrarMenuArchivosVisitantes.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "logica/nodo/mostrarVisitantesActivos.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include "structs/juego.h"
#include "structs/visitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputVisitante.h"
#include "utiles/inputs/leerInputMenu.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Visitantes");
    imprimirConNumero(1, "Mostrar Visitantes");
    imprimirConNumero(2, "Registrar Visitante");
    imprimirConNumero(3, "Buscar Visitante (Pulsera / Nombre)");
    imprimirConNumero(4, "Asignar juego a visitante");
    imprimirConNumero(5, "Eliminar y liberar");
    imprimirConNumero(6, "Historial de juegos");
    imprimirConNumero(7, "Archivos e indice");
    imprimirConNumero(8, "Volver al menu anterior");
    return;
}

void mostrarMenuVisitantes(NodoVisitante *&listaVisitantes){
    int opcionElegida = 0, numeroIngresado = 0;
    Visitante nuevoVisitante;

    imprimirMenu();

    while (opcionElegida != -1)
    {
        opcionElegida = -2; numeroIngresado = 0;

        leerInputMenu(0, 8, opcionElegida);

        switch (opcionElegida)
        {
        case 0:
            imprimirMenu();
            break;
        case 1:
            mostrarVisitantesActivos(listaVisitantes);
            break;
        case 2:
            leerInputVisitante(nuevoVisitante);
            listaVisitantes = agregarVisitanteLista(nuevoVisitante, listaVisitantes);
            cout<< "Visitante registrado correctamente.\n\n";
            break;
        case 3:
            cout << "Ingrese el numero de pulsera del visitante que desea buscar: ";
            cin >> numeroIngresado; cout << endl;
            buscarVisitanteActivoPorPulsera(listaVisitantes, numeroIngresado);
            break;
        case 4: {
            Juego juegosParaSeleccion[50];
            int cantJuegos = leerArchivoJuegos(juegosParaSeleccion, 50);
            if (cantJuegos > 0) {
                seleccionarJuego(juegosParaSeleccion, cantJuegos);
            } else {
                cout << "No hay juegos disponibles en el sistema.\n\n";
            }
            break;
        }
        case 5:
            mostrarMenuEliminarLiberar(listaVisitantes);
            break;
        case 6:
            mostrarMenuHistorial(listaVisitantes);
            break;
        case 7:
            mostrarMenuArchivosVisitantes(listaVisitantes);
            break;
        case 8:
            cout << "Regresando... \n\n";
            opcionElegida = -1;
            break;
        }
    }
};
