#ifndef CARTA_H
#define CARTA_H


class Carta
{
public:
    Carta();
    Carta(char valor, char naipe);
    char Valor,Naipe;
    bool poder;
    bool operator != (Carta& a);
    bool operator > (Carta& a);
    int getValor();
};

#endif // CARTA_H
