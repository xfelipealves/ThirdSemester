#include "Caminhao.h"

trab::Caminhao::Caminhao() : Veiculo(), Motor()
{
    toneladas=alturaMaxima=comprimento=0;
}

trab::Caminhao::Caminhao(double peso, double velocidadeMaxima, double preco, int numCilindros, int potencia, double toneladas, double alturaMaxima, double comprimento)
    : Veiculo(peso,velocidadeMaxima,preco), Motor(numCilindros,potencia)
{
    setToneladas(toneladas);
    setAlturaMaxima(alturaMaxima);
    setComprimento(comprimento);
}

double trab::Caminhao::getToneladas()
{
    return toneladas;
}

double trab::Caminhao::getAlturaMaxima()
{
    return alturaMaxima;
}

double trab::Caminhao::getComprimento()
{
    return comprimento;
}

void trab::Caminhao::setToneladas(double toneladas)
{//validar
    if (toneladas<0)
        throw (QString ("Negativo"));
    this->toneladas=toneladas;
}

void trab::Caminhao::setAlturaMaxima(double alturaMaxima)
{//validar
    if (alturaMaxima<0)
        throw (QString ("Negativo"));
    this->alturaMaxima=alturaMaxima;
}

void trab::Caminhao::setComprimento(double comprimento)
{//validar
    if (comprimento<0)
        throw (QString ("Negativo"));
    this->comprimento=comprimento;
}

QString trab::Caminhao::print()
{
    return QString(Veiculo::print() + Motor::print() + "\nToneladas: " + QString::number(toneladas) + "\nAltura Máxima: " + QString::number(alturaMaxima) + "\nComprimento: " + QString::number(comprimento));
}
