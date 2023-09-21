#ifndef LINEA_H
#define LINEA_H

#include<iostream>
#include<vector>
#include"punto.h"

using namespace std;

template <class T>
class Linea {
    private:
        Punto<T> punto1;
        Punto<T> punto2;
        vector<Punto<T>> puntos;
        T n_puntos = 3;
    public:
        Linea(){};
        // une los puntos más cercanos en una figura cualquiera
        Linea(Punto<T> punto1, Punto<T> punto2){
            this->punto1 = punto1;
            this->punto2 = punto2;

            T n_puntos = 3; // incluye al punto final
            for(T i = 0; i <= n_puntos; i++) {
                Punto<T> punto_intermedio = punto1 + (punto2-punto1)/n_puntos*i;
                puntos.push_back(punto_intermedio);
            }
        };

        // traslacion
        void operator+=(Punto<T> traslacion) {
            punto1 = punto1 + traslacion;
            punto2 = punto2 + traslacion;
            for(int i = 0; i < n_puntos+2; i++) {
                puntos[i] = puntos[i] + traslacion;
            }
        }
};

#endif