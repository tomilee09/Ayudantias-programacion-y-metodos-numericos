#ifndef PARTICULA_BROWNIANA_H
#define PARTICULA_BROWNIANA_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include <fstream>

using namespace std;

class Particula_browniana {
    private: 
        double x;
        double y;
        double largo_paso;
    public:
        Particula_browniana(){};
        Particula_browniana(double largo_paso){
            this->x = 0;
            this->y = 0;
            this->largo_paso = largo_paso;
        };

        // esta es la parte de la aleatoriedad
        void step() {
            // le pido que me entregue un  número aleatorio
            // este número le pido que esté entre 0 y 3
            int decision = rand()%4;
            // los 4 números serán las direcciones en las cuales moverse
            // ej: si es 0 avanza en x
            if(decision == 0) {
                x += largo_paso;
            }
            if(decision == 1) {
                x -= largo_paso;
            }
            if(decision == 2) {
                y += largo_paso;
            }
            if(decision == 3) {
                y -= largo_paso;
            }
        }

        double get_x() {
            return x;
        }

        double get_y() {
            return y;
        }
};

#endif