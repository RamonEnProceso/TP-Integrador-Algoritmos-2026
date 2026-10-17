#include "menu/mostrarMenuFilas.h"
#include "menu/seleccionarJuego.h"
#include "logica/cola/encolarVisitante.h"
#include "logica/cola/mostrarFilaJuego.h"
#include "logica/cola/atenderSiguienteVisitante.h"
#include "logica/verificador/verificarAcceso.h"
#include "logica/cola/estaEnCola.h"
#include "logica/nodo/obtenerVisitantePorPulsera.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "logica/archivo/leerArchivoJuegos.h"
#include "utiles/inputs/leerInputVisitante.h"
#include "utiles/outputs/imprimirVisitante.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include <iostream>

using namespace std;

void mostrarMenuFilas(DatosParque &datos) {
    if (datos.cantJuegos == 0) {
        datos.cantJuegos = leerArchivoJuegos(datos.juegos, MAX_JUEGOS);
        if (datos.cantJuegos == 0) {
            cout << "No hay juegos cargados en el sistema.\n";
            cout << "Genere primero los datos de prueba o cargue los juegos desde el Menu Principal.\n\n";
            return;
        }
    }

    int opcionElegida = 0;

    while (opcionElegida != -1) {
        opcionElegida = 0;
        imprimirTitulo("Menu Filas y Colas de Juegos");
        imprimirConNumero(1, "Encolar visitante en un juego");
        imprimirConNumero(2, "Ver fila de un juego");
        imprimirConNumero(3, "Atender siguiente visitante en un juego");
        imprimirConNumero(4, "Ver estado de todas las filas");
        imprimirConNumero(5, "Volver al Menu Principal");

        while (opcionElegida < 1 || opcionElegida > 5) {
            cout << "Ingresa el numero de opcion elegida: ";
            cin >> opcionElegida; cout << endl;
            if (opcionElegida < 1 || opcionElegida > 5) {
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        }

        switch (opcionElegida) {
            case 1: {
                int pulseraBuscada = 0;
                cout << "Ingrese el numero de pulsera del visitante: ";
                cin >> pulseraBuscada; cout << endl;

                Visitante v;
                bool existe = obtenerVisitantePorPulsera(datos.listaVisitantes, pulseraBuscada, v);

                if (!existe) {
                    cout << "No se encontro ningun visitante activo con la pulsera " << pulseraBuscada << ".\n";
                    cout << "¿Desea registrarlo como nuevo visitante en el sistema? (1: Si / 2: No): ";
                    int resp = 0;
                    cin >> resp; cout << endl;
                    if (resp == 1) {
                        leerInputVisitante(v);
                        datos.listaVisitantes = agregarVisitanteLista(v, datos.listaVisitantes);
                        cout << "Visitante registrado exitosamente.\n\n";
                    } else {
                        cout << "Operacion cancelada.\n\n";
                        break;
                    }
                } else {
                    cout << "Visitante identificado:\n";
                    imprimirVisitante(v);
                }

                cout << "Seleccione el juego al que desea ingresar a la fila:\n";
                int idxJuego = seleccionarJuego(datos.juegos, datos.cantJuegos);

                if (idxJuego >= 0 && idxJuego < datos.cantJuegos) {
                    if (estaEnCola(datos.filasJuegos[idxJuego], v.pulsera)) {
                        cout << "[ACCESO DENEGADO] El visitante " << v.nombre
                             << " (Pulsera: " << v.pulsera << ") ya se encuentra en la fila de '"
                             << datos.juegos[idxJuego].nombre << "'.\n\n";
                        break;
                    }

                    if (verificarAcceso(datos.juegos[idxJuego], v)) {
                        encolarVisitante(datos.filasJuegos[idxJuego], v);
                        cout << ">>> " << v.nombre << " ingresó a la fila de '"
                             << datos.juegos[idxJuego].nombre << "'. <<<\n\n";
                        mostrarFilaJuego(datos.filasJuegos[idxJuego]);
                    }
                }
                break;
            }

            case 2: {
                cout << "Seleccione el juego cuya fila desea consultar:\n";
                int idxJuego = seleccionarJuego(datos.juegos, datos.cantJuegos);
                if (idxJuego >= 0 && idxJuego < datos.cantJuegos) {
                    cout << "\n=== Fila de: " << datos.juegos[idxJuego].nombre << " ===\n";
                    mostrarFilaJuego(datos.filasJuegos[idxJuego]);
                }
                break;
            }

            case 3: {
                cout << "Seleccione el juego para atender al siguiente visitante:\n";
                int idxJuego = seleccionarJuego(datos.juegos, datos.cantJuegos);
                if (idxJuego >= 0 && idxJuego < datos.cantJuegos) {
                    cout << "\n=== Atendiendo fila de: " << datos.juegos[idxJuego].nombre << " ===\n";
                    atenderSiguienteVisitante(datos.filasJuegos[idxJuego]);
                }
                break;
            }

            case 4: {
                imprimirTitulo("ESTADO GENERAL DE LAS FILAS");
                for (int i = 0; i < datos.cantJuegos; i++) {
                    int cantEnFila = 0;
                    NodoVisitante* aux = datos.filasJuegos[i].frente;
                    while (aux != nullptr) {
                        cantEnFila++;
                        aux = aux->siguiente;
                    }
                    cout << (i + 1) << ". " << datos.juegos[i].nombre
                         << " [Codigo: " << datos.juegos[i].codigo << "]: "
                         << cantEnFila << " visitantes en fila";
                    if (!datos.juegos[i].operativo) {
                        cout << " (FUERA DE SERVICIO)";
                    }
                    cout << "\n";
                }
                cout << "\n";
                break;
            }

            case 5:
                cout << "Regresando al Menu Principal...\n\n";
                opcionElegida = -1;
                break;
        }
    }
}
