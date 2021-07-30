#include "Carta.h"

Carta::Carta()
{
    Naipe='Z';
    poder=false;
}

Carta::Carta(char valor, char naipe)
{
    Valor=valor;
    Naipe=naipe;
    poder=false;
    if (Valor=='A' or Valor=='G' or Valor=='I' or Valor=='L')
        poder=true;
}

bool Carta::operator !=(Carta &a)
{
    if (Naipe!=a.Naipe and Valor!=a.Valor)
        return true;
    return false;
}

bool Carta::operator >(Carta &a)
{
    if (Valor>a.Valor)
        return Naipe<=a.Naipe;
    return Valor>a.Valor;
}

int Carta::getValor()
{
    return (int)Valor;
}
