#include "Cone.h"

namespace TP2 {
    Cone::Cone():Cilindro()
    {
    }

    Cone::Cone(float raio, float altura): Cilindro(raio, altura)
    {
    }

    float Cone::calcularGeratriz() const{
        return sqrt(pow(getAltura(),2) + pow(getRaio(),2));
    }

    float Cone::calcularAreaLateral() const{
        return M_PI*getRaio()*calcularGeratriz();
    }

    float Cone::calcularAreaTotal() const{
        return M_PI*getRaio()*(calcularGeratriz()+getRaio());
    }

    float Cone::calcularVolume() const{
        return (M_PI*pow(getRaio(),2)*getAltura())/3;
    }

    QString Cone::getTipoDaFigura() const{
        return "Cone";
    }

}
