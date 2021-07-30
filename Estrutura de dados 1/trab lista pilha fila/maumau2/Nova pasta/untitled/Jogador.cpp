#include "Jogador.h"

Jogador::Jogador()
{

}

Jogador::Jogador(int id)
{
    this->id=id;
}

int Jogador::getId()
{
    return id;
}

bool Jogador::Venceu()
{
    return deck.IsEmpty();
}

int Jogador::getValorDeck()
{
    return deck.getValorDeck();
}

bool Jogador::Compra(Carta *C)
{
    return deck.Push(C);
}

bool Jogador::Descarta(Carta* CLixo, Carta *Dat)
{
    return deck.Remove(CLixo, Dat);
}
