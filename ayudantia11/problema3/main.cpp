#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include "matriz.h"
#include "regresion.h"
#include <fstream>

using namespace std;

/** Tenemos el siguiente sistema de ecuaciones: 
 * 3x + 4    =   k_1*x + k_2*y + k_3*z
 * 19x -3    =   k_4*(-x+z+y)
 * 7z + 2    =   k_5*abs(x-10) + k6*k5 // k6 se encuentra con el intercepto
 * (asumamos no se puede despejar la parte de la izquierda de la ecuacion)
 * se debe resolver aplicando 3 veces regresion lineal para varias variables
 * notemos que la primera nos dará un intercepto (que no nos interesa) y 3 pendientes, que serán k1, k2, k3.
 * para la segunda ecuación tomamos (-x+z+y) como solo una variable (solo una columna en la matriz a resolver)
 * y con esa encontramos solo una pendiente (k4) y un intercepto que no nos interesa.
 * Por último se debe crear una una variable (columna) con abs(x-10), donde la pendiente será k5 y el 
 * intercepto será k6*k5, y como k5 es conocido, k6 es conocido.
*/



vector<string> lector(string texto){
    // declaro el vector que almacenará las filas del archivo
    vector<string> lineas;
    // declaro el string linea que almacena la informacion de una linea individual
    string linea;
    
    // con ifstream guardo la informacion del archivo llamado texto
    ifstream myfile(texto);
    // realizo una iteracion para cada linea del archivo leido
    while(getline (myfile,linea))
    {
        // cada linea la guardo en el vector llamado lineas
        lineas.push_back(linea);
    }
    // la función entrega el vector lineas
    return lineas;
}
// implemento la funcion separador que tomara un vector lineas (el creado justo arriba) e irá separando las palabras contenidas en las lineas
vector<vector<string>> separador(vector<string> lineas){
    // creo un vector de vectores llamado palabras que irá almacenando las palabras de cada fila
    vector<vector<string>> palabras;
    
    // creo una iteracion por cada linea del archivo leido
    for(int i = 0; i<lineas.size(); i++)
    {
        // creo un vector en el cual almacenaré las palabras de la i-esima linea
        vector<string> vectori;
        // declaro e implemento el string palabra con valor " "
        string palabra = " ";
        // creo una iteracion por cada letra de la linea i-esima
        for(int j = 0; j<=lineas[i].length(); j++)
        {
            // tomo la j-esima letra de la i-esima linea
            char caracter = lineas[i][j];
            // si la letra que tomé es igual a un espacio tabulado o es la última letra de la linea pasa algo
            if(caracter == '\t' || caracter == ' ' || j==lineas[i].length())
            {
                // agrego la palabra al vector vectori
                vectori.push_back(palabra);
                // hago que palabra vuelva a valer " "
                palabra = " ";
            }
            // si lo anterior no se cumple pasa algo
            else
            {
                //agrego el caracter ch al string palabra
                palabra.push_back(caracter);
            }
        } 
        // agrego el vector vectori al vector de vectores palabras
        palabras.push_back(vectori);
    }
    // la funcion entrega el vector de vectores palabras
    return palabras;
}



int main(){
    // leo los datos
    vector<string> lineas = lector("datos.txt");
    vector<vector<string>> datos_string = separador(lineas);
    
    vector<double> x;
    vector<double> y;
    vector<double> z;

    // guardo los datos en x, y, z
    for(int i = 0; i<datos_string.size(); i++){
        x.push_back(stod(datos_string[i][0]));
        y.push_back(stod(datos_string[i][1]));
        z.push_back(stod(datos_string[i][2]));
    }



    //////////ECUACION 1: 3x + 4 = k_1*x + k_2*y + k_3*z /////////////
    // creo la matriz necesaria para resolver la primera ecuacion 
    // creo mi variable dependiente
    vector<double> tres_x_mas_4;
    for(int i = 0; i<x.size(); i++){
        tres_x_mas_4.push_back(3*x[i]+4);
    }

    // creo la matriz con varias variables
    vector<vector<double>> ecuacion1;
    ecuacion1.push_back(x);
    ecuacion1.push_back(y);
    ecuacion1.push_back(z);
    ecuacion1.push_back(tres_x_mas_4);

    // realizo la regresion y encuentro las pendientes
    Regresion regresion1(ecuacion1);
    vector<double> constantes1 = regresion1.regresion_lineal();
    cout << "k1: " << constantes1[1] << " k2: " << constantes1[2] << " k3: " << constantes1[3] << " " << endl; 
    // notese que constantes1[0] es el intercepto, no nos interesa ahora asi que no lo mostré



    //////////ECUACION 2: 19x - 3 = k_4*(-x+z+y) /////////////
    // creo la matriz necesaria para resolver la segunda ecuacion 
    vector<vector<double>> ecuacion2;

    // creo la variable independiente
    vector<double> menos_x_mas_z_mas_y;
    for(int i = 0; i<x.size(); i++){
        menos_x_mas_z_mas_y.push_back(-x[i]+z[i]+y[i]);
    }
    ecuacion2.push_back(menos_x_mas_z_mas_y);

    // creo la variable dependiente
    vector<double> d19_y_menos_3;
    for(int i = 0; i<x.size(); i++){
        d19_y_menos_3.push_back(19*x[i]-3);
    }
    ecuacion2.push_back(d19_y_menos_3);

    // realizo la regresion
    Regresion regresion2(ecuacion2);
    vector<double> constantes2 = regresion2.regresion_lineal();
    cout << "k4: " << constantes2[1]  << endl; 
    // notese que constantes2[0] es el intercepto, no nos interesa ahora asi que no lo mostré



    /////////////// TERCERA ECUACION 7z + 2 = k_5*abs(x-10) + k6*k5  ////////////////////
    // creo la matriz necesaria para resolver la tercera ecuacion 
    vector<vector<double>> ecuacion3;

    // creo la variable independiente
    vector<double> abs_x_10;
    for(int i = 0; i<x.size(); i++){
        abs_x_10.push_back(abs(x[i]-10));
    }
    ecuacion3.push_back(abs_x_10);
    
    // creo la variable dependiente
    vector<double> s7_z_mas_2;
    for(int i = 0; i<x.size(); i++){
        s7_z_mas_2.push_back(7*z[i]+2);
    }
    ecuacion3.push_back(s7_z_mas_2);

    // realizo la regresion lineal
    Regresion regresion3(ecuacion3);
    vector<double> constantes3 = regresion3.regresion_lineal();
    cout << "k6*k5 = " << constantes3[0] << ", k5 = " << constantes3[1] << endl;

    return 0;
}