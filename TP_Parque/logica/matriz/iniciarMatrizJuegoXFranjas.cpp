#include "structs/matrizJuegoxHoras.h"
#include "constantes/matrizConstantes.h"
#include "structs/juego.h"
#include "utiles/outputs/imprimirTabla.h"
#include <iostream>

using namespace std;

void iniciarMatrizJuegoXFranjas (MatrizJuegoXHoras datos, Juego juegos[]){
    cout << "Inicializar datos de opación de juegos por franja horaria...\n\n";
    for (int i = 0; i<datos.juegos;i++){
        cout<< "Cargando visitas al juego: " << juegos[i].nombre;
        for (int j = 0; j<datos.franjas; j++){
            cout << "Cargando visitas de " << FRANJAS_TEXTO[j] <<": ";
            cin >> datos.matriz[i][j]; cout << endl;
        }
    }
    cout << "Datos de visitas registrados correctamente.\n\n";

    char* nombresColumnas[FRANJAS_HORARIAS];
    char* nombresFilas[MAX_JUEGOS];

    for (int j = 0; j < datos.franjas; j++){
        nombresColumnas[j] = (char*)FRANJAS_TEXTO[j];
    }
    for (int i = 0; i < datos.juegos; i++){
        nombresFilas[i] = juegos[i].nombre;
    }

    Tabla tabla;
    tabla.columnas = datos.franjas;
    tabla.filas = datos.juegos;
    tabla.nombresColumnas = nombresColumnas;
    tabla.nombresFilas = nombresFilas;
    tabla.contenido = datos.matriz;

    imprimirTabla(tabla);
}
