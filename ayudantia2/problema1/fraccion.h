#ifndef FRACCION_H
#define FRACCION_H
// ifndef significa if not define, es para cuando tengan que usar su clase en archivos que se llaman entre ellos, y no definan varias veces su clase
// por lo que, si no está previamente definida, definela
// siempre se pone el nombre del archivo en mayúsculas, un guión bajo representando el punto, y la extensión que tenga, para este caso una h

#include<iostream>

using namespace std;

// cre la clase Fraccion, por convención siempre empiezan con mayúscula
class Fraccion {
    // en privado almaceno las variables básicas de mi clase, las que la definen
    private:
        int numerador;
        int denominador;
    // en público defino todo lo demás
    public:
        // defino el contructor por defecto
        Fraccion() {};
        // defino el constructor que me crea una fracción a partir de 2 números
        Fraccion(int a, int b) {
            numerador = a;
            denominador = b;
        }

        // con esta función muestro en pantalla la fracción
        void print() {
            cout << numerador << "/" << denominador << endl;
        }

        // función máximo común divisor
        int MCD(int a, int b) {
            if(b==0) {
                return a;
            }
            return MCD(b, a%b);
        }

        // uso la función máximo común divisor para simplificar
        void simplicar() {
            int mcd = MCD(numerador, denominador);
            numerador = numerador / mcd;
            denominador = denominador / mcd;
        }

        // sobrecarga del operador suma, es la suma de fracciones multiplicando por el denominador
        Fraccion operator+ (Fraccion otra_fraccion) {
            Fraccion resultado;
            resultado = Fraccion(numerador*otra_fraccion.denominador + denominador*otra_fraccion.numerador, denominador*otra_fraccion.denominador);
            return resultado;
        }

        // sobrecarga del operador multiplicacion para multiplicación de fracciones
        Fraccion operator* (Fraccion otra_fraccion) {
            Fraccion resultado;
            resultado = Fraccion(numerador*otra_fraccion.numerador, denominador*otra_fraccion.denominador);
            return resultado;
        }

        // sobrecarga del operador multiplicación para multiplicación por un escalar
        Fraccion operator* (int x) {
            Fraccion resultado;
            resultado = Fraccion(numerador*x, denominador);
            return resultado;
        }

        // sobrecarga del operador resta
        Fraccion operator- (Fraccion otra_fraccion) {
            Fraccion resultado;
            resultado = Fraccion(numerador*otra_fraccion.denominador - denominador*otra_fraccion.numerador, denominador*otra_fraccion.denominador);
            return resultado;
        }
};

// esto hay que ponerlo para cerrar el #ifndef del inicio
#endif