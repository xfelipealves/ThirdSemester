#ifndef RACIONAL_H
#define RACIONAL_H
#include <QString>

namespace NumBrabo {

    class Racional
    {
    private:
        int numerador;
        int denominador;
        void reduzRacional();
        int mdc(int n1, int n2);
        int mmc(int n1, int n2);
    public:
        Racional();
        Racional(int a, int b);
        void setNumerador (int a);
        void setDenominador (int b);
        int getNumerador() const;
        int getDenominador() const;
        QString obterRacional() const;
        Racional operator +(Racional &numero);
        Racional operator -(Racional &numero);
        Racional operator *(Racional &numero);
        Racional operator /(Racional &numero);
        bool operator ==(Racional &numero);
    };

}


#endif // RACIONAL_H
