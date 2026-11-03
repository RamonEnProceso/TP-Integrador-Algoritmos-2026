#include "logica/indice/buscarPorIndice.h"
#include "constantes/rutasArchivos.h"
#include "constantes/generales.h"
#include "constantes/visitantes.h"
#include "utiles/copiarTexto.h"
#include "structs/visitante.h"
#include <fstream>

using namespace std;

bool buscarPorIndice(int indice, Visitante& visitante) {
    if (indice < 1 || indice > MAX_PULSERAS) {
        return false;}
    ifstream archivoIndice(rutaArchivoIndice, ios::binary);
    if (!archivoIndice) return false;
    ifstream archivoVisitantes(rutaArchivoVisitantes, ios::binary);
    if (!archivoVisitantes) return false;

    int posicion = -1;

    archivoIndice.seekg((indice - 1) * sizeof(int), ios::beg);
    archivoIndice.read(reinterpret_cast<char*>(&posicion), sizeof(int));

    if (!archivoIndice || posicion < 0) {
        return false;}

    archivoVisitantes.seekg(posicion * sizeof(VisitanteArchivo), ios::beg);
    VisitanteArchivo reg;
    archivoVisitantes.read(reinterpret_cast<char*>(&reg), sizeof(VisitanteArchivo));
    if (!archivoVisitantes) {
        return false;}

    visitante.pulsera = reg.pulsera;
    copiarTexto(reg.nombre, visitante.nombre);
    visitante.edad = reg.edad;
    visitante.altura = reg.altura;
    visitante.historial = nullptr;

    return true;
}