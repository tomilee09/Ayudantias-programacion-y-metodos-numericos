#ifndef Matriz_H
#define Matriz_H

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


/**
 * Este es un template de matrices que cree anteriormente, la utilizo 
 * como base para realizar los métodos que requieren matrices
*/


template <class T>
class Matriz
{
private:
    vector<vector<T>> matrix;
public:
    Matriz(); // constructor por defecto
    Matriz(vector<vector<T>>); // constructor a base de un vector
    Matriz(int, int); // constructor vacio nxm
    Matriz(const Matriz &); // constructor de copia
    vector<vector<T>> get(); // obtener elementos
    int filas() const;
    int columnas() const;
    T operator()(int, int) const; // lectura
    T & operator()(int, int); // lectura y escritura
    Matriz<T> operator=(const Matriz<T>&); // se sobrecarga el operador asignacion
    ~Matriz();/*destructor/liberar, se usa al apartar/reservar memoria con (new tipo)*/
};

template <class T>
Matriz<T>::Matriz() // constructor defecto
{}

// constructor de copia
template <class T>
Matriz<T>::Matriz(const Matriz & a)
{
    matrix = a.matrix;
}

// se implementa el destructor
template <class T>
Matriz<T>::~Matriz()
{}

template <class T>
Matriz<T>::Matriz(int a, int b)
{
    vector<vector<T>> m; // resultado
    vector<T> m1;
    for(int i = 0; i < b; i++)
    {
        m1.push_back(0);
    }
    for(int j = 0; j < a; j++)
    {
        m.push_back(m1);
    }
    matrix = m;
}

// constructor a base de un vector de vectores
template<class T>
Matriz <T>::Matriz(vector<vector<T>> a)
{
    matrix = a;
}

// para obtener la base de la matriz
template <class T>
vector<vector<T>> Matriz<T>::get()
{
    return matrix;
}

// numero de columnas
template<class T>
int Matriz<T>::columnas() const
{
    return matrix[0].size();
}

// numero de filas
template<class T>
int Matriz<T>::filas() const
{
    return matrix.size();
}

// sobrecarga operador ()
template<class T>
T Matriz<T>::operator()(int i, int j) const
{
    return matrix[i][j];
}

template <class T>
T & Matriz <T>::operator()(int i, int j)
{
    return matrix[i][j];
}


// se implementa la sobrecarga del operador =
template <class T>
Matriz<T> Matriz<T>::operator=(const Matriz<T>&x)
{
    if(this!=&x)
    {
        matrix = x.matrix;
    }
  return *this;
}



// se implementa el operador suma entre dos matrices
template <class T>
Matriz<T> operator+(Matriz<T> &x1, Matriz<T> &x2)
{
    Matriz<T> suma(x1.filas(), x1.columnas());
    for(int i = 0; i < x1.filas(); i++)
    {
        for(int j = 0; j < x1.columnas(); j++)
        {
            suma(i, j) = x1(i, j) + x2(i, j);
        }
    }
    return suma;
}

// se implementa el operador multiplicacion entre dos matrices
template <class T>
Matriz<T> operator*(const Matriz<T> &x1, const Matriz<T> &x2)
{
    Matriz<T> mult(x1.filas(), x2.columnas());
    for(int i = 0; i < x1.filas(); i++)
    {
        for(int j = 0; j < x2.columnas(); j++)
        {
            for(int k = 0; k < x1.columnas(); k++)
            {
                mult(i, j) = mult(i, j) + x1(i, k)*x2(k, j);
            }
        }
    }
    return mult;
}



// se implementa la multiplicacion entre una matriz y un escalar
template <class T>
Matriz<T> operator*(T s, const Matriz<T> &x)
{
    Matriz<T> mult(x.filas(), x.columnas());
    for(int i = 0; i < x.filas(); i++)
    {
        for(int j = 0; j < x.columnas(); j++)
        {
            mult(i, j) = s*x(i, j);
        }
    }
    return mult;
}


// se implementa la transpuesta de una matriz
template <class T>
Matriz<T> transpuesta(const Matriz<T> &x)
{
Matriz<T> transpuesta(x.columnas(), x.filas());
for(int i = 0; i < x.filas(); i++)
{
 for(int j = 0; j < x.columnas(); j++)
 {
     transpuesta(j, i) = x(i, j);
 }
}
return transpuesta;
}




// se muestra en pantalla un objeto de la clase Matriz
template<class T>
ostream & operator<<(ostream & os, Matriz<T> a)
{
    vector<vector<T>> x = a.get();
    os << "[";
    for(int i = 0; i< x.size(); i++)
    {
        if(i==(x.size()-1))
        {
            os << "[";
            for(int j = 0; j<x[i].size(); j++)
            {
                if(j==(x[i].size()-1))
                {
                    os << x[i][j];
                }
                else
                {
                    os << x[i][j] << " ,";
                }
            }
            os << "]]" ;

        }
        else
        {
            os << "[";
            for(int j = 0; j<x[i].size(); j++)
            {
                if(j == (x[i].size()-1))
                {
                    os << x[i][j];
                }
                else
                {
                    os << x[i][j] << " ,";
                }
            }
            os << "]," << "\n";
        }
    }
    return os;
}


// Variable global contador, se usa para ver el signo del determinante, indica la cantidad de veces que las filas se intercambiaron en la eliminacion gaussiana
int contador = 0;

////////////////// GAUSS ////////////////////
// toma una matriz nxm y le aplica eliminacion gaussiana
template <class T>
Matriz<T> gauss(const Matriz<T> &x)
{
    // se crea la matriz que será solucion
    Matriz<T> m_gauss = x;

    // seteo la variable contador para que cada vez que aplique gauss inicie como 0, porque si hiciera gauss sobre la misma matriz varias veces se podría ir acumulando
    contador = 0;

    // se selecciona el pivote máximo de todas las filas (pivote es simplemente un número)
    for(int i = 0; i < m_gauss.filas(); i++) {
        T pivote = m_gauss(i, i); // asumo el pivote máximo es el elemento (i, i) de forma arbitraria
        int fila_pivote_maximo = i;
        for(int j = 0; j < m_gauss.filas(); j++){ // busco en todas las filas a ver si hay un pivote mayor
            if(abs(m_gauss(i, j)) > abs(pivote)) {
                pivote = m_gauss(i, j);
                fila_pivote_maximo = j;
            }
        }

        // si elegí un pivote que no esté en la diagonal, intercambio la fila del pivote máximo con la fila de la diagonal
        // esto es para que al final me quede una matriz diagonalizada
        if(fila_pivote_maximo != i) {
            for(int j = 0; j<m_gauss.columnas(); j++){
                double dato_i_j = m_gauss(i, j);
                m_gauss(i, j) = m_gauss(fila_pivote_maximo, j);
                m_gauss(fila_pivote_maximo, j) = dato_i_j;
            }
            contador += 1; // esto es para el determinante, para contar la cantidad de veces que se intercambian las filas, variable no usada directamente en gauss()
        }

        // parte fundamental del pivoteo, se aplican las restas para hacer 0's en todo lo que no sea la diagonal
        for(int j=0; j<m_gauss.filas(); j++){
            if(i!=j){ // aqui elijo eliminar todo lo que no sea la diagonal, si solo se quiere eliminar la parte de abajo de la matriz poner "i<j"
                T factor = m_gauss(j, i)/m_gauss(i, i);
                for(int k = 0; k<m_gauss.columnas(); k++){ // se aplica la resta de una fila a otra fila
                    m_gauss(j, k) = m_gauss(j, k) - factor*m_gauss(i, k);
                }
            }
        }
    }

    return m_gauss;
}



////////////////// INVERSA ////////////////////
// toma una matriz nxn y devuelve su inversa , calculoada a partir de la eliminacion gaussiana
template <class T>
Matriz<T> inversa(const Matriz<T> &x)
{
    // creo una matriz llamada extendida, será el doble de largo que mi matriz original
    Matriz<T> extendida(x.filas(), x.columnas()*2);

    // a la izquierda de extendida pongo la matriz original
    for(int i = 0; i < x.filas(); i++) {
        for(int j = 0; j < x.columnas(); j++){
            extendida(i, j) = x(i, j);
        }
    }

    // a la derecha de la matriz extendida pondré la matriz identidad
    for(int i = 0; i < x.filas(); i++) {
        extendida(i, i + x.columnas()) = 1;
    }

    // le aplico eliminacion gaussiana a la matriz extendida
    extendida = gauss(extendida);

    // mi eliminación gaussiana no divide las filas por los elementos de la diagonal, así que divido por ellos
    for(int i = 0; i < x.filas(); i++) {
        T factor = extendida(i, i);
        for(int j = 0; j < x.columnas(); j++){
            extendida(i, j + x.columnas()) = extendida(i, j+ x.columnas())/factor;
        }
    }

    // creo una matriz a la cual llamaré inversa
    Matriz<T> inversa(x.filas(), x.columnas());

    // los elementos de la matriz llamada inversa serán los elementos de la derecha de la matriz extendida luego de aplicarle eliminacion gaussiana
    for(int i = 0; i<x.filas(); i++){
        for(int j = 0; j<x.columnas(); j++){
            inversa(i, j) = extendida(i, j+x.columnas());
        }
    }

    // entrego la matriz inversa
    return inversa;
}



////////////////// DETERMINANTE ////////////////////
// calcula el determinante a partir de aplicar eliminacion gaussiana
template <class T>
T determinante(const Matriz<T> &x)
{
    // mi matriz reducida m_reducida será mi matriz x a la cual le aplico eliminacion gaussiana
    Matriz<T> m_reducida = gauss(x);

    // creo una variable determinante que partirá siendo 1
    T determinante = 1.;

    // veo de que signo es el determinante con la variable contador, la cual se define arriba como una variable global
    // es modificada dentro de gauss() y dado que la variable es global los cambios quedan guardados dentro de todo el código
    determinante = determinante*pow(-1, contador);

    // multiplico la variable determinante por los elementos de la diagonal de la matriz reducida
    for(int i = 0; i < x.filas(); i++){
        determinante = determinante * m_reducida(i, i);
    }

    // entrego el determinante como output
    return determinante;
}


#endif