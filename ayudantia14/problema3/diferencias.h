#ifndef DIFERENCIAS_H
#define DIFERENCIAS_H

#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

class Diferencias {
    private:
        // Parámetros del problema
        double alpha; // el valor de la constante c² o k de las ecuaciones diferenciales del pdf que subí
        double dx; 
        double dy; 
        double dh; // dx=dy=dh 
        int numX; // numero de elementos en x
        int numY; // numero de elementos en y
        int numN; // numero de elementos en t
        vector<vector<double>> datos; // matriz que guardará todos los datos que salen de la diferencia finita
        
    public:
        Diferencias(){ 
            // Parámetros del problema
            this->dx = 0.01;
            this->dy = 0.01;
            this->dh = 0.01;
            this->numX = 100;
            this->numY = 100;
            this->numN = 10000;
        };

        void sor(double omega, double (*Forzante)(double, double)) {

            vector<vector<double>> datos(numX, 
                vector<double>(numY, 0));

            for(int i = 0; i < numX; i++){
                datos[i][0] = 0.;
                datos[i][numY-1] = 0;
            }

            for(int i = 0; i < numY; i++){
                datos[0][i] = 0.;
                datos[numX-1][i] = 10;
            }

            for(int n = 0; n<numN; n++){
                for(int x = 1; x<numX-1; x++){
                    for(int y = 1; y<numY-1; y++){
                        datos[x][y] = (1. -omega)*datos[x][y]
                                        + (omega/4.)*(datos[x+1][y] + datos[x-1][y]
                                                    + datos[x][y+1] + datos[x][y-1]
                                                    + dh*dh*Forzante(x, y)); 
                    }
                }
            }
            this->datos = datos;
        }

        void guardarResultados() {
            std::ofstream archivo("resultados.txt");
            for (int x = 0; x < numX; x++) {
                for (int y = 0; y < numY; y++) {
                    archivo << x * dx << " " << y * dy << " " << this->datos[x][y] << "\n";
                }
            }
            archivo.close();
        }

};

#endif