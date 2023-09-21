#include <iostream>
#include <vector>
#include <cmath>
#include "integradores.h"
#include "matriz.h"

using namespace std;

/** Queremos resolver la integral de la exponencial */

double exponencial(double x) {
    return exp(x);
}

int main() {
    // creo un objeto de la clase integradores con limites 1 y 2
    Integradores mi_integrador(1, 2);

    // integracion con trapecio
    double integracion_trapecio = mi_integrador.trapecio(exponencial, 100);
    cout << integracion_trapecio << endl;

    // integracion con romberg
    double integracion_romberg = mi_integrador.romberg(exponencial, 20);
    cout << integracion_romberg << endl;

    // integracion con legendre
    double integracion_legendre = mi_integrador.gauss_legendre(exponencial, 20);
    cout << integracion_legendre << endl;

    return 0;
}