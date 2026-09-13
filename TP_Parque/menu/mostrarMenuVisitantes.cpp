#include "menu/mostrarMenuVisitantes.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputVisitante.h"
#include "structs/nodoVisitante.h"
#include "logica/nodo/mostrarVisitantesActivos.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "logica/nodo/eliminarVisitanteListaPorPulsera.h"
#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include "structs/visitante.h"
#include <iostream>

using namespace std;

void mostrarMenuVisitantes(NodoVisitante *&listaVisitantes){
    int opcionElegida = 0, numeroIngresado = 0;
    Visitante nuevoVisitante;

    while (opcionElegida != -1)
    {
        opcionElegida = 0; numeroIngresado = 0;
        imprimirTitulo("Menu Visitantes");
        imprimirConNumero(1,"Mostrar Visitantes");
        imprimirConNumero(2,"Registrar Visitante");
        imprimirConNumero(3,"Buscar Visitante (Pulsera / Nombre)");
        imprimirConNumero(4,"Ver Historial de juegos de Visitante (Pulsera / Nombre)");
        imprimirConNumero(5,"Eliminar Visitante");
        imprimirConNumero(6,"Volver al Menu Principal");

        while (opcionElegida < 1 || opcionElegida > 6){
            cout << "Ingresa el numero de opcion elegida: "; cin >> opcionElegida; cout<<endl;
            if (opcionElegida < 1 || opcionElegida > 6){
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        };

        switch (opcionElegida)
        {
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
        case 4:
            /* Ver Historial de juegos de Visitante (Pulsera / Nombre) */
            break;
        case 5:
            cout << "Ingrese el numero de pulsera del visitante que desea eliminar: ";
            cin >> numeroIngresado; cout << endl;
            eliminarVisitanteListaPorPulsera(listaVisitantes,numeroIngresado);
            break;
        case 6:
            cout << "Regresando... \n\n";
            opcionElegida = 0;
            return;
        }
    }
};
