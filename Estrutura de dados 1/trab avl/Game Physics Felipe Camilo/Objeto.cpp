#include "Objeto.h"

Objeto::Objeto()
{
    x=y=-1;
    id=false;
}

Objeto::Objeto(int x, int y)
{
    this->x=x;
    this->y=y;
    id=false;//pedra
}

Objeto::Objeto(int x, int y, int hp, int dano, int j)
{
    this->x=x;
    this->y=y;
    id=true;//player
    this->hp=hp;
    this->dano=dano;
    this->j=j;
}

bool Objeto::operator <(Objeto aux)
{
    if (x>aux.x)//this > aux
        return false;
    if (x<aux.x)//this < aux
        return true;
    //x iguais
    if (y<aux.y)//this < aux
        return true;
    return false;
}

