#ifndef REGRESION_H
#define REGRESION_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include"matriz.h"

using namespace std;

// clase que tiene métodos para realizar regresiones, de momento solo contendrá una regresion lineal multivariable
class Regresion {
    private:
        // dataset con variables independientes y la variable dependiente (x_1, x_2, ..., x_n, y)
        vector<vector<double>> vector_dataset;  
    public:
        Regresion(){};
        Regresion(vector<vector<double>> vector_dataset){
            this->vector_dataset = vector_dataset;
        };

        // regresion linear multivariable
        vector<double> regresion_lineal() {
            // transformo el dataset en una matriz
            Matriz<double> dataset(vector_dataset);
            // orden representa el número de variables independientes
            int orden = dataset.columnas()-1;

            // creo la matriz X, que contendrá una columna con 1's (para encontrar el intercepto)
            // y contendrá todos los valores de las variables independientes x1, ..., x_n
            Matriz<double> X(dataset.filas(), orden+1);
            for(int i = 0; i<dataset.filas(); i++) {
                X(i, 0) = 1.; // pongo los 1's a la izquierda
                for(int j = 1; j<orden+1; j++){
                    X(i, j) = dataset(i, j-1); // pongo todas las variables independientes del dataset
                    // notese que si se tiene una columna con error, aqui se debe dividir por el error
                    // en ese caso, este X, es análogo a Y del pdf del profesor Toledo
                }
            }

            // creo la matriz y, que contendrá solo la variable independiente
            Matriz<double> y(dataset.filas(), 1);
            for(int i = 0; i<dataset.filas(); i++) {
                y(i, 0) = dataset(i, orden); // pongo la variable dependiente del dataset
                // notese que si se tiene una columna con error, aqui se debe dividir por el error
                // en ese caso, este y, es análogo a b del pdf del profesor Toledo
            }

            // se calculan las constantes de la regresion lineal con la formula del pdf del profesor Toledo
            Matriz<double> constantes_matriz = (inversa(transpuesta(X)*X)*transpuesta(X))*y;

            // paso de tener matrices a vectores, para solo usar vectores en el main, esto es a gusto personal
            vector<double> constantes;
            for(int i = 0; i<orden+1; i++) {
                constantes.push_back(constantes_matriz.get()[i][0]);
            }

            // regreso un vector con los valores de las constantes de la regresion lineal
            return constantes;
            
        }
            

};

#endif