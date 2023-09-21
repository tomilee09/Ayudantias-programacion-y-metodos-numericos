#include<vector>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include <fstream>
#include"particula.h"

using namespace std;

int main() {
    // impongo que cada vez que el código corra los números aleatorios sean diferentes
    srand(time(NULL));

    int iteraciones = 10000;
    int numero_particulas = 1000;


    // creo un archivo que guarde las posiciones de las particulas
    ofstream archivo("posicion.txt");
    // dado que ahora tenemos varias particulas, las guardo en un vector
    vector<Particula> mis_particulas;
    // creo las particulas, las guardo en el vector, y guardo sus posiciones
    for(int i = 0; i<numero_particulas; i++) {
        Particula mi_particula(10., 10., 5.);
        mis_particulas.push_back(mi_particula);
        archivo << mi_particula.get_x() << ", " << mi_particula.get_y() << endl;
    }

    // guardo la posicion promedio de las particulas
    ofstream archivo2("posicion_promedio.txt");
    for(int i = 0; i<iteraciones; i++) {
        double suma_posicion_i = 0;
        for(int j = 0; j<numero_particulas; j++) {
            suma_posicion_i += mis_particulas[j].get_x();
            mis_particulas[j].step();
        }
        archivo2 << suma_posicion_i/numero_particulas << endl;
    }

    // guardo la velocidad promedio de las particulas
    ofstream archivo3("velocidad_promedio.txt");
    for(int i = 0; i<iteraciones; i++) {
        double suma_posicion_i = 0;
        for(int j = 0; j<numero_particulas; j++) {
            suma_posicion_i += mis_particulas[j].get_v_x();
            mis_particulas[j].step();
        }
        archivo3 << suma_posicion_i/numero_particulas << endl;
    }
}