#include "Motor.h"

trab::Motor::Motor()
{
    numCilindros=potencia=0;
}

trab::Motor::Motor(int numCilindros, int potencia)
{
    setNumCilindros(numCilindros);
    setPotencia(potencia);
}

int trab::Motor::getNumCilindros()
{
    return numCilindros;
}

int trab::Motor::getPotencia()
{
    return potencia;
}

void trab::Motor::setNumCilindros(int numCilindros)
{//validar
    if (numCilindros<0)
        throw (QString ("Negativo"));
    this->numCilindros=numCilindros;
}

void trab::Motor::setPotencia(int potencia)
{//validar
    if (potencia<0)
        throw (QString ("Negativo"));
    this->potencia=potencia;
}

QString trab::Motor::print()
{
    return QString("\nCilindros: " + QString::number(numCilindros) + "\nPotência: " + QString::number(potencia));
}
