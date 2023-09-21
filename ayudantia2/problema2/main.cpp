#include <iostream>
// a los archivos se les debe llamar usando dobles comillas
#include "matriz.h"

using namespace std;

int main() {
    // creo 2 matrices llamadas mi_matriz y otra_matriz
    Matriz mi_matriz(1, 2, 3, 4);
    Matriz otra_matriz(5, 6, 7, 8);
    mi_matriz.print();

    // probando la sobrecarga de la suma
    Matriz suma = mi_matriz + otra_matriz;
    suma.print();

    // probando la sobrecarga de la multiplicación entre matrices
    Matriz mult = mi_matriz * otra_matriz;
    mult.print();

    double x = mi_matriz(1, 1);

    // probando la sobrecarga de la multiplicación por escalar
    Matriz mult_escalar = mi_matriz * 100.;
    mult_escalar.print();
    return 0;
}