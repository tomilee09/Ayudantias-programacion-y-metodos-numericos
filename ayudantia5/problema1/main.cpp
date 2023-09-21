#include<vector>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include <fstream>
#include"particula_browniana.h"

using namespace std;

int main() {
    // impongo que cada vez que el código corra los números aleatorios sean diferentes
    srand(time(NULL));
    // ejemplo de número aleatorio entre -1 y 1
    cout << 2*(rand()%1000/1000.)-1 << endl;

    // creo archivo para guardar los datos de la posicion
    ofstream archivo("posicion.txt");
    // creo una particula browniana que avance un paso de largo 1
    Particula_browniana mi_particula(1.);
    int iteraciones = 10000;

    // durante 10000 iteraciones guardo la posicion de la particula y esta se mueve
    for(int i = 0; i<iteraciones; i++) {
        archivo << mi_particula.get_x() << ", " << mi_particula.get_y() << endl;
        mi_particula.step();
    }
}