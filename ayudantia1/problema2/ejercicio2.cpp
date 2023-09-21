// Cree una matriz cuyos valores sean su número de fila
// luego apliquele la transpuesta
// finalmente guarde los datos

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {

    // crear la matriz
    int n = 3;
    vector<vector<int>> matriz(n, vector<int>(n));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            matriz[i][j] = i;
        }
    }

    // aplicar transpuesta
    vector<vector<int>> matriz_copia = matriz;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            matriz[i][j] = matriz_copia[j][i];
        }
    }

    // guardar
    ofstream archivo("datos.txt");
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            archivo << matriz[i][j] << " ";
        }
        archivo << endl;
    }

    return 0;
}