#include "menu/mostrarMenuVisitantes.h"
#include "menu/seleccionarJuego.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "structs/juego.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputVisitante.h"
#include "structs/nodoVisitante.h"
#include "logica/nodo/mostrarVisitantesActivos.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "logica/nodo/eliminarVisitanteListaPorPulsera.h"
#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include "logica/nodo/liberarVisitanteLista.h"
#include "structs/visitante.h"
#include <iostream>

using namespace std;

void imprimirMenu(){
    imprimirTitulo("Menu Visitantes");
    imprimirConNumero(1,"Mostrar Visitantes");
    imprimirConNumero(2,"Registrar Visitante");
    imprimirConNumero(3,"Buscar Visitante (Pulsera / Nombre)");
    imprimirConNumero(4,"Seleccionar Juego (Asignar juego a un visitante)");
    imprimirConNumero(5,"Eliminar Visitante");
    imprimirConNumero(6,"Liberar Visitantes");
    imprimirConNumero(7,"Volver al Menu Principal");
    return;
}

void mostrarMenuVisitantes(NodoVisitante *&listaVisitantes){
    int opcionElegida = 0, numeroIngresado = 0;
    Visitante nuevoVisitante;

    imprimirMenu();

    while (opcionElegida != -1)
    {
        opcionElegida = 0; numeroIngresado = 0;
        

        while (opcionElegida < 0 || opcionElegida > 7){
            cout << "Ingresa un numero (0 para imprimir menu): "; cin >> opcionElegida; cout<<endl;
            if (opcionElegida < 0 || opcionElegida > 7){
                cout << "Numero incorrecto.\n";
            }
        };

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
            cout << "Ingrese el numero de pulsera del visitante que desea eliminar: ";
            cin >> numeroIngresado; cout << endl;
            eliminarVisitanteListaPorPulsera(listaVisitantes,numeroIngresado);
            break;
        case 6:
            liberarVisitanteLista(listaVisitantes);
            cout<< "Liberando lista de visitantes...\n\n";
            opcionElegida = 0;
            return;
        case 7:
            cout << "Regresando... \n\n";
            opcionElegida = 0;
            return;
        }
    }
};
