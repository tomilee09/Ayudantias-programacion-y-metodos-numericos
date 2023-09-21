#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include"rk4.h"

using namespace std;

// funcion que será la ode a resolver
// uso un vector como input para poder tener una generalización para n variables 
// (aunque en este caso solo uso 4)
vector<double> derivada(vector<double> variables){ // t, x, y, z
    vector<double> derivadas;

    double derivada_x = cos(variables[2]);
    double derivada_y = -sin(variables[1]);
    double derivada_z = 1;

    derivadas.push_back(derivada_x);
    derivadas.push_back(derivada_y);
    derivadas.push_back(derivada_z);

    return derivadas;
}


int main() {
    // aqui puede ser cualquier valor inicial en teoría
    vector<double> posicion = vector{0., 0., 0.}; 

    // inicializo un objeto de la clase con la ode a resolver
    Rk4<double> mi_ode(derivada, posicion, 0., 10., 0.5);
    
    // guardo los puntos obtenidos en rk4.dat
    mi_ode.rk4("rk4.dat");
    return 0;
}