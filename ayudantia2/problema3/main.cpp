#include <iostream>
#include <fstream>
// a los archivos se les debe llamar usando dobles comillas
#include "resorte.h"

using namespace std;

int main() {
    // creo un resorte con los siguientes parámetros
    Resorte mi_resorte(1, 0.1, 0.0, 10, 0.01);

    // guardo los datos por cada step de la simulación
    ofstream archivo("datos_x.txt");
    for (int i = 0; i< 1000; i++){
        mi_resorte.step(); // aqui avanzo un step
        archivo << mi_resorte.get_x() << endl;
    }

    // para graficar el archivo se debe abrir gnuplot en el directorio
    // donde se encuentra el archivo y poner:
    // plot "datos_x.txt" with lines
    return 0;
}