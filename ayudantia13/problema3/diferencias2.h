#ifndef DIFERENCIAS_H
#define DIFERENCIAS_H

#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

// Clase para aplicar diferencias finitas
class Diferencias2 {
    private:
        // Parámetros del problema
        double alpha; // el valor de la constante c² o k de las ecuaciones diferenciales del pdf que subí
        double dx; // tamaño paso en x
        double dt; // parametro que deben cambiar si les da algo raro, usar un dt chico
        int numX; // numero de elementos en x
        int numT; // numero de elementos en t
        vector<vector<double>> datos; // tensor que guardará todos los datos que salen de la diferencia finita
        
    public:
        // Diferencias(){};
        Diferencias2(){ // no le pongo datos de entrada, los defino todos directamente aquí solo por mi comodidad
            // Parámetros del problema
            this->alpha = 1;
            this->dx = 0.1;
            this->dt = dx*dx*dx*dx*dx*dx*dx/4.; // tal vez necesiten que sea más chico para que no de cosas raras, o más grande para avanzar más en el tiempo
                                 // hay que buscar el equilibrio
            this->numX = 100;
            this->numT = 1000;
        };

        // Función para resolver diferencias finitas en 1 dimension espacial y una temporal
        void diferencias_finitas_1D(double (*Forzante)(double, double)) {

            // creo un vector de vectores de vectores
            // inicializo todos los elementos a 0, asi que si no impongo otras condiciones, la condicion inicial es que todo sea 0
            vector<vector<double>> datos(numX, 
                vector<double>(numT, 0));



            /////////////////////////////////////////////////////////////////////
            /////////////////////// ECUACION DE TENSION /////////////////////////
            /////////////////////////////////////////////////////////////////////

            // se resuelve la ecuación de Euler-Bernoulli
            for(int t = 0; t<numT; t++){
                // dado que en x hay una doble derivada se deben dejar 2 espacios a la derecha y la izquierda
                for(int x = 2; x<numX-2; x++){
                    // condiciones de borde
                    datos[x][0] = 0.;

                    // resolución de ecuación de bernoulli, es tal como se muestra en el pdf subido
                    // se usó la aproximación para una cuarta derivada
                    datos[x][t+1] = 2*datos[x][t] - datos[x][t-1]
                                    + dt*dt*alpha*(datos[x+2][t]-4.*datos[x+1][t]+6.*datos[x][t]-4.*datos[x-1][t]+ datos[x-2][t])/(dx*dx*dx*dx)
                                                + dt*dt*Forzante(x, t); 
                    }


                    
                }

            // guardo los resultados en el tensor
            this->datos = datos;

        }



        ///////////////////////////////// GUARDAR DATOS 1D //////////////////////////////

        // Función para guardar los datos en un archivo .txt
        void guardarResultados1d() {
            std::ofstream archivo("resultados.txt");
            for (int t = 0; t < numT; t++) {
                for (int x = 0; x < numX; x++) {
                    archivo << x * dx << " " << t * dt << " " << this->datos[x][t] << "\n";
                }
            }
            archivo.close();
        }

};

#endif