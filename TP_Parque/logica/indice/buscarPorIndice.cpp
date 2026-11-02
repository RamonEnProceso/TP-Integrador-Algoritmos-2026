
#include "logica/indice/buscarPorIndice.h"
#include "constantes/rutasArchivos.h"
#include "constantes/generales.h"
#include "structs/visitante.h"
#include <fstream>

using namespace std;

bool buscarPorIndice(int pulsera, Visitante& visitante) {

    // Verificar que la pulsera este dentro del rango.
    if (pulsera < 1 || pulsera > MAXP) {
        return false;
    }

    // 1. Abrir los archivos.
    ifstream archivoIndice(rutaArchivoIndice, ios::binary);

    if (!archivoIndice) {
        return false;
    }

    ifstream archivoVisitantes(rutaArchivoVisitantes, ios::binary);

    if (!archivoVisitantes) {
        archivoIndice.close();
        return false;
    }

    int posicion;

    // 2. Saltar directamente al casillero de la pulsera.
    archivoIndice.seekg(
        (pulsera - 1) * sizeof(int),
        ios::beg
    );

    archivoIndice.read(
        (char*)&posicion,
        sizeof(int)
    );

    if (!archivoIndice) {
        archivoIndice.close();
        archivoVisitantes.close();
        return false;
    }

    // 3. Comprobar si la pulsera fue utilizada.
    if (posicion == -1) {
        archivoIndice.close();
        archivoVisitantes.close();
        return false;
    }

    // 4. Saltar directamente al registro del visitante.
    archivoVisitantes.seekg(
        posicion * sizeof(VisitanteArchivo),
        ios::beg
    );

    VisitanteArchivo reg;

    archivoVisitantes.read(
        (char*)&reg,
        sizeof(VisitanteArchivo)
    );

    if (!archivoVisitantes) {
        archivoIndice.close();
        archivoVisitantes.close();
        return false;
    }

    archivoIndice.close();
    archivoVisitantes.close();

    // 5. Recuperar los datos del visitante.
    visitante.pulsera = reg.pulsera;

    for (int k = 0; k < LARGO_NOMBRE; k++) {
        visitante.nombre[k] = reg.nombre[k];
    }

    visitante.edad = reg.edad;
    visitante.altura = reg.altura;
    visitante.historial = nullptr;

    return true;
}
