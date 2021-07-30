#ifndef JOGADOR_H
#define JOGADOR_H

#include <ListaO.h>
#include <Carta.h>
class Jogador
{
private:
    int id;
    ListaO deck;
public:
    Jogador();
    Jogador(int id);
    int getId();
    bool Venceu();
    int getValorDeck();
    bool Compra(Carta* C);//push
    bool Descarta(Carta* CLixo, Carta* Dat);
};

#endif // JOGADOR_H
