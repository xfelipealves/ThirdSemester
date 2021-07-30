#include "Racional.h"


void NumBrabo::Racional::reduzRacional()
{
    if (numerador%denominador==0)
    {
        numerador=numerador/denominador;
        denominador=1;
    }
    if (numerador>1)
    {
        int x=mdc(numerador,denominador);
        numerador=numerador/x;
        denominador=denominador/x;
    }
}

int NumBrabo::Racional::mdc(int n1, int n2)
{
    if (!(n1>=n2))
    {
        int x;
        x=n1;
        n1=n2;
        n2=x;
    }
    if (n1%n2==0)
        return n2;
    mdc(n2,n1%n2);
}

int NumBrabo::Racional::mmc(int n1, int n2)
{
    return (n1*n2)/mdc(n1,n2);
}

NumBrabo::Racional::Racional()
{
    numerador=0;
    denominador=1;
}

NumBrabo::Racional::Racional(int a, int b)
{
    setNumerador(a);
    setDenominador(b);
    reduzRacional();
}

void NumBrabo::Racional::setNumerador(int a)
{
    numerador=a;
}

void NumBrabo::Racional::setDenominador(int b)
{
    if (b==0)
    {
        throw "nao pode ser 0";
    }
    denominador=b;
}

int NumBrabo::Racional::getNumerador() const
{
    return numerador;
}

int NumBrabo::Racional::getDenominador() const
{
    return denominador;
}

QString NumBrabo::Racional::obterRacional() const
{
    return QString::number(numerador)+'/'+QString::number(denominador);
}

NumBrabo::Racional NumBrabo::Racional::operator +(NumBrabo::Racional &numero)
{
    int den=mmc(denominador,numero.denominador);
    int num=den/denominador*numerador+den/numero.denominador*numero.numerador;
    Racional  x(num,den);
    return x;
}

NumBrabo::Racional NumBrabo::Racional::operator -(NumBrabo::Racional &numero)
{
    int den=mmc(denominador,numero.denominador);
    int num=den/denominador*numerador-den/numero.denominador*numero.numerador;
    Racional  x(num,den);
    return x;
}

NumBrabo::Racional NumBrabo::Racional::operator *(NumBrabo::Racional &numero)
{
    Racional x(numerador*numero.numerador, denominador*numero.denominador);
    return x;
}

NumBrabo::Racional NumBrabo::Racional::operator /(NumBrabo::Racional &numero)
{
    Racional x(numerador*numero.denominador,denominador*numero.numerador);
    return x;
}

bool NumBrabo::Racional::operator ==(NumBrabo::Racional &numero)
{
    if (obterRacional()==numero.obterRacional())
        return true;
    return false;
}
