#ifndef DUAL_H
#define DUAL_H

// incluyo las librerías que voy a usar
#include<iostream>
#include<cmath> 

using namespace std;

// creo el template de duales llamado Dual
template <class T>
class Dual {
    // defino las variables que no pueden ser usadas en el main
    private:
        T real;
        T dual;
    // defino todo lo que se puede usar en cualquier parte
    public:
        // contructor por defecto
        Dual(){};
        // constructor que crea un dual a partir de 2 números
        Dual(T real, T dual){
            this->real = real;
            this->dual = dual;
        }

        // sobrecarga del operador << usando librería iostream
        friend ostream& operator<<(ostream& texto, Dual mi_dual) {
            texto << "(" <<  mi_dual.real << ", " << mi_dual.dual << ")" << endl;
            return texto;
        } 

        // sobrecarga del operador - en una operación unitaria (no interacciona con otro objeto)
        Dual<T> operator-() {
            return Dual(-real, -dual);
        }

        // sobrecarga del operador + con otro dual
        Dual<T> operator+(Dual<T> otro_dual){
            return Dual(real + otro_dual.real, dual + otro_dual.dual);
        }

        // sobrecarga del operador - con otro dual
        Dual<T> operator-(Dual<T> otro_dual){
            return Dual(real - otro_dual.real, dual - otro_dual.dual);
        }

        // sobrecarga del operador + con un escalar
        Dual<T> operator*(T escalar) {
            return Dual(real * escalar, dual* escalar);
        }

        // sobrecarga del operador * con otro dual
        Dual<T> operator*(Dual<T> otro_dual) {
            return Dual(real * otro_dual.real, dual * otro_dual.real + otro_dual.dual * real);
        }

        // sobrecarga del operador [] para seleccionar el numero real o el numero dual dentro de un objeto de la clase Dual
        T operator[] (int i) {
            if(i==0) {
                return real;
            }
            if(i==1) {
                return dual;
            }
            else {
                cout << "te pasaste" << endl;
                return 0;
            }
        }
};

// sobrecarga de sin para que reciba como parámetro un número dual
template <typename T> Dual<T> sin(Dual<T> mi_dual){
    Dual<T> resultado = Dual(sin(mi_dual[0]), cos(mi_dual[0])*mi_dual[1]);
    return resultado;
}

// sobrecarga de cos para que reciba como parámetro un número dual
template <typename T> Dual<T> cos(Dual<T> mi_dual){
    Dual<T> resultado = Dual(cos(mi_dual[0]), -sin(mi_dual[0])*mi_dual[1]);
    return resultado;
}


#endif