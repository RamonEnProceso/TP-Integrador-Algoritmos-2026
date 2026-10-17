#include "logica/archivo/generarNovedadesDePrueba.h"
#include "constantes/rutasArchivos.h"
#include "structs/novedad.h"
#include <fstream>

using namespace std;

void generarNovedadesDePrueba() {






    Novedad novedades[] = {
        { { 2,  "Rueda de la Fortuna",  0, 1.20f, 32, false, {0,0,0,0,0} }, 'B' },
        { { 3,  "Autitos Chocadores",   0, 1.10f, 40, true,  {0,0,0,0,0} }, 'M' },
        { { 11, "Sillas Voladoras",     0, 1.30f, 18, true,  {0,0,0,0,0} }, 'A' },
        { { 99, "",                     0, 0.0f,  0,  false, {0,0,0,0,0} }, 'M' },
    };

    ofstream archivo(rutaArchivoNovedades, ios::binary);
    if (!archivo) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        archivo.write((char*)&novedades[i], sizeof(Novedad));
    }

    archivo.close();
}
