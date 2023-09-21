#ifndef MATRIZ_H
#define MATRIZ_H
// ifndef significa if not define, es para cuando tengan que usar su clase en archivos que se llaman entre ellos, y no definan varias veces su clase
// por lo que, si no está previamente definida, definela
// siempre se pone el nombre del archivo en mayúsculas, un guión bajo representando el punto, y la extensión que tenga, para este caso una h

#include <iostream>
#include <vector>

using namespace std;

// cre la clase Matriz, por convención siempre empiezan con mayúscula
class Matriz {
    // en privado almaceno las variables básicas de mi clase, las que la definen
    private:
        int n = 2;
        // defino un vector de vectores inicializado solo con 0's
        vector<vector<double>> m{{0, 0},{0, 0}};
    // en público defino todo lo demás
    public:
        // defino el contructor por defecto
        Matriz() {};
        // defino el constructor que me crea una fracción a partir de 4 números
        Matriz(double a, double b, double c, double d) {
            m[0][0] = a;
            m[0][1] = b;
            m[1][0] = c;
            m[1][1] = d;
        }

        // sobrecarga de [], para elegir un elemento de la matriz fácilmente
        // notese que solo lo sobrecargo 1 vez, así que no podría hacer mi_matriz[][],
        // pero dado que me entrega un objeto de la clase vector, estos también tienen
        // la sobrecarga de [], por lo que sí puedo hacer mi_matriz[][]
        vector<double> operator[] (int i) {
            return m[i];
        }

        // sobrecarga del operador suma
        Matriz operator+ (Matriz otra_matriz) {
            Matriz resultado;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    resultado.m[i][j] = m[i][j] + otra_matriz.m[i][j];
                } 
            }
            return resultado;
        }
        
        // sobrecarga del operador resta
        Matriz operator- (Matriz otra_matriz) {
            Matriz resultado;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    resultado.m[i][j] = m[i][j] - otra_matriz.m[i][j];
                } 
            }
            return resultado;
        }

        // sobrecarga del operador multiplicacion para multiplicación de matrices
        Matriz operator* (Matriz otra_matriz) {
            Matriz resultado;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    for(int k = 0; k < n; k++){
                        resultado.m[i][j] = resultado.m[i][j] + m[i][k]*otra_matriz.m[k][j];
                    }
                } 
            }
            return resultado;
        }

        // sobrecarga del operador multiplicacion para multiplicación por un escalar
        Matriz operator* (double x) {
            Matriz resultado;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    resultado.m[i][j] = m[i][j] * x;
                } 
            }
            return resultado;
        }

        // sobrecarga del operador ()
        // aqui sí estoy entregando directamente un número
        double operator() (int i, int j) {
            return m[i][j];
        }

        // con esta función muestro en pantalla la matriz
        void print() {
            cout << "[" << m[0][0] << ", " << m[0][1] << endl;
            cout << m[1][0] << ", " << m[1][1] << "]" << endl << endl;
        }



};

// esto hay que ponerlo para cerrar el #ifndef del inicio
#endif