#include<iostream>
#include<cmath>
#include"diferencias2.h"

using namespace std;

// forzante que voy a usar (la F del pdf)
double forzante(double x, double t)
{
    return 10*sin(x/40);
    // return 0;
}

// se desea resolver la ecuación de Euler-Bernoulli
// se usa diferencias finitas

int main() {
    // se resuelve usando la función diferencias_finitas_1D
    Diferencias2 mi_solucion;
    mi_solucion.diferencias_finitas_1D(forzante);

    // se guardan los resultados
    mi_solucion.guardarResultados1d();
    return 0;
}