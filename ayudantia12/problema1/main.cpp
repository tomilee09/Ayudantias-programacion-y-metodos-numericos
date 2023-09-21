#include<iostream>
#include<cmath>
#include"diferencias.h"

// forzante que voy a usar (la F del pdf)
double forzante(double x, double y, double t)
{
    // return 100*sin(x); // ese es el forzante que usé en la foto 3_ecuacion_poisson_con_forzante
    return 0;
}

int main() {
    // creo un objeto de la clase
    Diferencias mi_solucion;

    // realizo la diferencia finita
    // 1 = ecuacion de difusion
    // 2 = ecuacion de onda
    // 3 = ecuacion de poisson
    mi_solucion.diferencias_finitas_2D("3", forzante);
    
    // guardo en un .txt los datos, guardo x, y, t, amplitud
    // con amplitud me refiero a lo que arroja el método, puede ser la temperatura, la amplitud de la onda o el valor del campo
    mi_solucion.guardarResultados();
    return 0;
}