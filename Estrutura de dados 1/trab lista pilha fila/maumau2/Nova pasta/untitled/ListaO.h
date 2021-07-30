#ifndef LISTAO_H
#define LISTAO_H
#include <Node.h>
#include <Carta.h>

//Cartas
class ListaO
{
private:
    Node<Carta>* Head;
    int N;
    int valorDeck;
public:
    ListaO();
    bool Push(Carta* Dat);
    bool Remove(Carta* k, Carta* Dat);
    bool Search(Carta k, Carta* Dat);
    int getValorDeck();
    bool IsEmpty();
    int Size();
    void Clear();
};

#endif // LISTAO_H
