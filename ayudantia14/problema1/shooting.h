#ifndef SHOOTING_H
#define SHOOTING_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include<random>


using namespace std;

// clase que resuelve el método de shooting no lineal
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



        // funcion de shooting no lineal que se usa en el problema
        // me defino cosas más abajo que uso en la función
        // resumen: se define una función shoot para encontrar donde choca en x
        //          se define la función a minimizar
        //          se realiza la minimización con el método de la bisección y se encuentra el mejor u
        //          (es decir, con el u con el cual se choca en y1_objetivo)
        vector<vector<double>> shooting_no_lineal() {
            
            // se encuentra el mejor y'=u
            double u_bueno = biseccion_disparo(-100, 1000, 1e-7);

            // se realiza un último disparo donde se guardan los puntos intermedios
            vector<vector<double>> datos = shoot_save(x0, y0, u_bueno, f);

            // devuelvo los datos
            return datos;
            
        }

        // función shoot aplica un método de resolución de ode (en este caso uso euler)
        double shoot(double x0, double y0, double u0, double (*f)(double, double, double)){
            double x = x0;
            double y = y0;
            double u = u0;
            double y_next;
            double u_next;

            // se aplica el método de euler desde x0 hasta x1
            for(int i = 0; i<n; i++){
                u_next = u + h*f(x, y, u);
                y_next = y + h*u;

                x = x+h;
                y=y_next;
                u=u_next;
            }

            // se devuelve el y1 objetivo
            return y;
        }

        // se define la función a minimizar
        // es la altura a la cual se llega con el shoot pero ahora se le resta y1_objetivo
        // con lo anterior la minimización encuentra el u tal que se llega a y1_objetivo
        double shoot_con_objetivo(double u_posible) {
            double y1 = shoot(x0, y0, u_posible, f);
            double diferencia = y1-y1_objetivo;
            return diferencia;
        }

        // se realiza la minimización mediante bisección
        double biseccion_disparo(double a, double b, double epsilon) {
            double fa = shoot_con_objetivo(a);
            double fb = shoot_con_objetivo(b);

            while( abs(b-a) >epsilon ){
                double c = (a+b)/2.;
                double fc = shoot_con_objetivo(c);

                if(fa*fc>0){
                    a = c;
                    fa = fc;
                }
                else{
                    b=c;
                    fb=fc;
                }
            }
            return (a+b)/2;
        }

        // es igual a la función shoot pero ahora guardan los datos
        vector<vector<double>> shoot_save(double x0, double y0, double u0, double (*f)(double, double, double)) {
            vector<vector<double>> datos;
            vector<double> datos_x;
            vector<double> datos_y;

            double x = x0;
            double y = y0;
            double u = u0;

            for(int i = 0; i < n; i++){
                double u_next = u+h*f(x, y, u);
                double y_next = y+h*u;

                datos_x.push_back(x);
                datos_y.push_back(y);

                x = x+h;
                y = y_next;
                u = u_next;
            }
            datos.push_back(datos_x);
            datos.push_back(datos_y);
            return datos;
        }

};

#endif