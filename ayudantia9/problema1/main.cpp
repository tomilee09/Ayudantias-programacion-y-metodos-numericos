#include <iostream>
#include <vector>
#include "matriz.h"

using namespace std;

int main() {

    // sistema lineal
    vector<vector<double>> matriz1 = {{1, 2, 3, 1},
                                     {4, 5, 6, -4},
                                     {7, 8, 10, 2}};
    
    // calculo de la inversa
    vector<vector<double>> matriz2 = {{1, 2, 3},
                                     {4, 5, 6},
                                     {7, 8, 10}};
    
    // calculo del determinante
    vector<vector<double>> matriz3 = {{1, 2, 3},
                                     {4, 5, 6},
                                     {7, 8, 10}};

    // inicializacion de matrices sin cambios
    Matriz mi_matriz1(matriz1);
    Matriz mi_matriz2(matriz2);
    Matriz mi_matriz3(matriz3);
    cout << mi_matriz1 << endl << endl;

    // solucion del sistema lineal con pivoteo
    Matriz matriz_pivoteada = gauss(mi_matriz1);
    cout << matriz_pivoteada << endl << endl;

    // calculo de la inversa de una matriz
    Matriz mi_inversa = inversa(mi_matriz2);
    cout << mi_inversa << endl << endl;

    // calculo del determinante de una matriz
    double mi_determinante = determinante(mi_matriz3);
    cout << mi_determinante << endl << endl;


    return 0;
}