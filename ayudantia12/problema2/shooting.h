#ifndef SHOOTING_H
#define SHOOTING_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include<random>


using namespace std;

class Shooting {
    private:
        // Parámetros del problema
        double x0;
        double x1;
        double y0;
        double y1_objetivo;
        double h;
        int n;
        double (*f)(double, double, double);
        
    public:
        Shooting(){};
        Shooting(double x0, double x1, double y0, double y1, double h, double (*f)(double, double, double)){
            // Parámetros del problema
            this->x0 = x0;
            this->x1 = x1;
            this->y0 = y0;
            this->y1_objetivo = y1;
            this->h = h;
            this->n = (x1-x0)/h;
            this->f = f;
        };



        // union de las cosas anteriores para obtener el mejor disparo
        vector<vector<double>> shooting_no_lineal(double u) {

            // devuelvo los datos
            return datos;
            
        }

};

#endif