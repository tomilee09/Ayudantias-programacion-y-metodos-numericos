#ifndef GEOMETRIA_H
#define GEOMETRIA_H

#include<iostream>
#include<vector>
#include"linea.h"

using namespace std;

template <class T>
class Geometria {
    private:
        vector<Punto<T>> puntos;
        // vector<Linea<T>> lineas;
    public:
        Geometria(){};
        // une los puntos más cercanos en una figura cualquiera
        Geometria(vector<Punto<T>> puntos){
            this->puntos = puntos;

            // for(T i = 0; i <= puntos.size(); i++) {
            //     if(i == puntos.size()) {
            //         Linea mi_linea(puntos[i], puntos[0]);
            //         lineas.push_back(mi_linea);
            //     }
            //     else {
            //         Linea mi_linea(puntos[i], puntos[i+1]);
            //         lineas.push_back(mi_linea);
            //     }
            // }

        };

        // // traslacion
        // void operator+=(Punto<T> traslacion) {
        //     for(int i = 0; i < puntos.size(); i++) {
        //         puntos[i] += traslacion;
        //     }
            
        //     for(int i = 0; i < lineas.size(); i++) {
        //         for(int j = 0; j < lineas[i].size(); j++) {
        //             lineas[i][j] += traslacion;
        //         }
        //     }
        // }
};

#endif