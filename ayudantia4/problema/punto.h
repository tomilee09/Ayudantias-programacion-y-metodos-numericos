#ifndef PUNTO_H
#define PUNTO_H

#include<iostream>
#include<vector>

using namespace std;

template <class T>
class Punto {
    private:
        T x;
        T y;
        vector<T> punto;
    public:
        Punto(){};
        // une los puntos más cercanos en una figura cualquiera
        Punto(T x, T y){
            this->x = x;
            this->y = y;
            vector<T> punto{x, y};
        };

        Punto<T> operator+(Punto otro_punto) {
            return Punto(x + otro_punto.x, y + otro_punto.y);
        }

        Punto<T> operator-(Punto otro_punto) {
            return Punto(x - otro_punto.x, y - otro_punto.y);
        }

        Punto<T> operator*(T escalar) {
            return Punto(x * escalar, y * escalar);
        }

        Punto<T> operator/(T escalar) {
            return Punto(x/escalar, y/escalar);
        }
};

#endif