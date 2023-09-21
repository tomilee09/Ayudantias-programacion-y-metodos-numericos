#include<iostream>
#include<random>
#include<vector>
#include<cmath>
#include"integradores.h"

using namespace std;

// Ejemplo de función a integrar: f(x, y) = x^2 + y^2
double funcion(vector<double> variables)
{
    double resultado = 0;
    for(int i = 0; i<variables.size(); i++){
        resultado += variables[i]*variables[i];
    }
    return resultado;
}

// si lo que se desea calcular es un volumen, la funcion debe valer 1, y se debe cumplir con los bordes del volumen
double esfera(vector<double> variables)
{
    double resultado = 0;
    // bordes para una esfera radio 3
    if (variables[0]*variables[0] + variables[1]*variables[1] + variables[2]*variables[2] <= 9){ 
        resultado += 1; // suma solo 1 para solo calcular el volumen
    }
    else{
        resultado += 0; // si está afuera de la esfera no suma nada
    }
    return resultado;
}


int main()
{
    // pongo estos limites de integracion para el cálculo del volumen de la esfera
    vector<double> a{-3, -3, -3};  // Límite inferior
    vector<double> b{3, 3, 3};  // Límite superior
    int n_puntos = 100000;  // Número de muestras

    // realizo la integracion con el método de montecarlo
    Integradores mi_integrador(a, b);
    double resultado_integracion = mi_integrador.montecarlo(esfera, n_puntos);
    cout << resultado_integracion << endl;

    return 0;
}