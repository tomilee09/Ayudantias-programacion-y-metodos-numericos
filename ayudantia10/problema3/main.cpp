#include <iostream>
#include <vector>
#include <cmath>
#include "regresion.h"
#include "matriz.h"

using namespace std;

/** 
 * Encontrar las constantes de regresion linear de algun set de datos 
*/

int main() {
    // datos para la regresion linear con solo una variable
    // x, y
    vector<vector<double>> puntos = {
        {1.0, 1.7},
        {2.0, 2.8},
        {3.0, 3.3},
        {4.0, 4.6},
        {5.0, 5.2},
        {6.0, 6.7},
        {7.0, 7.9},
        {8.0, 8.1},
        {9.0, 9.4},
        {10.0, 10.3}
    };

    // datos para la regresion linear con dos variables
    // x1, x2, y
    vector<vector<double>> puntos_2_variables = {
        {1.0, 1.7, 1.7},
        {2.0, 2.8, 2.8},
        {3.0, 3.3, 3.3},
        {4.0, 4.6, 4.6},
        {5.0, 5.2, 5.2},
        {6.0, 6.7, 3.7}, // <--- aqui el único dato que cambié
        {7.0, 7.9, 7.9},
        {8.0, 8.1, 8.1},
        {9.0, 9.4, 9.4},
        {10.0, 10.3, 10.3}
    };
    // nota: dado que los datos son casi iguales, una de las 2 pendientes será muy baja,
    // significa que los datos pueden representarse con solo una variable

    // regresion linear para datos con solo una variable
    Regresion mi_regresion(puntos);
    vector<double> constantes_regresion = mi_regresion.regresion_lineal();
    cout << "intercepto: " << constantes_regresion[0] << ", pendiente: " << constantes_regresion[1] << endl;

    // regresion linear para datos con 2 variables, por lo que entrega un intercepto y dos pendientes
    Regresion mi_regresion2(puntos_2_variables);
    vector<double> constantes_regresion2 = mi_regresion2.regresion_lineal();
    cout << "intercepto: " << constantes_regresion2[0] << ", pendiente1: " << constantes_regresion2[1] 
                                                        << ", pendiente2: " << constantes_regresion2[2] << endl;

    return 0;
}