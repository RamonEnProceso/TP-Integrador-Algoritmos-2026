#include "menu/mostrarMenuOcupacion.h"
#include "structs/matrizJuegoxHoras.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "logica/matriz/totalOcupacion.h"
#include "logica/matriz/totalPorJuego.h"
#include "logica/matriz/totalPorFranja.h"
#include "logica/matriz/imprimirMatriz.h"
#include "logica/matriz/devolverMayorOcupacion.h"
#include "logica/matriz/devolverJuegoMasUsado.h"
#include "utiles/matematica/sumaTotal.h"
#include "constantes/matrizConstantes.h"
#include "structs/mayorOcupacion.h"
#include <iostream>

using namespace std;

void mostrarMenuOcupacion(DatosParque &datos){
    int opcionElegida = 0;

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Menu Ocupacion");
        imprimirConNumero(1, "Mostrar ocupacion de juegos por franja");
        imprimirConNumero(2, "Mostrar pico maximo de ocupacion");
        imprimirConNumero(3, "Mostrar juego mas usado");
        imprimirConNumero(4, "Mostrar total de visitas en el dia" );
        imprimirConNumero(5, "Exportar Reporte del dia");
        imprimirConNumero(6, "Volver al Menu Principal");

        while (opcionElegida < 1 || opcionElegida > 6) {
            cout << "Ingresa el numero de opcion elegida: ";
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 6) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {

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
                
                int total = totalOcupacion(datos.datosMatriz);
                int totalJuegos[MAX_JUEGOS];
                int totalFranjas[FRANJAS_HORARIAS];
                totalPorJuego(datos.datosMatriz, totalJuegos);
                totalPorFranja(datos.datosMatriz, totalFranjas);

                imprimirTitulo("Total de visitas por juego");
                for (int i = 0; i < datos.datosMatriz.juegos; i++){
                    imprimirConNumero(totalJuegos[i], datos.juegos[i].nombre);
                }

                imprimirTitulo("Total de visitas por franja horaria");
                for (int j = 0; j < datos.datosMatriz.franjas; j++){
                    imprimirConNumero(totalFranjas[j], FRANJAS_TEXTO[j]);
                }
                cout << "La cantidad total de visitas del dia fue de " << total << " accesos.\n\n";
                cout << "\n";
                break;
            }

            case 5: {
                /**/
                break;
            }

            case 6:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
