#include "logica/nodo/crearListaNodo.h"
#include "logica/nodo/agregarVisitanteLista.h"
#include "constantes/rutasArchivos.h"
#include "utiles/copiarTexto.h"
#include "structs/nodoVisitante.h"
#include <fstream>

NodoVisitante* crearLista (){
    NodoVisitante* lista = nullptr;
    std::ifstream archivo(rutaArchivoVisitantes, std::ios::binary);
    if (!archivo) return nullptr;
    VisitanteArchivo reg;
    while (archivo.read((char*)&reg, sizeof(VisitanteArchivo))) {
        Visitante v{};
        v.pulsera = reg.pulsera;
        copiarTexto(reg.nombre, v.nombre);
        v.edad = reg.edad;
        v.altura = reg.altura;
        v.historial = nullptr;
        lista = agregarVisitanteLista(v, lista);
    }
    return lista;
}
