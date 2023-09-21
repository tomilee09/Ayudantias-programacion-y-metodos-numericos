#ifndef INTEGRADORES_H
#define INTEGRADORES_H

#include<vector>
#include<cstdlib>
#include<iostream>
#include"matriz.h"

using namespace std;

// clase que contiene cuadraturas, al crearlo contiene el intervalo de integracion
// contiene cuadratura de romberg, trapecio y gauss_legendre
class Integradores {
    private:
        double posicion_inicial;
        double posicion_final;
    public:
        Integradores(){};
        Integradores(double posicion_inicial, double posicion_final){
            this->posicion_inicial = posicion_inicial;
            this->posicion_final = posicion_final;
        };

        // cuadratura con regla del trapecio
        double trapecio(double (*funcion)(double), double pasos) {
            double resultado = 0;

            // posicion será la variable a iterar, comienza en el limite inferior del intervalo de integracion
            double posicion = posicion_inicial;
            
            // es el mismo h mostrado en el pdf del profesor Toledo
            double h = (posicion_final-posicion_inicial)/pasos;
            
            // se itera la posicion hasta que llega al limite superior del intervalo de integracion
            while(posicion<posicion_final){
                // se sigue la formula del pdf del profesor Toledo
                double promedio = (funcion(posicion)+funcion(posicion+h))/2;
                double integracion_i = h*promedio;
                resultado += integracion_i;
                posicion = posicion+h;
            }
            return resultado;
        }

        // cuadratura de romberg 
        double romberg(double (*f)(double), double pasos) {
            // cambio los nombres de las variables porque las formulas son largas
            double n = pasos;
            double a = posicion_inicial;
            double b = posicion_final;

            // es el h definido en el pdf del profesor Toledo para romberg
            double h = (b-a)/(pow(2, n));

            // creo una matriz llena de ceros 
            Matriz<double> R(n, n); // esta forma de inicializar la definí en mi clase matrices

            // creo la primera iteracion de la cuadratura
            // notemos que es literalmente la regla del trapecio (ver imagen romberg.png)
            R(0, 0) = (b-a) * (f(a)+f(b))/2;
            
            // se procede a realizar las iteraciones con el método de romberg
            // sigo lo realizado en https://en.wikipedia.org/wiki/Romberg%27s_method
            for(int i = 1; i<n; i++){
                double sumatoria = 0;
                
                // calculo los elementos de la izquierda (se usa aceleracion de Richardson)
                for(int k = 1; k<pow(2, n-1); k++){
                    sumatoria = sumatoria + f(a+(2*k-1)*h);
                }
                R(i, 0) = 0.5*R(i-1, 0) + h*sumatoria;

                // calculo los elementos que van hacia la derecha de la matriz hasta la diagonal
                for(int j = 1; j<n; j++){
                    R(i, j) = R(i, j-1)+(1./(pow(4, j)-1))*(R(i, j-1)-R(i-1, j-1));
                }       
            }
            // se entrega el valor de la última diagonal
            return R(n-1, n-1);

        }

        // cuadratura de gauss-legendre
        double gauss_legendre(double (*f)(double), double pasos) {
            // se agregan los pesos y los puntos en los cuales se usan 
            // solo deben buscarlos/calcularlos y dejarlos ahí
            double peso1 = 0.568889;
            double peso2 = 0.478629;
            double peso3 = 0.236927;
            double punto1 = 0.;
            double punto2 = 0.538469;
            double punto3 = -0.538469;
            double punto4 = 0.90618;
            double punto5 = -0.90618;

            // se sigue la formula sacada de https://es.wikipedia.org/wiki/Cuadratura_de_Gauss
            double h = (posicion_final-posicion_inicial)/2;
            double promedio = (posicion_final+posicion_inicial)/2;
            return h*(peso1*f(h*punto1 + promedio) 
                    + peso2*f(h*punto2 + promedio) 
                    + peso2*f(h*punto3 + promedio) 
                    + peso3*f(h*punto4 + promedio) 
                    + peso3*f(h*punto5 + promedio));
        }
            

};

#endif