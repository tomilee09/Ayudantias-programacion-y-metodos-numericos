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
            this->alpha = 9;
            this->dx = 0.1;
            this->dt = dx*dx*dx*dx; // tal vez necesiten que sea más chico para que no de cosas raras, o más grande para avanzar más en el tiempo
                                 // hay que buscar el equilibrio
            this->numX = 100;
            this->numT = 40000;
        };

        // Función para resolver diferencias finitas en 1 dimension espacial y una temporal
        void diferencias_finitas_1D(double (*Forzante)(double, double)) {

            // creo un vector de vectores de vectores
            // inicializo todos los elementos a 0, asi que si no impongo otras condiciones, la condicion inicial es que todo sea 0
            vector<vector<double>> datos(numX, 
                vector<double>(numT, 0));

            // pongo todos los valores iniciales en un solo segmento explicito para t=0
            for(int i = 0; i < numX; i++){
                if(i == 0){
                    datos[i][0] = 0;
                }
                else if(i == numX-1){
                    datos[i][0] = 0;
                }
                else{
                    datos[i][0] = sin(i*0.1);
                }
            }

            // pongo todos los valores iniciales en un solo segmento explicito para t=1
            for(int i = 0; i < numX; i++){
                if(i == 0){
                    datos[i][1] = 0;
                }
                else if(i == numX-1){
                    datos[i][1] = 0;
                }
                else{
                    datos[i][1] = sin(i*0.1);
                }
            }

            // pongo todos los valores iniciales en un solo segmento explicito para x=0 y x=10
            for(int i = 0; i < numT; i++){
                datos[0][i] = 0;
                datos[numX-1][i] = 0;
            }

            // se calcula la diferencia finita
            for(int t = 1; t<numT-1; t++){
                for(int x = 1; x<numX-1; x++){
                    datos[x][t+1] = 2*datos[x][t]-datos[x][t-1]
                                    +dt*dt*alpha*(datos[x+1][t]-2*datos[x][t]+datos[x-1][t])/(dx*dx)
                                    +dt*dt*Forzante(x, t);
                    }
                }

            // guardo los resultados en la matriz
            this->datos = datos;

        }



        ///////////////////////////////// GUARDAR DATOS //////////////////////////////

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