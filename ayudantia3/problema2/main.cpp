#include<iostream>
#include<cmath>
#include"numeromod.h"
#include"planet_cal.h"


using namespace std;

int main(){
    // hora_global, duracion_dia, duracion_semana, duracion_año
    // hoy a las 11:00 pasaron 2405 horas desde año nuevo
    Planet_cal tierra(10000, 24, 7, 52);
    Planet_cal marte(10000, 25, 7, 98);
    tierra.print();
    marte.print();
    cout << endl;
    
    // podemos hacer la suma por un escalar para pasar 100000 horas
    tierra+100000;
    marte+100000;
    tierra.print();
    marte.print();
    cout << endl;

    // podemos hacer la resta de horas entre los calendarios de los planetas
    Planet_cal jupiter(1000000, 10, 7, 624);
    jupiter.print();
    jupiter = jupiter - tierra;
    jupiter.print();
    return 0;
}