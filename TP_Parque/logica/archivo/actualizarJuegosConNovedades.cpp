#include "logica/archivo/actualizarJuegosConNovedades.h"
#include "constantes/rutasArchivos.h"
#include "structs/novedad.h"
#include <fstream>
#include <iostream>

using namespace std;


static bool leerJuego(ifstream &archivo, Juego &juego) {
    archivo.read((char*)&juego, sizeof(Juego));
    return static_cast<bool>(archivo);
}

static bool leerNovedad(ifstream &archivo, Novedad &novedad) {
    archivo.read((char*)&novedad, sizeof(Novedad));
    return static_cast<bool>(archivo);
}

static void grabarJuego(ofstream &archivo, const Juego &juego) {
    archivo.write((char*)&juego, sizeof(Juego));
}


static void sinMaestro(ofstream &actualizado, const Novedad &novedad) {
    if (novedad.op == 'A') {
        grabarJuego(actualizado, novedad.datos);
        cout << "[ALTA] Se agrego el juego " << novedad.datos.codigo
             << " - " << novedad.datos.nombre << ".\n";
    } else {
        cout << "[ERROR] La novedad '" << novedad.op << "' del codigo "
             << novedad.datos.codigo << " no existe en el maestro.\n";
    }
}


static void conMaestro(ofstream &actualizado, const Juego &maestro, const Novedad &novedad) {
    if (novedad.op == 'B') {

        cout << "[BAJA] Se elimino el juego " << maestro.codigo << " - " << maestro.nombre << ".\n";
    } else if (novedad.op == 'M') {

        grabarJuego(actualizado, novedad.datos);
        cout << "[MODIFICACION] Se actualizo el juego " << novedad.datos.codigo
             << " - " << novedad.datos.nombre << ".\n";
    } else {

        cout << "[ERROR] El codigo " << maestro.codigo << " ya existe, no se puede dar de alta.\n";
        grabarJuego(actualizado, maestro);
    }
}

void actualizarJuegosConNovedades() {
    ifstream maestro(rutaArchivoJuegos, ios::binary);
    ifstream novedades(rutaArchivoNovedades, ios::binary);

    if (!maestro) {
        cout << "No se pudo abrir el maestro juegos.dat. Genera los datos de prueba primero.\n\n";
        return;
    }
    if (!novedades) {
        cout << "No se pudo abrir novedades.dat. Genera los datos de prueba primero.\n\n";
        maestro.close();
        return;
    }



    ofstream actualizado(rutaArchivoJuegosActualizados, ios::binary);
    if (!actualizado) {
        cout << "No se pudo crear el archivo temporal de actualizacion.\n\n";
        maestro.close();
        novedades.close();
        return;
    }


    Juego m;
    Novedad n;
    bool hayMaestro = leerJuego(maestro, m);
    bool hayNovedad = leerNovedad(novedades, n);


    while (hayMaestro && hayNovedad) {
        if (m.codigo < n.datos.codigo) {

            grabarJuego(actualizado, m);
            hayMaestro = leerJuego(maestro, m);
        } else if (n.datos.codigo < m.codigo) {

            sinMaestro(actualizado, n);
            hayNovedad = leerNovedad(novedades, n);
        } else {

            conMaestro(actualizado, m, n);
            hayMaestro = leerJuego(maestro, m);
            hayNovedad = leerNovedad(novedades, n);
        }
    }



    while (hayMaestro) {
        grabarJuego(actualizado, m);
        hayMaestro = leerJuego(maestro, m);
    }
    while (hayNovedad) {
        sinMaestro(actualizado, n);
        hayNovedad = leerNovedad(novedades, n);
    }

    maestro.close();
    novedades.close();
    actualizado.close();



    ifstream temporal(rutaArchivoJuegosActualizados, ios::binary);
    ofstream maestroNuevo(rutaArchivoJuegos, ios::binary);
    if (!temporal || !maestroNuevo) {
        cout << "No se pudo reemplazar el maestro actualizado.\n\n";
        if (temporal) temporal.close();
        return;
    }

    Juego j;
    while (leerJuego(temporal, j)) {
        grabarJuego(maestroNuevo, j);
    }

    temporal.close();
    maestroNuevo.close();

    cout << "Maestro de juegos actualizado correctamente.\n\n";
}
