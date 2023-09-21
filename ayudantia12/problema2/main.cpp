#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "shooting.h"

using namespace std;
// Definir la ecuación diferencial

double f(double x, double y, double u) {
    return x * x * y - 11 * y;
}

int main() {
    double x0 = -5.5;
    double x1 = 5.5;
    double y0 = 0.857763884960710;
    double y1_objetivo = -0.857763884960710;
    double dx = 0.0001

    return 0;
}