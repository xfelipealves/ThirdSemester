#include "CarroPasseio.h"

trab::CarroPasseio::CarroPasseio() : Veiculo(), Motor()
{
    cor=modelo="";
}

trab::CarroPasseio::CarroPasseio(double peso, double velocidadeMaxima, double preco, int numCilindros, int potencia, QString cor, QString modelo)
    : Veiculo(peso,velocidadeMaxima,preco), Motor(numCilindros,potencia)
{
    setCor(cor);
    setModelo(modelo);
}

QString trab::CarroPasseio::getCor()
{
    return cor;
}

QString trab::CarroPasseio::getModelo()
{
    return modelo;
}

void trab::CarroPasseio::setCor(QString cor)
{
    this->cor=cor;
}

void trab::CarroPasseio::setModelo(QString modelo)
{
    this->modelo=modelo;
}

QString trab::CarroPasseio::print()
{
    return QString(Veiculo::print() + Motor::print() + "\nModelo: " + modelo + "\nCor: " + cor);
}
