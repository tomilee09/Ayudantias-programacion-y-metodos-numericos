#ifndef DIFERENCIAS_H
#define DIFERENCIAS_H

#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

// Clase para aplicar diferencias finitas
class Diferencias {
    private:
        // Parámetros del problema
        double alpha; // el valor de la constante c² o k de las ecuaciones diferenciales del pdf que subí
        double dx; // tamaño paso en x
        double dy; // tamaño paso en y
        double dh; // es igual a dx y dy, solo lo uso para la ecuación de poisson, le cambié el nombre porque dx=dy=dh 
        double dt; // parametro que deben cambiar si les da algo raro, usar un dt chico
        int numX; // numero de elementos en x
        int numY; // numero de elementos en y
        int numT; // numero de elementos en t
        vector<vector<vector<double>>> datos; // tensor que guardará todos los datos que salen de la diferencia finita
        
    public:
        // Diferencias(){};
        Diferencias(){ // no le pongo datos de entrada, los defino todos directamente aquí solo por mi comodidad
            // Parámetros del problema
            this->alpha = 1;
            this->dx = 0.1;
            this->dy = 0.1;
            this->dh = 0.1;
            this->dt = dx*dx/4.; // tal vez necesiten que sea más chico para que no de cosas raras, o más grande para avanzar más en el tiempo
                                 // hay que buscar el equilibrio
            this->numX = 100;
            this->numY = 100;
            this->numT = 1000;
        };

        // Función para resolver diferencias finitas en 2 dimensiones espaciales y una temporal
        void diferencias_finitas_2D(string tipo_ecuacion, double (*Forzante)(double, double, double)) {

            // creo un vector de vectores de vectores, o sea, un tensor, de tamaño numX*numY*numT
            // inicializo todos los elementos a 0, asi que si no impongo otras condiciones, la condicion inicial es que todo sea 0
            vector<vector<vector<double>>> datos(numX, 
                vector<vector<double>>(numY, 
                    vector<double>(numT, 0)));
            


            /////////////////////////////////////////////////////////////////////
            ////////////////////// ECUACION DE DIFUSION /////////////////////////
            /////////////////////////////////////////////////////////////////////

            if(tipo_ecuacion == "1" || tipo_ecuacion == "difusion") {
                
                // condiciones iniciales
                for(int x = 0; x<numX; x++){
                    for(int y = 0; y<numY; y++){
                        datos[x][0][0] = 100.;
                    }
                }

                // Resolución de la ecuación de difusión utilizando diferencias finitas
                for(int t = 0; t<numT-1; t++){
                    for(int x = 1; x<numX-1; x++){
                        datos[x][0][t] = 100.;
                        for(int y = 1; y<numY-1; y++){
                            // la siguiente es la ecuación despejada en el pdf que subí para la ecuación de difusión
                            datos[x][y][t+1] = datos[x][y][t]
                                                +dt*alpha*(datos[x+1][y][t]-2*datos[x][y][t]+datos[x-1][y][t])/(dx*dx)
                                                +dt*alpha*(datos[x][y+1][t]-2*datos[x][y][t]+datos[x][y-1][t])/(dy*dy)
                                                +dt*Forzante(x, y, t);
                        }
                    }
                }
            }



            /////////////////////////////////////////////////////////////////////
            //////////////////////// ECUACION DE ONDA ///////////////////////////
            /////////////////////////////////////////////////////////////////////

            if(tipo_ecuacion == "2" || tipo_ecuacion == "onda") {
                
                // condiciones iniciales
                for(int x = 0; x<numX; x++){
                    for(int y = 0; y<numY; y++){
                        datos[50][50][0] = 100.;
                        datos[50][51][1] = 90.; // ahora puse t=1 a diferencia de en la ayudantía, da casi lo mismo
                    }
                }

                // Resolución de la ecuación de onda utilizando diferencias finitas
                for(int t = 1; t<numT-1; t++){ // en la ayudantia puse t=0 y funcionó, no sé por qué, ahora lo cambié a t=1
                    for(int x = 1; x<numX-1; x++){
                        for(int y = 1; y<numY-1; y++){
                            // la siguiente es la ecuación despejada en el pdf que subí para la ecuación de onda
                            datos[x][y][t+1] = 2*datos[x][y][t] - datos[x][y][t-1]
                                                +dt*dt*alpha*(datos[x+1][y][t]-2*datos[x][y][t]+datos[x-1][y][t])/(dx*dx)
                                                +dt*dt*alpha*(datos[x][y+1][t]-2*datos[x][y][t]+datos[x][y-1][t])/(dy*dy)
                                                +dt*dt*Forzante(x, y, t);
                        }
                    }
                }
            }



            /////////////////////////////////////////////////////////////////////
            //////////////////////// POISSON O LAPLACE //////////////////////////
            /////////////////////////////////////////////////////////////////////

            if(tipo_ecuacion == "3" || tipo_ecuacion == "poisson") {
                
                // condiciones iniciales
                for(int x = 0; x<numX; x++){
                    for(int y = 0; y<numY; y++){
                        datos[x][0][0] = 100.;
                        datos[x][numY-1][0] = -100.;
                    }
                }

                // Resolución de la ecuación de Poisson utilizando diferencias finitas
                // ahora no hay tiempo, solo son pasos sucesivos para mejorar la aproximacion (se está "relajando")
                for(int t = 0; t<numT-1; t++){
                    for(int x = 1; x<numX-1; x++){

                        // condiciones de borde que se mantienen en el tiempo, puse estas para que se viera más bonito
                        if(x<50){
                            datos[x][0][t] = -100.0; 
                            datos[x][numY - 1][t] = 100.0; 
                        }
                        else{
                            datos[x][numY - 1][t] = -100.0; 
                            datos[x][0][t] = 100.0; 
                        }

                        for(int y = 1; y<numY-1; y++){
                            // la siguiente es la ecuación despejada en el pdf que subí para la ecuación de poisson
                            datos[x][y][t+1] = (1./4.)*(datos[x+1][y][t] + datos[x-1][y][t]
                                                    +datos[x][y+1][t] + datos[x][y-1][t]
                                                    +dh*dh*Forzante(x, y, t));
                            

                        }
                    }
                }
            }

            // guardo los resultados en el tensor
            this->datos = datos;

        }



        ///////////////////////////////// GUARDAR DATOS 2D //////////////////////////////

        // Función para guardar los datos en un archivo .txt
        void guardarResultados() {
            std::ofstream archivo("resultados.txt");
            for (int t = 0; t < numT; t++) {
                for (int x = 0; x < numX; x++) {
                    for (int y = 0; y < numY; y++) {
                        archivo << x * dx << " " << y * dy << " " << t * dt << " " << this->datos[x][y][t] << "\n";
                    }
                }
            }
            archivo.close();
        }

};

#endif