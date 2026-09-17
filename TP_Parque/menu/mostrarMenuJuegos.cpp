#include "menu/mostrarMenuJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "utiles/outputs/imprimirJuego.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "logica/vector/ordenarPorCodigo.h"
#include "logica/vector/ordenarPorNombre.h"
#include "logica/vector/buscarJuegoPorCodigoBinaria.h"
#include "logica/texto/buscarJuegoPorNombre.h"
#include "constantes/generales.h"
#include "constantes/matrizConstantes.h"
#include "structs/juego.h"
#include <iostream>

using namespace std;

void mostrarMenuJuegos() {
    int opcionElegida = 0;
    Juego juegos[MAX_JUEGOS]; 
    
    int cantidad = leerArchivoJuegos(juegos, MAX_JUEGOS);

    if (cantidad == 0) {
        cout << "No hay juegos cargados. Genera los datos de prueba desde el Menu Principal.\n\n";
        return;
    }

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Menu Juegos");
        imprimirConNumero(1, "Ordenar por Codigo");
        imprimirConNumero(2, "Ordenar por Nombre");
        imprimirConNumero(3, "Buscar Juego por Codigo");
        imprimirConNumero(4, "Buscar Juego por Nombre");
        imprimirConNumero(5, "Volver al Menu Principal");

        while (opcionElegida < 1 || opcionElegida > 5) {
            cout << "Ingresa el numero de opcion elegida: "; 
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 5) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {
            case 1:
                ordenarPorCodigo(juegos, cantidad);
                cout << "Juegos ordenados por codigo exitosamente.\n\n";
                break;
            case 2:
                ordenarPorNombre(juegos, cantidad);
                cout << "Juegos ordenados alfabeticamente exitosamente.\n\n";
                break;
            case 3: {
                cout << "Ingrese el codigo a buscar: ";
                int cod;
                cin >> cod;
                ordenarPorCodigo(juegos, cantidad); 
                int posCod = buscarJuegoPorCodigoBinaria(juegos, cantidad, cod);
                if (posCod != -1) {
                    imprimirJuego(juegos[posCod]);
                } else {
                    cout << "Juego no encontrado.\n\n";
                }
                break;
            }
            case 4: {
                cout << "Ingrese el nombre a buscar (parcial): ";
                char nom[LARGO_NOMBRE];
                cin.ignore();
                cin.getline(nom, LARGO_NOMBRE);
                int posNom = buscarJuegoPorNombre(juegos, cantidad, nom);
                if (posNom != -1) {
                    imprimirJuego(juegos[posNom]);
                } else {
                    cout << "Juego no encontrado.\n\n";
                }
                break;
            }
            case 5:
                cout << "Regresando...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
