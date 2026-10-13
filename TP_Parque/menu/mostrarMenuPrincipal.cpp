#include "menu/mostrarMenuPrincipal.h"
#include "logica/cola/encolarVisitante.h"
#include "logica/cola/mostrarFilaJuego.h"
#include "logica/cola/atenderSiguienteVisitante.h"
#include "menu/mostrarMenuJuegos.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirConNum.h"
#include "menu/mostrarMenuVisitantes.h"
#include "menu/mostrarMenuOcupacion.h"
#include "structs/datosParque.h"
#include "logica/generarPrueba/generarDatosPrueba.h"
#include <iostream>

using namespace std;

void mostrarMenuPrincipal(DatosParque &datos){
    int opcionElegida = 0;

    while (opcionElegida != -1)
    {
        opcionElegida = 0;
        imprimirTitulo("Menu Principal");
        imprimirConNumero(1,"Gestionar Visitantes");
        imprimirConNumero(2,"Gestionar Juegos");
        imprimirConNumero(3,"Gestionar Ocupacion de juegos");
        imprimirConNumero(4,"Generar Datos De Prueba");
        imprimirConNumero(5,"Salir del programa");
        imprimirConNumero(9,"[TEST] Probar Colas (Entrega 2)");

        while ((opcionElegida < 1 || opcionElegida > 5) && opcionElegida != 9){
            cout << "Ingresa el numero de opcion elegida: "; cin >> opcionElegida; cout<<endl;
            if ((opcionElegida < 1 || opcionElegida > 5) && opcionElegida != 9){
                cout << "Numero incorrecto. Ingrese uno correcto.\n";
            }
        };


        switch (opcionElegida)
        {
        case 1:
            mostrarMenuVisitantes(datos.listaVisitantes);
            break;
        case 2:
            mostrarMenuJuegos(datos.juegos);
            break;
        case 3:
            mostrarMenuOcupacion(datos);
            break;
        case 4:
            generarDatosPrueba(datos);
            break;
        case 5:
            cout << "\nHasta luego ;)\n\n";
            opcionElegida = -1;
            break;
        case 9: {
            Cola filaMontaniaRusa = {nullptr, nullptr};
            Visitante v1 = {1001, "Joaquin", 20, 1.75f};
            Visitante v2 = {1002, "Ramiro", 21, 1.80f};
            cout << "--- ENCOLANDO VISITANTES ---\n";
            encolarVisitante(filaMontaniaRusa, v1);
            encolarVisitante(filaMontaniaRusa, v2);
            mostrarFilaJuego(filaMontaniaRusa);
            cout << "--- ATENDIENDO AL PRIMERO ---\n";
            atenderSiguienteVisitante(filaMontaniaRusa);
            mostrarFilaJuego(filaMontaniaRusa);
            break;
        }
        }
    }

    return;
};
