#ifndef DECIMAL_H
#define DECIMAL_H

#include<iostream>
#include<vector>
#include<cmath>
#include"fraccion.h"

using namespace std;

// Se define la clase Decimal
class Decimal {
    private:
        // aqui guardo todos los números del número
        vector<int> numeros;
        // aqui guardo la posición de la coma
        int posicion_coma;
    public:
        Decimal(){};
        Decimal(vector<int> numeros, int posicion_coma) {
            this->numeros = numeros;
            this->posicion_coma = posicion_coma;
        }

        // sobrecarga del operador + entre decimales
        Decimal operator+(Decimal otro_decimal) {
            vector<int> resultado = numeros;
            
            // realizo la suma de las 2 listas
            for(int i = 0; i<numeros.size(); i++){
                resultado[i] = numeros[i] + otro_decimal.numeros[i];
            }

            // puede que esta lista tenga números mayores a 10, voy a agregar un 1 en el siguiente elemento de la lista
            // notese que se suma de derecha a izquierda, asi que parto del ultimo elemento hasta el primero
            for(int i = numeros.size()-1; i >= 0; i--) {
                // si es el primer elemento de la lista hay que agregar un 1 como nuevo primer elemento
                if(i == 0) {
                    if(resultado[i]>10) {
                        resultado[i] = resultado[i]-10;
                        resultado.insert(resultado.begin(), 1);
                        posicion_coma += 1;
                    }
                }
                // en los demás casos solo hay que sumar un 1 al siguiente elemento
                else{
                    if(resultado[i]>=10) {
                        resultado[i] = resultado[i]-10;
                        resultado[i-1] = resultado[i-1]+1;
                    }
                }
            }
            return Decimal(resultado, posicion_coma);
        }

        // hago la suma entre decimal y fraccion, la idea detrás de la función es que transforma la fracción en un double,
        // luego el double se transforma en un texto, luego el texto en una lista, y finalmente la lista en un Decimal
        // los 2 decimal se suman usando la sobrecarga del operador + previamente definido
        Decimal operator+(Fraccion mi_fraccion) {
            double fraccion_double = double(mi_fraccion[0])/double(mi_fraccion[1]);
            string fraccion_texto = to_string(fraccion_double);
            vector<int> fraccion_vector;
            int posicion_fraccion;
            for(int i = 0; i<fraccion_texto.size(); i++) {
                if((fraccion_texto[i] == ',') || (fraccion_texto[i] == '.')){
                    posicion_fraccion = i;
                }
                else{
                    fraccion_vector.push_back(int(fraccion_texto[i])-48);
                }
            }
            Decimal fraccion_decimalizada(fraccion_vector, posicion_fraccion);
            Decimal mi_decimal(numeros, posicion_coma);
            Decimal resultado_decimal = mi_decimal + fraccion_decimalizada;
            return resultado_decimal;
        }

        // muestro en pantalla un número decimal
        void print() {
            for(int i = 0; i<numeros.size(); i++){
                cout << numeros[i]; 
                if(i == posicion_coma-1) {
                    cout << ",";
                }
            }
            cout << endl;
        }
        
};

#endif