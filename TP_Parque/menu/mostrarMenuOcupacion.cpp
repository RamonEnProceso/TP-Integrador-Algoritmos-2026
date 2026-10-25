#include "menu/mostrarMenuOcupacion.h"
#include "structs/matrizJuegoxHoras.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/matriz/imprimirMatriz.h"
#include "logica/matriz/imprimirTotales.h"
#include "logica/matriz/devolverMayorOcupacion.h"
#include "logica/matriz/devolverJuegoMasUsado.h"
#include "logica/matriz/reconstruirMatriz.h"
#include "logica/archivo/exportarReporteDia.h"
#include "utiles/matematica/sumaTotal.h"
#include "constantes/matrizConstantes.h"
#include "structs/mayorOcupacion.h"
#include "utiles/inputs/leerInputMenu.h"
#include <iostream>

using namespace std;

static void imprimirMenu(){
    imprimirTitulo("Menu Ocupacion");
    imprimirConNumero(1, "Mostrar ocupacion de juegos por franja");
    imprimirConNumero(2, "Mostrar pico maximo de ocupacion");
    imprimirConNumero(3, "Mostrar juego mas usado");
    imprimirConNumero(4, "Mostrar total de visitas en el dia" );
    imprimirConNumero(5, "Exportar Reporte del dia");
    imprimirConNumero(6, "Volver al Menu Principal");
    return;
}

void mostrarMenuOcupacion(DatosParque &datos){
    int opcionElegida = 0;
    reconstruirMatriz(datos);

    imprimirMenu();

    while (opcionElegida != -1) {
        opcionElegida  = -2;;

        leerInputMenu(0, 6, opcionElegida);

        switch (opcionElegida) {

            case 0:
                imprimirMenu();
                break;

            case 1:
                imprimirMatriz(datos);
                break;

            case 2: {
                MayorOcupacion mayorOcupacion = devolverMayorOcupacion(datos.datosMatriz);
                cout << "El pico maximo fue en el juego " << datos.juegos[mayorOcupacion.juego].nombre
                << " de " << FRANJAS_TEXTO[mayorOcupacion.franja] << " con un total de " << mayorOcupacion.ocupacion
                << " visitantes. \n\n";
                break;
            }

            case 3: {
                int maxPos = devolverMasUsado(datos.datosMatriz);
                int cantidadMax = sumaTotalV(datos.datosMatriz.matriz[maxPos],datos.datosMatriz.franjas);
                cout<< "El juego mas usado fue " << datos.juegos[maxPos].nombre << " con " << cantidadMax << " ocupantes en todo el dia.\n\n";
                break;
            }

            case 4: {
                imprimirTotales(datos);
                break;
            }

            case 5: {
                exportarReporteDia(datos);
                break;
            }

            case 6:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
