#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // constantes
    int N = 100; // puntos posicion
    int T = 1000; // puntos tiempo
    double L = 1.0;  // largo
    double k = 1.0; // constante de difusion

    // paso espacial
    double dx = L/N;

    // paso temporal, puse ese porque tiene que tener estabilidad (ver pdf profesor Toledo)
    double dt = dx*dx/(2*k);

    // inicializacion del vector de vectores de tamaño N por T
    double temperatura[N][T] = {0.0};

    // condiciones iniciales: a la derecha a estar caliente, a la izquierda frío
    for(int i = 0; i < N-1; i++){
        if(i<N/2){
            temperatura[i][0] = 0.;
        }
        else{
            temperatura[i][0] = 100.;
        }
    }

    // resolución del sistema con diferencias finitas
    for(int t = 0; t < T-1; t++){
        // condiciones de borde que se mantendrán en el tiempo
        temperatura[0][t] = 50; // condicion de borde izquierda a todo tiempo
        temperatura[N-1][t] = 50; // condicion de borde derecha a todo tiempo
        for(int x = 0; x< N-1; x++){
            // calculo de la doble derivada en x
            double temperatura_x_x = (temperatura[x+1][t]-2*temperatura[x][t]+temperatura[x-1][t])/(dx*dx);

            // se despeja temperatura[x][t+1] de la ecuacion (ver imagen ecuacion_difusion.png)
            temperatura[x][t+1] = k*dt*temperatura_x_x + temperatura[x][t];
        }
    }

    // se guarda el archivo en datos.txt
    ofstream file("datos.txt");
    for(int t = 0; t<T-1; t++){
        for(int x = 0; x<N-1; x++){
            file << (x*dx) << " " << (t*dt) << " " << temperatura[x][t] << endl;
        }
    }

    return 0;
}