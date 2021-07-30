#include "Veiculo.h"

trab::Veiculo::Veiculo()
{
    peso=velocidadeMaxima=preco=0;
}

trab::Veiculo::Veiculo(double peso, double velocidadeMaxima, double preco)
{
    setPeso(peso);
    setVelocidadeMaxima(velocidadeMaxima);
    setPreco(preco);
}

double trab::Veiculo::getPeso()
{
    return peso;
}

double trab::Veiculo::getVelocidadeMaxima()
{
    return velocidadeMaxima;
}

double trab::Veiculo::getPreco()
{
    return preco;
}

void trab::Veiculo::setPeso(double peso)
{
    if (peso<0)
        throw (QString ("Negativo"));
    this->peso=peso;
}

void trab::Veiculo::setVelocidadeMaxima(double velocidadeMaxima)
{
    if (velocidadeMaxima<0)
        throw (QString ("Negativo"));
    this->velocidadeMaxima=velocidadeMaxima;
}

void trab::Veiculo::setPreco(double preco)
{
    if (preco<0)
        throw (QString ("Negativo"));
    this->preco=preco;
}

QString trab::Veiculo::print()
{
    return QString("Peso: " + QString::number(peso) + "\nVelocidade Máxima: " + QString::number(velocidadeMaxima) + "\nPreço: " + QString::number(preco));
}
