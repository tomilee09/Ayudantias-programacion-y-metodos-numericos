#ifndef NUMEROMOD_H
#define NUMEROMOD_H

#include<iostream>

using namespace std;

// Creo la clase numeromod: numero modular
class Numeromod {
    private: 
        // aqui defino el número
        int numero;
        // aqui defino su módulo
        int modulo;
    public:
        Numeromod(){}
        Numeromod(int numero, int modulo){
            // en la construcción del objeto le aplico inmediatamente el módulo
            this->numero = numero%modulo;
            this->modulo = modulo;
        }

        Numeromod operator+(Numeromod otro_numeromod) {
            int suma = numero + otro_numeromod.numero;
            return Numeromod(suma, modulo);
        }

        Numeromod operator+(int otro_numero) {
            int suma = numero + otro_numero;
            return Numeromod(suma, modulo);
        }

        friend ostream& operator<<(ostream& texto, Numeromod mi_numeromod) {
            texto << mi_numeromod.numero;
            return texto;
        }

};

#endif