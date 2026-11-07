#include "menu/mostrarMenuVisitantes.h"
#include "menu/menuJuegos/seleccionarJuego.h"
#include "menu/menuVisitantes/mostrarMenuEliminarV.h"
#include "menu/menuVisitantes/mostrarMenuHistorial.h"
#include "menu/menuVisitantes/mostrarMenuArchivosVisitantes.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "logica/nodo/mostrarVisitantesActivos.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "logica/nodo/buscarVisitanteActivoPorPulsera.h"
#include "logica/nodo/obtenerVisitantePorPulsera.h"
#include "logica/cola/estaEnCola.h"
#include "logica/cola/encolarVisitante.h"
#include "logica/verificador/verificarAcceso.h"
#include "structs/juego.h"
#include "structs/visitante.h"
#include "structs/nodoVisitante.h"
#include "structs/datosParque.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputVisitante.h"
#include "utiles/inputs/leerInputMenu.h"
#include "constantes/generales.h"
#include "constantes/matrizConstantes.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Visitantes");
    char listaMenu[8][LARGO_NOMBRE] = {"Mostrar Visitantes","Registrar Visitante","Buscar Visitante",
        "Asignar juego a visitante","Eliminar y liberar","Historial de juegos","Archivos e indice","Volver al menu anterior"};
    for (int i = 0; i < 8; i++){
        imprimirConNumero(i+1,listaMenu[i]);
    }
    return;
}

void asignarJuegoVisitante (DatosParque &datos){
    if (datos.cantJuegos == 0) {
        datos.cantJuegos = leerArchivoJuegos(datos.juegos, MAX_JUEGOS);
        if (datos.cantJuegos == 0) {
            cout << "No hay juegos disponibles en el sistema.\n\n";
            return;
        }
    }
    int pulsera = 0;
    cout << "Ingrese el numero de pulsera del visitante: ";
    cin >> pulsera; cout << endl;
    Visitante v;
    if (!obtenerVisitantePorPulsera(datos.listaVisitantes, pulsera, v)) {
        cout << "No se encontro un visitante activo con la pulsera " << pulsera << ".\n\n";
        return;
    }
    int idxJuego = seleccionarJuego(datos.juegos, datos.cantJuegos, datos.filasJuegos);
    if (idxJuego >= 0 && idxJuego < datos.cantJuegos) {
        if (estaEnCola(datos.filasJuegos[idxJuego], v.pulsera)) {
            cout << "[ACCESO DENEGADO] El visitante ya se encuentra en la fila.\n\n";
            return;
        }
        if (verificarAcceso(datos.juegos[idxJuego], v)) {
            encolarVisitante(datos.filasJuegos[idxJuego], v);
            cout << ">>> " << v.nombre << " fue asignado a la fila de '" << datos.juegos[idxJuego].nombre << "'. <<<\n\n";
        }
    }
}

void mostrarMenuVisitantes(DatosParque &datos){
    int opcionElegida = 0, numeroIngresado = 0;
    Visitante nuevoVisitante;
    NodoVisitante *&listaVisitantes = datos.listaVisitantes;

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
            asignarJuegoVisitante(datos);
            break;
        }
        case 5:
            mostrarMenuEliminarV(listaVisitantes);
            break;
        case 6:
            mostrarMenuHistorial(datos);
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
