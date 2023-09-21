#ifndef PARTICULA_H
#define PARTICULA_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include <fstream>

using namespace std;

class Particula {
    private: 
        double x;
        double y;
        double v_x;
        double v_y;
        vector<double> direccion;
        double borde_x;
        double borde_y;
        double modulo_velocidad;
    public:
        Particula(){};
        Particula(double borde_x, double borde_y, double modulo_velocidad){
            this->borde_x = borde_x;
            this->borde_y = borde_y;
            this->modulo_velocidad = modulo_velocidad;

            // creo las posiciones iniciales de forma aleatoria, en el rango [0, borde]
            x = (rand()%1000)/1000. * borde_x;
            y = (rand()%1000)/1000. * borde_y;

            // creo la direccion del movimiento de la particula
            // dado que es una direccion puede ser positiva o negativa
            double direccion_x = 2*(rand()%1000)/1000. - 1.;
            double direccion_y = 2*(rand()%1000)/1000. - 1.;
            // normalizo para tener un vector unitario de direccion
            double modulo = sqrt(direccion_x*direccion_x + direccion_y*direccion_y);
            direccion_x = direccion_x/modulo;
            direccion_y = direccion_y/modulo;
            direccion.push_back(direccion_x);
            direccion.push_back(direccion_y);

            // calculo la velocidad en cada direccion
            v_x = modulo_velocidad*direccion_x;
            v_y = modulo_velocidad*direccion_y;
        };

        void step() {
            // impongo la condicion de que no se puede salir de la caja
            if(x > borde_x) {
                v_x *= -1.;
            }
            if(x < 0) {
                v_x *= -1.;
            }
            if(y > borde_y) {
                v_y *= -1.;
            }
            if(y < 0) {
                v_y *= -1.;
            }

            // hago que las particulas avancen con la ecuacion del itinerario
            // (dt = 0.1)
            x += v_x*0.1;
            y += v_y*0.1;
        }

        double get_x() {
            return x;
        }

        double get_y() {
            return y;
        }

        double get_v_x() {
            return v_x;
        }

        double get_v_y() {
            return v_y;
        }
};

#endif