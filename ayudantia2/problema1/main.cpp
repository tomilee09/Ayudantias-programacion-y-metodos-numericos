#include <iostream>
// a los archivos se les debe llamar usando dobles comillas
#include "fraccion.h"

using namespace std;

int main() {
    // creación de una fracción llamada mi_fraccion, que es 3/6
    Fraccion mi_fraccion(3, 6);

    // muestro la fracción anterior en pantalla
    mi_fraccion.print();

    // simplifico la fracción
    mi_fraccion.simplicar();
    mi_fraccion.print();
    
    // creo otra_fraccion
    Fraccion otra_fraccion(4, 5);
    
    // probando la sobrecarga de la suma
    Fraccion suma = mi_fraccion + otra_fraccion;
    suma.print();

    // probando la sobrecarga de la multiplicación entre fracciones
    Fraccion mult = mi_fraccion * otra_fraccion;
    mult.print();

    // probando la sobrecarga de la multiplicación por escalar
    Fraccion mult_escalar = mi_fraccion*100;
    mult_escalar.print();


    return 0;
}