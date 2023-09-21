#include<iostream>
#include<vector>
#include"punto.h"
#include"linea.h"
#include"geometria.h"

using namespace std;

int main() {
    // prueba de Punto
    Punto<double> mi_punto(1., 1.);
    Punto<double> otro_punto(2., 2.);
    Punto<double> suma = mi_punto + otro_punto;

    // prueba de Linea
    Linea<double> mi_linea(mi_punto, otro_punto);
    mi_linea += Punto(1., 2.)/10;

    // prueba de geometría
    Punto<double> punto3(1., 2.);
    Punto<double> punto4(2., 1.);
    vector<Punto<double>> figura_vector(4, mi_punto);
    figura_vector[0] = mi_punto;
    figura_vector[1] = punto3;
    figura_vector[2] = otro_punto;
    figura_vector[3] = punto4;
    Geometria figura(figura_vector);

    return 0;
}