#include<iostream>
#include<cmath>
#include"diferencias2.h"

// forzante que voy a usar (la F del pdf)
double forzante(double x, double y, double z)
{
    return 0;
}

/** 
 * se desea resolver una ecuación de poisson en 3D
 * hacerlo con el método SOR, es muy parecido a las diferencias finitas
*/
int main() {
    // creo un objeto de la clase
    Diferencias2 mi_solucion;

    // encuentro la solucion de una ecuacion de poisson en 3d con SOR
    double omega = 1.9; // si omega > 1 obtenemos SOR
    mi_solucion.sor3D(omega, forzante);
    
    // guardo en un .txt los datos
    mi_solucion.guardarResultados3d();
    return 0;
}