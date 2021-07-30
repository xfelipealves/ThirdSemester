#ifndef OBJETO_H
#define OBJETO_H


class Objeto
{
public:
    int x,y;//posicao
    bool id;//1 pra player, 0 pra pedra
    int j;
    int hp,dano;
    Objeto();
    Objeto(int x, int y);
    Objeto(int x, int y, int hp, int dano, int j);
    bool operator < (Objeto aux);
};

#endif // OBJETO_H
