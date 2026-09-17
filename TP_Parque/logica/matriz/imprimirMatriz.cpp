#include "structs/datosParque.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "constantes/matrizConstantes.h"
#include <iostream>

using namespace std;

void imprimirMatriz(DatosParque datos){

    imprimirTitulo("Matriz de ocupantes por franja");
    for (int i = 0; i < datos.datosMatriz.juegos; i++)
    {
        cout << datos.juegos[i].nombre << ": ";
        for (int j = 0; j < datos.datosMatriz.franjas; j++)
        {
            cout << " | " << datos.datosMatriz.matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Franjas horarias ";
    for (int i = 0; i < datos.datosMatriz.franjas; i++){
        cout << " | " << FRANJAS_TEXTO[i] << " ";
    }
    cout << "\n Fin de la matriz.\n\n";
}
