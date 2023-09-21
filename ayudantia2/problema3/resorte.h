#ifndef RESORTE_H
#define RESORTE_H
// ifndef significa if not define, es para cuando tengan que usar su clase en archivos que se llaman entre ellos, y no definan varias veces su clase
// por lo que, si no está previamente definida, definela
// siempre se pone el nombre del archivo en mayúsculas, un guión bajo representando el punto, y la extensión que tenga, para este caso una h

// cre la clase Resorte, por convención siempre empiezan con mayúscula
class Resorte {
    // en privado almaceno las variables básicas de mi clase, las que la definen
    private:
        double m;
        double x;
        double v;
        double k;
        double dt;
    // en público defino todo lo demás
    public:
        // defino el contructor por defecto
        Resorte() {};
        // defino el constructor que me crea una fracción a partir de 5 números
        Resorte(double m, double x, double v, double k, double dt) {
            // "this->" en c++ es análogo a "self." en python
            // aqui lo uso porque la variable de la clase tiene el mismo nombre que la variable de entrada
            this->m = m;
            this->x = x;
            this->v = v;
            this->k = k;
            this->dt = dt;
        }

        // creo una función que actualice los parametros de la simulación un dt cada vez que es llamada
        void step() {
            double a = -k*x/m;
            v += a*dt;
            x += v*dt;
        }

        // creo una función de mega-ultra-hacker que rompa la seguridad de c++ y me entregue una variable privada
        double get_x() {
            return x;
        }
};

// esto hay que ponerlo para cerrar el #ifndef del inicio
#endif