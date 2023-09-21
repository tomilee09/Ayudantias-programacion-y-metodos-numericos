#include <iostream>
#include <vector>
#include <cmath>
#include "solver_nonlinear.h"
#include "matriz.h"

using namespace std;

/** Queremos resolver el siguiente sistema no lineal:
 * x1*x2 - 1 = 0 
 * x3*x1 - 3 = 0 
 * x2*x3 - 5 = 0 
*/

// Funcion en 3d que representa al sistema de ecuaciones
vector<double> funcion_3d(vector<double> coordenadas)
{
    double x1 = coordenadas[0];
    double x2 = coordenadas[1];
    double x3 = coordenadas[2];

    vector<double> nuevas_coordenadas;
    nuevas_coordenadas.push_back(x1*x2-1);
    nuevas_coordenadas.push_back(x3*x1-3);
    nuevas_coordenadas.push_back(x2*x3-5);
    return nuevas_coordenadas;
}

// función que entrega un vector de vectores de la jacobiana de la funcion_3d anterior 
vector<vector<double>> jacobiano(vector<double> coordenadas)
{
    double x1 = coordenadas[0];
    double x2 = coordenadas[1];
    double x3 = coordenadas[2];
    
    vector<vector<double>> jacobina;
    
    // estas van a ser las columnas de mi matriz jacobiana
    vector<double> nuevas_coordenadas1;
    vector<double> nuevas_coordenadas2;
    vector<double> nuevas_coordenadas3;

    // derivadas primera ecuacion respecto a x1, x2, x3
    nuevas_coordenadas1.push_back(x2);
    nuevas_coordenadas1.push_back(x1);
    nuevas_coordenadas1.push_back(0.);
    jacobina.push_back(nuevas_coordenadas1);
    
    // derivadas segunda ecuacion respecto a x1, x2, x3
    nuevas_coordenadas2.push_back(x3);
    nuevas_coordenadas2.push_back(0.);
    nuevas_coordenadas2.push_back(x1);
    jacobina.push_back(nuevas_coordenadas2);

    // derivadas tercera ecuacion respecto a x1, x2, x3
    nuevas_coordenadas3.push_back(0.);
    nuevas_coordenadas3.push_back(x3);
    nuevas_coordenadas3.push_back(x2);
    jacobina.push_back(nuevas_coordenadas3);

    // devuelvo la matriz jacobiana
    return jacobina;
}

int main() {
    // punto inicial en 3D
    vector<double> posiciones_iniciales = {3, 2, 3};

    // resolucion del sistema de ecuaciones con newton en varias variables
    Solver_nonlinear mi_solver3d(posiciones_iniciales);
    vector<double> solucion = mi_solver3d.newton_varias_variables(funcion_3d, jacobiano, 100);
    cout << "x1: " << solucion[0] << ", x2: " << solucion[1] << ", x3: " << solucion[2] << endl; 

    return 0;
}