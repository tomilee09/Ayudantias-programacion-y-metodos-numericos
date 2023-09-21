#include<iostream>
#include<cmath>
#include"diferencias.h"

using namespace std;

// forzante que voy a usar (la F del pdf)
double forzante(double x, double t)
{
    return exp(-x*x);
    // return 0;
}

int main() {
    // se resuelve usando la función diferencias_finitas_1D
    Diferencias2 mi_solucion;
    mi_solucion.diferencias_finitas_1D(forzante);

    // se guardan los resultados
    mi_solucion.guardarResultados1d();
    return 0;
}