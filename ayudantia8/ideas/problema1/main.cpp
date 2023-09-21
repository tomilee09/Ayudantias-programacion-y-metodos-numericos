#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

using namespace std;

/** 
 * Aqui usé el main como zona de pruebas al momento de mostrar 
 * como funcionan los métodos, recomiendo su uso más ordenado con
 * clases o templates
*/

// derivada que se usará en todos los siguientes métodos
double derivada(double t, double x, double v) {
    double F = 1.5; // Fuerza inicial
    double w = 2.; // omega
    double m = 1.; // masa
    double k = 1.; // constante elástica
    double b = 0.75; // beta
    return  F * sin(w*t)/m - v*b/m -x*k;
    // return - x*k - v*b + sin(t); // movimiento armonico amortiguado con forzante
}

int main() {

    // las siguientes son todas las variables necesarias para 
    // los métodos que se usarán, notese que v = dx/dt y a = d²x/dt²
    double x = 0;
    double v = 0;
    double a = 0;

    // defino los valores de x, v, a para el step anterior, 
    // es decir, en este caso, x es el paso (n+1) y x_n es el paso n 
    double x_n = 0;
    double v_n = 0;
    double a_n = 0;

    double dt = 0.1;

    double t_f = 100.;

    double t = 0; // es la variable para este problema (x(t))


    /////////////////////////////// EULER /////////////////////////////////
    // guardo los datos en pefrl.dat 
    ofstream pefrl;
    pefrl.open("pefrl.dat");

    double e = 0.178617; // xi minúscula
    double l = -0.212341; // lambda
    double ji = -0.0662645; // ji minúscula 

    double m=1;

    while(t<t_f) {
        pefrl << t << " " << a << " " << v << " " << x << endl;

        // Aplico método de Euler para resolver ode
        // la ode que debemos resolver es: a = d²x/dt² = derivada(t)
        // por ejemplo, si a = -1, la solución debería ser x = -x²/2,
        // lo cual debería reflejarse en el gráfico obtenido
        // a = derivada(t, x, v);
        // calculo y1, y1diff, y2, y2diff, y3, y3diff, y4 tal como dice el método pefrl
        double y1 = x + e*derivada(t, x, v)*dt;
        double y1diff = v + ((1. -2.*l)/(2.*m))*dt*derivada(t, x, y1);
        
        double y2 = y1 + ji*y1diff*dt;
        double y2diff = y1diff + (l/m)*dt*derivada(t, x, y2);

        double y3 = y2 + (1. -2.*(ji+e))*y2diff*dt;
        double y3diff = y2diff + (l/m)*dt*derivada(t, x, y3);

        double y4 = y3 + ji*y3diff*dt;
        
        // calculo la aceleración, velocidad y la posición a partir de estas constantes
        // a = derivada(t, x, v);
        a = y3diff + ((1. -2.*l)/(2.*m))*dt*derivada(t, x, y4);
        v = y4 + e*a*dt;
        x = x + v*dt;
        t = t + dt;
    }
    pefrl.close();

    // // reinicio las variables para el siguiente método
    // // hago esto solo porque estoy probando varios métodos, no es parte de algún método
    // t = 0;
    // x = 0;
    // v = 0;
    // a = 0;
    // x_n = 0;
    // v_n = 0;
    // a_n = 0;

    return 0;
}