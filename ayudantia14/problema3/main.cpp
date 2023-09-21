#include<iostream>
#include<cmath>
#include"diferencias.h"

double forzante(double x, double y)
{
    return 2*(x-y)*exp(cos(y-x));
}

int main() {
    Diferencias mi_solucion;

    double omega = 1.93; // si omega > 1 obtenemos SOR
    mi_solucion.sor(omega, forzante);
    
    mi_solucion.guardarResultados();
    return 0;
}