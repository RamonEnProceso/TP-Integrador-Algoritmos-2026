#include "logica/matriz/imprimirTotales.h"
#include "logica/matriz/totalPorJuego.h"
#include "logica/matriz/totalPorFranja.h"
#include "logica/matriz/totalOcupacion.h"
#include "utiles/outputs/imprimirTitulo.h"
#include "utiles/outputs/imprimirTabla.h"
#include "constantes/matrizConstantes.h"

void imprimirTotales(DatosParque datos){
    int totalJuegos[MAX_JUEGOS];
    int totalFranjas[FRANJAS_HORARIAS];

    totalPorJuego(datos.datosMatriz, totalJuegos);
    totalPorFranja(datos.datosMatriz, totalFranjas);
    int total = totalOcupacion(datos.datosMatriz);

    char* nombreColumna[1];
    nombreColumna[0] = (char*)"Visitas";

    imprimirTitulo("Total de visitas por juego");
    char* nombresFilasJuegos[MAX_JUEGOS];
    int* punterosJuegos[MAX_JUEGOS];
    for (int i = 0; i < datos.datosMatriz.juegos; i++){
        nombresFilasJuegos[i] = datos.juegos[i].nombre;
        punterosJuegos[i] = &totalJuegos[i];
    }
    Tabla tablaJuegos;
    tablaJuegos.columnas = 1;
    tablaJuegos.filas = datos.datosMatriz.juegos;
    tablaJuegos.nombresColumnas = nombreColumna;
    tablaJuegos.nombresFilas = nombresFilasJuegos;
    tablaJuegos.contenido = punterosJuegos;
    imprimirTabla(tablaJuegos);

    imprimirTitulo("Total de visitas por franja horaria");
    char* nombresFilasFranjas[FRANJAS_HORARIAS];
    int* punterosFranjas[FRANJAS_HORARIAS];
    for (int j = 0; j < datos.datosMatriz.franjas; j++){
        nombresFilasFranjas[j] = (char*)FRANJAS_TEXTO[j];
        punterosFranjas[j] = &totalFranjas[j];
    }
    Tabla tablaFranjas;
    tablaFranjas.columnas = 1;
    tablaFranjas.filas = datos.datosMatriz.franjas;
    tablaFranjas.nombresColumnas = nombreColumna;
    tablaFranjas.nombresFilas = nombresFilasFranjas;
    tablaFranjas.contenido = punterosFranjas;
    imprimirTabla(tablaFranjas);

    imprimirTitulo("Total de visitas del dia");
    char* nombreFilaTotal[1];
    int* punteroTotal[1];
    nombreFilaTotal[0] = (char*)"Total";
    punteroTotal[0] = &total;
    Tabla tablaTotal;
    tablaTotal.columnas = 1;
    tablaTotal.filas = 1;
    tablaTotal.nombresColumnas = nombreColumna;
    tablaTotal.nombresFilas = nombreFilaTotal;
    tablaTotal.contenido = punteroTotal;
    imprimirTabla(tablaTotal);
}
