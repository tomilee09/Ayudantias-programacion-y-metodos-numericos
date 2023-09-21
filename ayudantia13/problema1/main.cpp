#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "shooting.h"

using namespace std;

/**
 * se desea resolver una ecuación diferencial
 * donde f = y'' = x^2*y - 11*y
 * se toman los puntos (x0, y0), (x1, y1_objetivo)
*/

// Definicion de la ecuación diferencial
double f(double x, double y, double u) {
    return x * x * y - 11 * y;
}

int main() {
    // se definen los puntos que se usarán
    double x0 = -5.5;
    double x1 = 5.5;
    double y0 = 0.857763884960710;
    double y1_objetivo = -0.857763884960710;
    double dx = 0.0001; // se usa un dx muy pequeño porque sino no funciona

    // se define un objeto de la función shooting
    Shooting solucion(x0, x1, y0, y1_objetivo, dx, f);
    
    // se usa el método shooting_no_lineal(), el argumento es el primer u=y' que se da
    // luego dentro de la función se encontrará un mejor u=y'
    vector<vector<double>> datos = solucion.shooting_no_lineal(1);

    // se guardan los datos
    ofstream archivo("solucion.txt");
    for(int i = 0; i<datos[0].size(); i++){
        archivo << datos[0][i] << " " << datos[1][i] << "\n";
    }
    archivo.close();

    return 0;
}