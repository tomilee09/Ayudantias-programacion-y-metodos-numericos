#include <iostream>
#include <cmath>

using namespace std;

/**
 *  ¿Cuales son las raices de funcion1?,  
 * notemos que funcion1 es no lineal por lo que se debe usar alguno de los algoritmos no lineales
 * en este archivo se usan los algoritmos enseñados en el curso, biseccion, newton y secante 
*/


// funcion a la cual se le quiere encontrar las raices
double funcion1(double x) {
    return x*x-1;
}

// derivada de la funcion anterior (usada en newton)
double funcion1_derivada(double x) {
    return 2*x;
}

// funcion que realiza el método de la biseccion para encuentrar la raiz de una funcion
// a y b es el intervalo donde se busca la solucion
// f es la funcion a la cual se le busca la raiz
double biseccion(double a, double b, double epsilon, int iteraciones, double (*f)(double)) {
    // se inicializan las variables
    double f_a = f(a);
    double f_b = f(b);
    int iteracion = 0;
    double promedio = 0;
    double f_promedio = 0;

    // se debe cumplir que f_a < 0 y que f_b > 0 o viceversa 
    if(f_a*f_b>=0) {
        cout << "mu mal" << endl;
        return 123; // devuelvo algo random para que se detenga la función
    }

    // iteracion en la cual se encontrará la raiz, se detendrá si a y b están muy cerca o si se pasó el máximo de iteraciones
    while(abs(b-a)>epsilon && iteracion < iteraciones) {
        promedio = (a+b)/2.;
        f_promedio = f(promedio);

        // si el valor f_promedio está "en el mismo lado" que f_a (ambos son positivos por ejemplo), entonces "promedio" reemplaza a "a" 
        if(f_promedio*f_a>0) {
            a = promedio;
            f_a = f_promedio;
        }

        // en caso contrario al anterior, "promedio" reemplaza a "b"
        else {
            b = promedio;
            f_b = f_promedio;
        }

        iteracion += 1;
    }

    return promedio;
}


// funcion que realiza el método de newton para encuentrar la raiz de una funcion
// a es el punto inicial del cual parte, solo usa un punto porque tambien se le debe ingresar f_derivada
// f es la funcion a la cual se le busca la raiz
double newton(double a, double epsilon, int iteraciones, double (*f)(double), double (*f_derivada)(double)) {
    // se inicializan variables
    double raiz = a;
    int iteracion = 0;

    // se itera para encontrar las raices
    while(iteracion < iteraciones){
        raiz = raiz - f(raiz)/f_derivada(raiz); // formula del PDF de profesor Toledo
        iteracion += 1;
    }

    return raiz;
}


// funcion que realiza el método de la secante para encuentrar la raiz de una funcion
// x0 y x1 es el intervalo donde se busca la solucion, se usan 2 puntos para aproximar la derivada
// f es la funcion a la cual se le busca la raiz
double secante(double x0, double x1, double epsilon, int iteraciones, double (*f)(double)) {
    // inicializo variables
    int iteracion = 0;

    double f0 = f(x0);
    double f1 = f(x1);

    double interseccion = 0.;
    double f_interseccion = 0.;

    // iteracion en la cual se encontrará la raiz, se detendrá si x0 y x1 están muy cerca o si se pasó el máximo de iteraciones
    while(abs(x1-x0)>epsilon && iteracion < iteraciones) {
        interseccion = x1 -f1*(x1-x0)/(f1-f0); // formula del PDF del profesor Toledo
        f_interseccion = f(interseccion);

        // se cambian las variables para la siguiente iteracion
        x0 = x1;
        x1 = interseccion;
        f0 = f1;
        f1 = f_interseccion;
    }

    return interseccion;
}




int main() {
    // Parámetros de los métodos
    double epsilon = 0.0001;
    int iteraciones = 10000;

    // se aplica el método de la bisección
    double raiz_biseccion = biseccion(200, 0, epsilon, iteraciones, funcion1);
    cout << raiz_biseccion << endl;

    // se aplica el método de la secante
    double raiz_secante = secante(-2, 0, epsilon, iteraciones, funcion1);
    cout << raiz_secante << endl;

    // se aplica el método de newton
    double raiz_newton = newton(1000, epsilon, iteraciones, funcion1, funcion1_derivada);
    cout << raiz_newton << endl;

    return 0;
}