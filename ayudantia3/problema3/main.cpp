#include<iostream>
#include<vector>
#include<cmath>
#include"fraccion.h"
#include"decimal.h"

using namespace std;

int main() {
    // creo 2 decimales
    vector<int> numeros{1, 2, 3, 4, 5, 6, 7, 8, 9};
    Decimal mi_decimal(numeros, 1);
    Decimal otro_decimal(numeros, 1);
    mi_decimal.print();

    // realizo la suma entre 2 decimales
    Decimal suma = mi_decimal+otro_decimal;
    suma.print();

    // compruebo lo del enunciado de la pregunta
    Fraccion mi_fraccion(1, 2);
    Decimal decimal05({0, 5}, 1);
    Decimal suma_con_fraccion = decimal05 + mi_fraccion;
    suma_con_fraccion.print();
    return 0;
}