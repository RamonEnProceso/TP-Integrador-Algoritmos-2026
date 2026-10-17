#include "logica/archivo/exportarReporteDia.h"
#include "constantes/rutasArchivos.h"
#include "constantes/matrizConstantes.h"
#include "logica/matriz/totalPorJuego.h"
#include "logica/matriz/totalPorFranja.h"
#include "logica/matriz/totalOcupacion.h"

#include <fstream>
#include <iostream>

using namespace std;

void exportarReporteDia(DatosParque &datos) {

    ofstream archivo(rutaArchivoReporteDia);

    if (!archivo) {
        cout << "No se pudo crear el reporte.\n\n";
        return;
    }

    int totalJuegos[MAX_JUEGOS];
    int totalFranjas[FRANJAS_HORARIAS];

    totalPorJuego(datos.datosMatriz, totalJuegos);
    totalPorFranja(datos.datosMatriz, totalFranjas);

    archivo << "REPORTE DEL DIA\n";
    archivo << "====================\n\n";

    archivo << "VISITAS POR JUEGO\n";
    archivo << "--------------------\n";

    for (int i = 0; i < datos.datosMatriz.juegos; i++) {
        archivo << datos.juegos[i].nombre
                << ": "
                << totalJuegos[i]
                << " visitas\n";
    }

    archivo << "\n";

    archivo << "VISITAS POR FRANJA HORARIA\n";
    archivo << "--------------------\n";

    for (int j = 0; j < datos.datosMatriz.franjas; j++) {
        archivo << FRANJAS_TEXTO[j]
                << ": "
                << totalFranjas[j]
                << " visitas\n";
    }

    archivo << "\n";

    int total = totalOcupacion(datos.datosMatriz);

    archivo << "TOTAL DE VISITAS DEL DIA: "
            << total
            << "\n";

    archivo.close();

    cout << "Reporte generado correctamente.\n\n";
}