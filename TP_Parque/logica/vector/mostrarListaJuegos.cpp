#include "structs/juego.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirTabla.h"
#include "utiles/copiarTexto.h"
#include "constantes/generales.h"
#include <iostream>

using namespace std;

void mostrarListaJuegos(Juego *listaJuegos, int cantJuegos){
    imprimirTitulo("Lista de Juegos");
    if(cantJuegos < 1){cout<<"No hay juegos en lista.\n";return;}

    char nombres[cantJuegos][LARGO_NOMBRE];
    int codigos[cantJuegos];

    for (int i = 0; i<cantJuegos; i++){
        copiarTexto(listaJuegos[i].nombre, nombres[i]);
        codigos[i] = listaJuegos[i].codigo;}
    imprimirTablaMonoColum("Codigo", nombres, codigos, cantJuegos);
    
    cout <<"Fin de lista de Juegos.\n\n";
    return;
}

void mostrarListaJuegosDisponibles(Juego *listaJuegos, int cantJuegos){
    imprimirTitulo("Lista de Juegos Disponibles");
    if(cantJuegos < 1){cout<<"No hay juegos en lista.\n";return;}

    int contador = 0;
    char nombres[cantJuegos][LARGO_NOMBRE];
    int  codigos[cantJuegos];

    for (int i = 0; i < cantJuegos; i++){
        if (listaJuegos[i].operativo){
            copiarTexto(listaJuegos[i].nombre, nombres[contador]);
            codigos[contador] = listaJuegos[i].codigo;
            contador++;
        }
    }

    if (contador > 0){
        imprimirTablaMonoColum("Codigo", nombres, codigos, contador);
        cout << "Hay " << contador << " juegos disponibles.\n\n";
    } else {
        cout << "No hay juegos disponibles.\n\n";
    }
} 
