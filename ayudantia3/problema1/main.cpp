#include<iostream>
#include<cmath>
#include"dual.h"

using namespace std;

int main(){
    // creo un número dual
    Dual<double> mi_dual(5.13, 1);
    
    // calculo lo que pide el enunciado
    cout << cos(mi_dual) - sin(mi_dual)*sin(mi_dual) + mi_dual*4;
    // (20.0901, 5.65551) comprobado con calculadora
    
    return 0;
}