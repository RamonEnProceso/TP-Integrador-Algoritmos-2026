#include "utiles/outputs/imprimirDatos.h"
#include <iostream>

using namespace std;

void imprimirDatos(char **texto, int **datos, int total){
    for(int i = 0; i <total;i++){
        cout<<texto[i]<<": "<<datos[i]<<endl;
    }
}
