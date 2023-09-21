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

#endif