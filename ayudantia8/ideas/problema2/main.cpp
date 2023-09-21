/* MONTE CARLO EN 3D */

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double parametricFunction(double x, double y, double z) {
    if (x * x + y * y + z * z <= 9) { // x*x +y*y < z
        return 1.0;  // Punto dentro de la esfera
    }
    else {
        return 0.0;  // Punto fuera de la esfera
    }
}

int main() {
    // Configuración del algoritmo Monte Carlo
    double numSamples = 1000000;  // Número de muestras a generar
    double countInside = 0;       // Contador de muestras dentro de la figura

    // Generación de las muestras y conteo de las que están dentro de la figura
    srand(time(0));  // Semilla para la generación de números aleatorios
    // double rango = 5.;

    for (int i = 0; i < numSamples; i++) {
        // Generar coordenadas aleatorias en el rango [-rango, rango]
        double x = -3. + 6. * rand()/RAND_MAX;
        double y = -3. + 6. * rand()/RAND_MAX;
        double z = -3. + 6. * rand()/RAND_MAX;

        // sumar si está dentro
        countInside+=parametricFunction(x, y, z);
    }
    cout << countInside;
    // Cálculo del volumen utilizando la fórmula de Monte Carlo
    double volume = (countInside / numSamples) * 6.*6.*6.; // el 8 sale porque es el volumen de un cubo de 2x2x2

    // Mostrar el resultado
    cout << "El volumen de la figura paramétrica es: " << volume << endl;

    return 0;
}