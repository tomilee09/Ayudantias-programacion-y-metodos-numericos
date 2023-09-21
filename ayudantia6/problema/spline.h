#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>

using namespace std;

class Spline {
    private: 
        string nombre_archivo;
        vector<vector<double>> datos;
        vector<vector<double>> datos_interpolados;

    public:
        Spline(){};

        Spline(string nombre_archivo, int numero_columna){
            this->nombre_archivo = nombre_archivo;

            // lectura de datos
            vector<string> lineas = lector(nombre_archivo);
            vector<vector<string>> datos_string = separador(lineas);

            vector<double> t;
            vector<double> x;

            for(int i = 0; i<datos_string.size(); i++) {
                t.push_back(stod(datos_string[i][0]));
                x.push_back(stod(datos_string[i][1]));
            }

            this->datos.push_back(t);
            this->datos.push_back(x);

            this->datos_interpolados = interpolacion(datos);
        }

        vector<vector<double>> get_interpolacion() {
            return datos_interpolados;
        }

        vector<vector<double>> constantes(vector<double> t, vector<double> x) {
            int n = t.size()-1;

            vector<double> a(n+1);
            for(int i = 0; i<=n; i++) {
                a[i] = x[i];
            }

            vector<double> b(n, 0.);
            vector<double> c(n+1, 0.);
            vector<double> d(n, 0.);

            vector<double> h(n);
            for(int i = 0; i<=n-1; i++){
                h[i] = t[i+1]-t[i];
            }

            vector<double> r(n);
            for(int i = 1; i<=n-1; i++){
                r[i] = 3.*(a[i+1]-a[i])/h[i] - 3.*(a[i]-a[i-1])/h[i-1];
            }

            vector<double> l(n, 0.);
            vector<double> mu(n, 0.);
            vector<double> k(n, 0.);

            l[0] = 1.;
            mu[0] = 0.;
            k[0] = 0.;

            for(int i=1; i<n; i++)
            {
                l[i] = 2.*(t[i+1]-t[i-1]) - h[i-1]*mu[i-1];
                mu[i] = h[i]/l[i];
                k[i] = (r[i]-h[i-1]*k[i-1])/l[i];
            }
            
            l[n] = 1.;
            c[n] = 0.;
            k[n] = 0.;
            
            // a partir de los valores de los vectores anteriores se obtienen los vectores que contienen las constantes necesarias para el el spline cúbico
            for(int i=n-1; i>=0; i--)
            {
                c[i] = k[i]-mu[i]*c[i+1];
                b[i] = (a[i+1]-a[i])/h[i] - h[i]*(c[i+1] + 2.*c[i])/3.;
                d[i] = (c[i+1]-c[i])/(3.*h[i]);
            }

            vector<vector<double>> constantes;

            constantes.push_back(a);
            constantes.push_back(b);
            constantes.push_back(c);
            constantes.push_back(d);

            return constantes;
        }

        vector<vector<double>> interpolacion(vector<vector<double>> datos) {
            vector<double> t = datos[0];
            vector<double> x = datos[1];

            int n = t.size()-1;

            vector<vector<double>> mis_constantes = constantes(t, x);
            vector<double> a = mis_constantes[0];
            vector<double> b = mis_constantes[1];
            vector<double> c = mis_constantes[2];
            vector<double> d = mis_constantes[3];

            double t_j = 0;
            double polinomio;
            double n_puntos = 10;
            vector<vector<double>> interpolacion;


            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n_puntos; j++) {
                    polinomio = d[i]*t_j*t_j*t_j + c[i]*t_j*t_j + b[i]*t_j + a[i];
                    interpolacion.push_back(vector{t_j, polinomio});
                    t_j = t_j + (t[i+1]-t[i])/n_puntos;
                }
            }

            return interpolacion;
        }


        vector<string> lector(string texto)
        {
            // declaro el vector que almacenará las filas del archivo
            vector<string> lineas;
            // declaro el string linea que almacena la informacion de una linea individual
            string linea;
            
            // con ifstream guardo la informacion del archivo llamado texto
            ifstream myfile (texto);
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
        vector<vector<string>> separador(vector<string> lineas)
        {
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
};