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
double derivada(double t) {
    return sin(t); // puede ser cualquier función
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

    double t_f = 10.;

    double t = 0; // es la variable para este problema (x(t))


    /////////////////////////////// EULER /////////////////////////////////
    // guardo los datos en euler.dat 
    ofstream euler;
    euler.open("euler.dat");

    while(t<t_f) {
        euler << t << " " << a << " " << v << " " << x << endl;

        // Aplico método de Euler para resolver ode
        // la ode que debemos resolver es: a = d²x/dt² = derivada(t)
        // por ejemplo, si a = -1, la solución debería ser x = -x²/2,
        // lo cual debería reflejarse en el gráfico obtenido
        a = derivada(t);
        v = v_n + a_n*dt;
        x = x_n + v_n*dt;
        t = t + dt;

        x_n = x;
        v_n = v;
        a_n = a;
    }
    euler.close();

    // reinicio las variables para el siguiente método
    // hago esto solo porque estoy probando varios métodos, no es parte de algún método
    t = 0;
    x = 0;
    v = 0;
    a = 0;
    x_n = 0;
    v_n = 0;
    a_n = 0;

    /////////////////////////////// EULER-CROMER /////////////////////////////////
    ofstream euler_cromer;
    euler_cromer.open("euler_cromer.dat");

    while(t<t_f) {
        euler_cromer << t << " " << a << " " << v << " " << x << endl;

        // Aplico método de Euler-Cromer
        // solo cambia el v_n por v respecto al método de euler
        a = derivada(t);
        v = v_n + a_n*dt;
        x = x_n + v*dt;
        t = t + dt;

        x_n = x;
        v_n = v;
        a_n = a;
    }
    euler_cromer.close();


    // reinicio los valores para el siguiente método
    t = 0;
    x = 0;
    v = 0;
    a = 0;
    x_n = 0;
    v_n = 0;
    a_n = 0;


    /////////////////////////////// Verlet /////////////////////////////////
    ofstream verlet;
    verlet.open("verlet.dat");

    while(t<t_f) {
        verlet << t << " " << a << " " << v << " " << x << endl;

        // Aplico método de verlet
        a = derivada(t);
        v = v_n + 0.5*(a+a_n)*dt;
        x = x_n + v_n*dt + a_n*dt*dt/2;
        t = t + dt;

        x_n = x;
        v_n = v;
        a_n = a;
    }
    verlet.close();


    // reinicio los valores para el siguiente método
    t = 0;
    x = 0;
    v = 0;
    a = 0;
    x_n = 0;
    v_n = 0;
    a_n = 0;


    /////////////////////////////// RK2 /////////////////////////////////
    ofstream rk2;
    rk2.open("rk2.dat");

    while(t<t_f) {
        rk2 << t << " " << a << " " << v << " " << x << endl;

        // Aplico método RK2
        double k1 = derivada(t);
        double k2 = derivada(t+dt);
        a = (k1+k2)/2.;
        v = v_n + a*dt;
        x = x_n + v*dt;
        t = t + dt;

        x_n = x;
        v_n = v;
        a_n = a;
    }

    rk2.close();


    return 0;
}