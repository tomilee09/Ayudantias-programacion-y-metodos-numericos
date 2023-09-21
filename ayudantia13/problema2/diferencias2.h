#ifndef DIFERENCIAS_H
#define DIFERENCIAS_H

#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

// Clase para aplicar diferencias finitas
// esta es la continuacion de la clase de la ayudantia 12
// por lo anterior tiene los mismos parámetros
class Diferencias2 {
    private:
        // Parámetros del problema
        double alpha; // el valor de la constante c² o k de las ecuaciones diferenciales del pdf que subí
        double dx; 
        double dy; 
        double dz; 
        double dh; // dx=dy=dh 
        int numX; // numero de elementos en x
        int numY; // numero de elementos en y
        int numZ; // numero de elementos en y
        int numN; // numero de elementos en t
        vector<vector<vector<double>>> datos; // tensor que guardará todos los datos que salen de la diferencia finita
        
    public:
        // Diferencias(){};
        Diferencias2(){ // no le pongo datos de entrada, los defino todos directamente aquí solo por mi comodidad
            // Parámetros del problema
            this->alpha = 1;
            this->dx = 0.01;
            this->dy = 0.01;
            this->dz = 0.01;
            this->dh = 0.01;
            this->numX = 20;
            this->numY = 20;
            this->numZ = 20;
            this->numN = 1000;
        };

        // Función para resolver una ecuacion de poisson con 3 coordenadas espaciales
        // forzante solo depende de las 3 coordenadas
        void sor3D(double omega, double (*Forzante)(double, double, double)) {

            // creo un vector de vectores de vectores
            // inicializo todos los elementos a 0, asi que si no impongo otras condiciones, la condicion inicial es que todo sea 0
            vector<vector<vector<double>>> datos(numX, 
                vector<vector<double>>(numY, 
                    vector<double>(numZ, 0)));



            /////////////////////////////////////////////////////////////////////
            //////////////////////////////// SOR ////////////////////////////////
            /////////////////////////////////////////////////////////////////////
            
            // realizo iteraciones para las 3 coordenadas
            for(int n = 0; n<numN; n++){
                for(int x = 1; x<numX-1; x++){
                    for(int y = 1; y<numY-1; y++){
                        // condiciones de borde
                        datos[x][y][0] = 100.;

                        // aplico el método de SOR, dado que tenemos 3 coordenadas, hay que dividir por 6
                        // por lo demás es la misma fórmula del pdf del profesor Toledo
                        for(int z = 1; z<numZ-1; z++){
                            datos[x][y][z] = (1. -omega)*datos[x][y][z]
                                            + (omega/6.)*(datos[x+1][y][z]+ datos[x-1][y][z]
                                                        + datos[x][y+1][z]+ datos[x][y-1][z]
                                                        + datos[x][y][z+1]+ datos[x][y][z-1]
                                                        + dh*dh*Forzante(x, y, z)); 
                            // dado que se avanza desde el var = 0 -> N-1, cuando queremos calcular el paso n de datos[x][y][z],
                            // los valores de datos[x-1][y][z], datos[x][y-1][z], datos[x][y][z-1] serán los valores para el 
                            // paso n+1, pues ya los habremos calculado antes, esto no pasaba en la ayudantía pasada, dado que 
                            // ahí fijé la iteracion para un n en todos los datos (tenía datos[x][y][t], donde t era mi n, en 
                            // este caso sería equivalente a hacer datos[x][y][z][n], pero necesitaría 4 dimensiones, o al menos
                            // guardar de forma inteligente las variables en el ciclo for)
                        }

                    }

                    
                }
            }
            

            // guardo los resultados en el tensor
            this->datos = datos;

        }



        ///////////////////////////////// GUARDAR DATOS 3D //////////////////////////////
        // Función para guardar los datos en un archivo .txt
        void guardarResultados3d() {
            std::ofstream archivo("resultados.txt");
            for (int x = 0; x < numX; x++) {
                for (int y = 0; y < numY; y++) {
                    for (int z = 0; z < numZ; z++) {
                        archivo << x * dx << " " << y * dy << " " << z * dz << " " << this->datos[x][y][z] << "\n";
                    }
                }
            }
            archivo.close();
        }

};

#endif