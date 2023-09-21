#ifndef FRACCION_H
#define FRACCION_H

// clase fraccion creada en una ayudantía previa

#include<iostream>

using namespace std;

class Fraccion {
private:
    int numerador, denominador;

public:
    Fraccion(int num, int den) {
        numerador = num;
        denominador = den;
    }

    void simplificar() {
        int mcd = this->MCD(numerador, denominador);
        numerador /= mcd;
        denominador /= mcd;
    }

    int MCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return MCD(b, a % b);
    }

    Fraccion operator+(Fraccion f) {
        int num = (numerador * f.denominador) + (f.numerador * denominador);
        int den = denominador * f.denominador;
        Fraccion res(num, den);
        res.simplificar();
        return res;
    }

    // esto es lo único nuevo que le puse a la clase, la sobrecarga de []
    int operator[] (int i) {
        if(i==0) {
            return numerador;
        }
        if(i==1) {
            return denominador;
        }
        else {
            cout << "fuera de rango" << endl;
            return 0;
        }
    }

    void imprimir() {
        cout << numerador << "/" << denominador << endl;
    }
};

#endif