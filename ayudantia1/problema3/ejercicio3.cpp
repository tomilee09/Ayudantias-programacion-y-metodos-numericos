// cree una función que logre leer archivos de texto como matrices
// separe la matriz en 2 vectores y aplique el producto tensorial
// guarde la matriz resultante en un archivo 

// lo siguiente era mi archivo matriz_lectura.txt, la pongo aqui para no poner otra foto
/**
1,  2
3, 4
5,    6
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// funcion que lee un archivo y que obtiene todos los números de su interior como una matriz 
vector<vector<int>> leer_matriz(string nombre_archivo) {
    vector<vector<int>> resultado; // creo una matriz para luego modifiarla
    ifstream archivo(nombre_archivo); // leo el archivo
    string linea;
    string numero_texto = ""; // voy a almacenar los números aqui en forma de texto, luego los paso a enteros (int)
    while(getline(archivo, linea)){ // para cada linea (y mientras haya lineas) hago lo siguiente
        vector<int> mi_vector;
        for (int i =0; i<linea.size(); i++) { // para cada letra de la linea hago lo siguiente
            if (linea[i] != ' ' && linea[i] != ',') { // si no es un espacio o una coma, lo agrego
                numero_texto = numero_texto + linea[i];
            }
            else if (numero_texto != "") { // si ya terminé de agregar números, asumo terminó el número, y lo agrego al vector
                mi_vector.push_back(stoi(numero_texto)); // transformo un string a int
                numero_texto = ""; // reinicio numero_texto para el siguiente número
            }
        }
        // la siguiente parte es por si hago un salto de linea, como no sigue un espacio o una coma, no agregaba el número del final
        if (numero_texto != "") {
            mi_vector.push_back(stoi(numero_texto));
            numero_texto = "";
        }
        // finalmente agrego el vector resultante de esta linea, esto lo hago para cada linea y así hago una matriz
        resultado.push_back(mi_vector);
    }
    return resultado; // entrego la matriz modificada
}

// funcion con la cual realizo el producto tensorial
vector<vector<int>> producto_tensorial(vector<int> vector1, vector<int> vector2) {
    vector<vector<int>> resultado(vector1.size(), vector<int>(vector2.size()));
    for(int i = 0; i<vector1.size(); i++) {
        for(int j = 0; j<vector2.size(); j++) {
            resultado[i][j] = vector1[i]*vector2[j];
        }
    }
    return resultado;
}

int main() {
    // creo la matriz leyendo el archivo
    vector<vector<int>> matriz = leer_matriz("matriz_lectura.txt");
    
    // obtengo los 2 vectores
    vector<int> vector1;
    vector<int> vector2;
    for(int i = 0; i<matriz.size(); i++) {
        vector1.push_back(matriz[i][0]);
        vector2.push_back(matriz[i][1]);
    }

    // realizo el producto tensorial
    vector<vector<int>> producto = producto_tensorial(vector1, vector2);
    
    // guardo los datos
    ofstream archivo("datos.txt");
    for(int i = 0; i<vector1.size(); i++) {
        for(int j = 0; j<vector2.size(); j++) {
            archivo << producto[i][j] << " "; 
        }
        archivo << endl;
    }
    
    return 0;
}