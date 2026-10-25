#include "menu/mostrarMenuHerramientas.h"
#include "menu/mostrarMenuRecursividad.h"
#include "logica/generarPrueba/generarDatosPrueba.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/inputs/leerInputMenu.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Principal > Herramientas");
    imprimirConNumero(1, "Generar datos de prueba");
    imprimirConNumero(2, "Recursion");
    imprimirConNumero(3, "Volver al menu anterior");
}

void mostrarMenuHerramientas(DatosParque &datos){
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
                generarDatosPrueba(datos);
                break;
            case 2:
                mostrarMenuRecursividad(datos);
                break;
            case 3:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
