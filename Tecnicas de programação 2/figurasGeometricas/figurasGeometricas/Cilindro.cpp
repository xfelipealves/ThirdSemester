#include "Cilindro.h"
namespace TP2 {

    Cilindro::Cilindro():FiguraGeometrica(), altura(1)
    {
    }

    Cilindro::Cilindro(float raio, float altura):FiguraGeometrica(raio){
        setAltura(altura);
    }

    void Cilindro::setAltura(float altura){
        if(altura <= 0)
            throw QString ("Altura inválida.");
        this->altura = altura;
    }

    float Cilindro::getAltura() const{
        return altura;
    }

    float Cilindro::calcularAreaLateral()const{
        return (2*M_PI*getRaio()*altura);
    }

    float Cilindro::calcularAreaTotal()const{
        float AL = calcularAreaLateral();
        float AT = (2*M_PI*pow(getRaio(),2))+AL;
        return AT;
    }

    float Cilindro::calcularVolume()const{
        return (M_PI*pow(getRaio(),2)*altura);
    }

    QString Cilindro::getTipoDaFigura() const{
        return "Cilindro";
    }

}

