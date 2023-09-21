#ifndef SOLVER_NONLINEAR_H
#define SOLVER_NONLINEAR_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include"matriz.h"

using namespace std;

// clase que resulve ecuaciones no lineales, contendrá newton en varias variables de momento
class Solver_nonlinear {
    private:
        vector<double> posiciones_iniciales; // valor inicial de las posiciones
        int dimension; // numero de variables que se recibe
    public:
        Solver_nonlinear(){};
        Solver_nonlinear(vector<double> posiciones_iniciales){
            this->posiciones_iniciales = posiciones_iniciales;
            this->dimension = posiciones_iniciales.size();
        };




        // se crea la función newton_varias_variables, la cual encuentra las raices de una función en varias variables
        vector<double> newton_varias_variables(vector<double> (*funcion)(vector<double>), vector<vector<double>> (*derivadas)(vector<double>), int iteraciones)
        {
            // creo un vector que contenga las coordenadas, esta variable será la iterada
            vector<double> coordenadas = posiciones_iniciales;

            for(int i = 0; i<iteraciones; i++){
                // encuentro el valor de la funcion en las coordenadas de la i-ésima iteracion
                vector<double> f = funcion(coordenadas);

                // encuentro el valor del jacobiano en las coordenadas de la i-ésima iteracion
                vector<vector<double>> jacobiano = derivadas(coordenadas);

                // uso mi clase matriz únicamente para encontrar la inversa del jacobiano
                Matriz<double> derivada_matriz(jacobiano);
                Matriz<double> inversa_derivada_matriz = inversa(derivada_matriz);

                // me devuelvo a los vectores
                vector<vector<double>> inversa_jacobiano = inversa_derivada_matriz.get();

                // aplico la formula del pdf del profesor Toledo para encontrar las raices en varias variables
                for(int j = 0; j<dimension; j++){
                    for(int k = 0; k < jacobiano.size(); k++) {
                        coordenadas[j] = coordenadas[j] - f[k]*inversa_jacobiano[j][k];
                    }
                }
            }
            
            return coordenadas;
        }


            

};

#endif