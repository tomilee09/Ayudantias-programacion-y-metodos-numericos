#include<vector>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<fstream>
#include"spline.h"

using namespace std;

int main() {
    Spline spline_x("datos.dat", 1);
    Spline spline_y("datos.dat", 2);

    ofstream archivo_interpolacion;
    archivo_interpolacion.open("archivo_interpolacion.dat");
    for(int i = 0; i < spline_x.get_interpolacion().size(); i++){
        archivo_interpolacion << spline_x.get_interpolacion()[i][0] << " " << spline_x.get_interpolacion()[i][1] << " " << spline_y.get_interpolacion()[i][1] << endl;
    }

    archivo_interpolacion.close();
    return 0;
}