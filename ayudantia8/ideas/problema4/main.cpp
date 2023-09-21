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
double derivada(double t, double theta, double theta_punto) {
    return -0.01*theta_punto*0. - sin(theta) + 0.1*sin(t)*cos(theta)*0.; // puede ser cualquier función
}


double rk4(double x, double theta, double y, double h, double (*f)(double, double ,double)) {
        double k1 = h * f(x, theta, y);
        double k2 = h * f(x + h / 2, theta, y + k1 / 2);
        double k3 = h * f(x + h / 2, theta, y + k2 / 2);
        double k4 = h * f(x + h, theta, y + k3);
        
        double y_next = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        return y_next;
    }

vector<double> adaptive_rk4(double x, double theta, double y, double h, double tolerance, double (*f)(double, double, double)) {
        double y1 = rk4(x, theta, y, h, f);
        double y2 = rk4(x, theta, y, h / 2, f);
        double error = std::abs(y1 - y2);
        

        if (error <= tolerance) {
            return vector{h, y1};
        } else {
            double h_new = h / 2;
            return adaptive_rk4(x, theta, y, h_new, tolerance, f);
        }
    }

int main() {

    // las siguientes son todas las variables necesarias para 
    // los métodos que se usarán, notese que v = dx/dt y a = d²x/dt²
    double x = 1;
    double v = 0;
    double a = 0;

    // defino los valores de x, v, a para el step anterior, 
    // es decir, en este caso, x es el paso (n+1) y x_n es el paso n 
    double x_n = 1;
    double v_n = 0;
    double a_n = 0;

    double dt = 0.1;

    double t_f = 100.;

    double t = 0; // es la variable para este problema (x(t))

    /////////////////////////////// RK4 /////////////////////////////////

    ofstream rk4_text;
    rk4_text.open("rk4.dat");
    while(t<t_f) {
        rk4_text << t << " " << a << " " << v << " " << x << endl;

        // aplico rk4 adaptativo
        v = rk4(t, x, v_n, dt, derivada);
        x = x_n + v*dt;
        t = t + dt;

        x_n = x;
        v_n = v;
        a_n = a;
    }

    rk4_text.close();


    // reinicio los valores para el siguiente método
    t = 0;
    x = 1;
    v = 0;
    a = 0;
    x_n = 1;
    v_n = 0;
    a_n = 0;



    /////////////////////////////// ADAPTATIVE RK4 /////////////////////////////////

    ofstream rk4_error;
    rk4_error.open("rk4_error.dat");

    // double h = 0.01; // Tamaño de paso inicial
    double tolerance = 1e-4; // Tolerancia de error
    vector<double> datos;

    while(t<t_f) {
        rk4_error << t << " " << a << " " << v << " " << x << endl;

        // aplico rk4 adaptativo
        datos = adaptive_rk4(t, x, v_n, dt, tolerance, derivada);
        dt = datos[0];
        v = datos[1];
        x = x_n + v*dt;
        t = t + dt;

        x_n = x;
        v_n = v;
        a_n = a;
        dt = 0.1; // vuelvo al dt original

    }

    rk4_error.close();


    return 0;
}