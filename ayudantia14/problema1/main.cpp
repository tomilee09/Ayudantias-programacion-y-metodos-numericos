#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "shooting.h"

using namespace std;

/**
 * se desea resolver una ecuación diferencial
 * donde f = y''
 * se toman los puntos (x0, y0), (x1, y1_objetivo)
*/

double ecuacion(double x, double y, double u) {
    return (-u*x-y);
}

double exponencial(double x, double y, double u) {
    return y;
}

double exponencial_imaginaria(double x, double y, double u) {
    return -y;
}

int main() {
    double dx = 0.0001; 

    // puntos de ecuacion
    // double x0 = 0.0;
    // double x1 = 2.4048;
    // double y0 = 1.;
    // double y1_objetivo = 0.;

    // puntos de exponencial
    // double x0 = 0.;
    // double x1 = 2.;
    // double y0 = 1.;
    // double y1_objetivo = 7.39;

    // puntos de exponencial_imaginaria
    double x0 = 0.;
    double x1 = 3.1415;
    double y0 = 0.;
    double y1_objetivo = 0.;

    // se define un objeto de la función shooting
    Shooting solucion(x0, x1, y0, y1_objetivo, dx, exponencial_imaginaria);
    
    // se usa el método shooting_no_lineal(), el argumento es el primer u=y' que se da
    // luego dentro de la función se encontrará un mejor u=y'
    vector<vector<double>> datos = solucion.shooting_no_lineal();

    // se guardan los datos
    ofstream archivo("solucion.txt");
    for(int i = 0; i<datos[0].size(); i++){
        archivo << datos[0][i] << " " << datos[1][i] << "\n";
    }
    archivo.close();

    return 0;
}