#include "Pilha.h"

Pilha::Pilha()
{
    Head=nullptr;
    N=0;
}

bool Pilha::Push(Carta *Dat)
{
    Node<Carta>* Aux=Node<Carta>::MontaNode(Dat);
    if (!Aux)
        return false;
    Aux->Next=Head;
    Head=Aux;
    N++;
    return true;
}

bool Pilha::Pop(Carta *Dat)
{
    if (!Head)
        return false;
    Node<Carta>* Aux=Head;
    Head=Head->Next;
    Carta b=Node<Carta>::DesmontaNode(Aux);
//    *Dat=Node<Carta>::DesmontaNode(Aux);
    *Dat=b;
    N--;
    return true;
}

bool Pilha::Pop()
{
    if (!Head)
        return false;
    Node<Carta>* Aux=Head;
    Head=Head->Next;
    Node<Carta>::DesmontaNode(Aux);
    N--;
    return true;
}

void Pilha::trocaPoder()
{
    Head->D.poder= !Head->D.poder;
}

Carta Pilha::Top()
{
    return Head->D;
}

bool Pilha::IsEmpty()
{
    return !N;
}

int Pilha::size()
{
    return N;
}

void Pilha::clear()
{
    while(size())
        Pop();
}
