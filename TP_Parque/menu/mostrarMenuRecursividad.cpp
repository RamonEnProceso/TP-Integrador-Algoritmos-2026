#include "menu/mostrarMenuRecursividad.h"
#include "menu/menuJuegos/seleccionarJuego.h"
#include "logica/recursividad/recursionActivosYFila.h"
#include "logica/recursividad/mostrarVisitantesActivosRec.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputMenu.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Herramientas > Recursion");
    imprimirConNumero(1, "Contar visitantes activos (recursivo)");
    imprimirConNumero(2, "Atender fila (recursivo)");
    imprimirConNumero(3, "Volver al menu anterior");
}

void mostrarMenuRecursividad(DatosParque &datos){
    int opcionElegida = 0;

    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida = -2;

        leerInputMenu(0, 3, opcionElegida);

        switch (opcionElegida) {
            case 0:
                imprimirMenu();
                break;
            case 1:
                mostrarVisitantesActivosRec(datos.listaVisitantes);
                break;
            case 2: {
                if (datos.cantJuegos == 0) {
                    datos.cantJuegos = leerArchivoJuegos(datos.juegos, MAX_JUEGOS);
                }
                if (datos.cantJuegos == 0) {
                    cout << "No hay juegos cargados en el sistema.\n";
                    cout << "Genere primero los datos de prueba desde Herramientas.\n\n";
                    break;
                }
                cout << "Seleccione el juego cuya fila desea atender (recursivamente):\n";
                int idxJuego = seleccionarJuego(datos.juegos, datos.cantJuegos);
                if (idxJuego >= 0 && idxJuego < datos.cantJuegos) {
                    cout << "\n=== Atendiendo (recursivo) la fila de: " << datos.juegos[idxJuego].nombre << " ===\n";
                    atenderFilaRec(datos.filasJuegos[idxJuego]);
                }
                break;
            }
            case 3:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
