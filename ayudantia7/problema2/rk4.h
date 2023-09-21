#ifndef RK4_H
#define RK4_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/**
 * Clase de RK4 que puede resolver ecuaciones diferenciales en varias dimensiones
*/

template <class T>
class Rk4
{

private:
    T dt = 0.1; // delta t
    T t_i; // tiempo inicial
    T t_f; // tiempo final

    // condiciones iniciales en t_i
    vector<T> posiciones_iniciales; // (x, y, z)

    // ecuaciones diferenciales a resolver
    vector<T> (*derivadas)(vector<T>); // (t, x, y, z) 

public:
    Rk4(){};
    Rk4(vector<T> (*derivadas)(vector<T>), vector<T> posiciones_iniciales, T t_i, T t_f, T dt){
        this->dt = dt;
        this->t_i = t_i;
        this->t_f = t_f;
        this->posiciones_iniciales = posiciones_iniciales;
        this->derivadas = derivadas;
    };

    // función que resuelve la ode introducida al inicializar la clase
    void rk4(string nombre) {
        T t = t_i;
        vector<T> posiciones = posiciones_iniciales;
        // analogo a:
        // x = posiciones_iniciales[0]
        // y = posiciones_iniciales[0]
        // ...

        // guardo los datos en "nombre"
        ofstream rk4; 
        rk4.open(nombre);

        // numero variables
        int n_var = posiciones_iniciales.size(); 

        // guardo el valor de los k1, k2, k3, k4 para cada variable
        // analogo a crear k1_x, k1_y, ..., k2_x, k2_y, ..., k4_n
        vector<T> k1(n_var);
        vector<T> k2(n_var);
        vector<T> k3(n_var);
        vector<T> k4(n_var);

        // valores en los cuales está evaluado k1, k2, k3, k4 para cada componente
        // incluye la variable independiente (t), por ello tiene tamaño n_var+1
        vector<T> posicion_k1(n_var+1);
        vector<T> posicion_k2(n_var+1);
        vector<T> posicion_k3(n_var+1);
        vector<T> posicion_k4(n_var+1);

        // comienza a calcularse la solución de la ode hasta t_f
        while(t<t_f){
            // se guardan los datos en rk4
            rk4 << t << " ";
            for(int i = 0; i < n_var; i++) {
                rk4 << posiciones[i] << " ";
            }
            rk4 << endl;

            // pongo los valores independientes en la coordenada 0
            posicion_k1[0] = t;
            posicion_k2[0] = t+dt/2;
            posicion_k3[0] = t+dt/2;
            posicion_k4[0] = t+dt;

            // calculo los valores de posicion_k1 para todas las variables
            // dado que ya puse el tiempo, comienzo desde i+1
            for(int i = 0; i < n_var; i++){
                posicion_k1[i+1] = posiciones[i];
            }
            k1 = derivadas(posicion_k1);

            // sigo calculando los valores que van evaluados en k2, k3 y k4,
            // todo siguiendo los pasos del método runge-kutta-4
            for(int i = 0; i < n_var; i++){
                posicion_k2[i+1] = posiciones[i]+k1[i]*dt/2;
            }
            k2 = derivadas(posicion_k2);

            // calculo posicion_k3 y k3
            for(int i = 0; i < n_var; i++){
                posicion_k3[i+1] = posiciones[i]+k2[i]*dt/2;
            }
            k3 = derivadas(posicion_k3);

            // calculo posicion_k4 y k4
            for(int i = 0; i < n_var; i++){
                posicion_k4[i+1] = posiciones[i]+k3[i]*dt;
            }
            k4 = derivadas(posicion_k4);

            // lo anterior es análogo (para el caso n_var=3) a lo siguiente:
            // k1 = derivadas(t, x, y, z); 
            // k2 = derivadas(t+dt/2., x + k1[0]*dt/2., y + k1[1]*dt/2., z + k1[2]*dt/2.);
            // k3 = derivadas(t+dt/2., x + k2[0]*dt/2., y + k2[1]*dt/2., z + k2[2]*dt/2.);
            // k4 = derivadas(t+dt, x + k3[0]*dt, y + k3[1]*dt, z + k3[2]*dt);
            // (notese que habría que definir de forma distinta la función derivadas a como se hizo en la parte sin comentar) 

            // encontramos las siguientes posiciones para cada componente realizando un promedio sobre k1, k2, k3, k4,
            for(int i = 0; i<n_var; i++){
                posiciones[i] = posiciones[i] + 1./6.*(k1[i]+2*k2[i]+2*k3[i]+k4[i])*dt;
            }

            t = t+dt;
        }
        rk4.close();
    }
};

#endif