// escriba un programa que entregue una lista con numeros primos hasta n
// demostrar que todos los números primos son coprimos

#include <iostream>
#include <vector>
using namespace std;

// funcion que comprueba si un número es primo y entrega un booleano
bool comprobar_primos(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true; 
}

// función que entrega una lista de números primos hasta n
vector<int> numeros_primos(int n) {
    vector<int> resultado;
    for(int i = 0; i<= n; i++) {
        if (comprobar_primos(i)) {
            resultado.push_back(i);
        }
    }
    return resultado;
}

// función recursiva que entrega el máximo común divisor entre a y b
int maximo_comun_divisor(int a, int b) {
    if (b == 0) {
        return a;
    }
    return maximo_comun_divisor(b, a%b);
}

// función que comprueba si en un vector todos los números son coprimos
bool comprobacion_coprimos(vector<int> numeros) {
    for(int i = 0; i < numeros.size(); i++) {
        for(int j = 0; j < numeros.size(); j++) {
            if (maximo_comun_divisor(numeros[i], numeros[j]) != 1) {
                if (i != j) {
                    return false;
                }
            }
        }
    }
    
    return true; 
}

/** en el main no puse cout's en honor al tiempo, vimos el contenido 
 * de las variables usando el debugger (C++ GDB/LLDB) **/ 
int main() {

    int n = 100;
    
    vector<int> numeros = numeros_primos(n);

    bool comprobacion = comprobacion_coprimos(numeros);

    return 0;
}