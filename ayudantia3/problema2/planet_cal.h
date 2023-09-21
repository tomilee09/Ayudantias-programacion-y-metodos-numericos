#ifndef PLANET_CAL_H
#define PLANET_CAL_H

#include<iostream>
#include"numeromod.h"

using namespace std;

// creo la clase planet_cal (planet calendar)
class Planet_cal {
    private: 
        int hora_global;
        int duracion_dia_horas;
        int duracion_semana_dias;
        int duracion_year_semanas;
        Numeromod hora;
        Numeromod dia;
        Numeromod semana;
        Numeromod year;
    public:
        Planet_cal(){}
        Planet_cal(int hora_global, int duracion_dia_horas, int duracion_semana_dias, int duracion_year_semanas){
            this->hora_global = hora_global; 
            this->duracion_dia_horas = duracion_dia_horas; // duracion del dia en horas (ej: 24)
            this->duracion_semana_dias = duracion_semana_dias; // duracion de la semana en dias (ej: 7)
            this->duracion_year_semanas = duracion_year_semanas; // duracion año en semanas (ej: 52)

            // uso Numeromod para aplicar módulo a la hora global
            this->hora = Numeromod(hora_global, duracion_dia_horas);
        
            // uso int(numero_double) porque sirve para truncar sin importar el decimal, por ejemplo: int(1.9) = 1
            // hora_global/duracion_dia_horas = n_dias
            this->dia = Numeromod(int(hora_global/duracion_dia_horas), duracion_semana_dias); 

            // hora_global/duracion_dia_horas/duracion_semana_dias = n_semanas
            this->semana = Numeromod(int(hora_global/duracion_dia_horas/duracion_semana_dias), duracion_year_semanas);
            
            // hora_global/duracion_dia_horas/duracion_semana_dias/duracion_year_semanas = n_años 
            // puse 10000 para que no se aplique el módulo al número, porque los años no son cíclicos
            // ahora que lo pienso, no debería haberlo definido como Numeromod, simplemente es un int, mala mía
            this->year = Numeromod(int(hora_global/duracion_dia_horas/duracion_semana_dias/duracion_year_semanas), 10000);
        }

        // función para mostrar en pantalla la hora, dia, semana, año
        void print() {
            cout << "hora: " << hora << ", dia: " << dia << ", semana: " << semana << ", año: " << year << endl;
        }

        // sobrecarga de la operación + para un escalar
        void operator+(int horas_nuevas) {
            this->hora_global += horas_nuevas;
            this->hora = Numeromod(hora_global, duracion_dia_horas);
            this->dia = Numeromod(int(hora_global/duracion_dia_horas), duracion_semana_dias);
            this->semana = Numeromod(int(hora_global/duracion_dia_horas/duracion_semana_dias), duracion_year_semanas);
            this->year = Numeromod(int(hora_global/duracion_dia_horas/duracion_semana_dias/duracion_year_semanas), 10000);
        }

        // sobrecarga de la operación - entre planet_cal
        Planet_cal operator-(Planet_cal otro_planet_cal) {
            int resultado_horas = hora_global - otro_planet_cal.hora_global;
            return Planet_cal(resultado_horas, duracion_dia_horas, duracion_semana_dias, duracion_year_semanas);
        }


};

#endif

