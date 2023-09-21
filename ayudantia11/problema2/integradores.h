#ifndef INTEGRADORES_H
#define INTEGRADORES_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include<random>


using namespace std;

// Extension de clase integradores (ayudantia 10), ahora se integra con montecarlo
class Integradores {
    private:
        vector<double> limites_inferiores;
        vector<double> limites_superiores;
        int dimension;
        
    public:
        Integradores(){};
        Integradores(vector<double> limites_inferiores, vector<double> limites_superiores){
            this->limites_inferiores = limites_inferiores;
            this->limites_superiores = limites_superiores;
            this->dimension = limites_inferiores.size();
        };

        // Función de integración en múltiples variables
        double montecarlo(double (*f)(vector<double>), int n_puntos){
            // uso la funcion que me permite encontrar números aleatorios con mersenne twister
            // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
            random_device rd;
            mt19937 gen(rd());
            uniform_real_distribution dis(0., 1.);

            // sigo el método de integracion con montecarlo
            // https://en.wikipedia.org/wiki/Monte_Carlo_integration
            
            // primero calculo el promedio de la funcion
            double sumatoria = 0.0;
            vector<double> punto(dimension);
            for(int i = 0; i<n_puntos; i++) {
                for(int j = 0; j<dimension; j++){
                    punto[j] = limites_inferiores[j] + (limites_superiores[j]-limites_inferiores[j])*dis(gen);
                }
                sumatoria += f(punto);
            }
            double promedio = sumatoria/n_puntos;

            // ahora calculo el volumen de todo el sistema en el cual se integra
            double volumen = 1;
            for(int i = 0; i<dimension; i++){
                volumen = volumen*(limites_superiores[i]-limites_inferiores[i]);
            }

            // la integral es el promedio de la funcion por el volumen
            double resultado = volumen*promedio;
            return resultado;
        }

};

#endif