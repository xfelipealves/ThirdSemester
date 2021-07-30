#include "ListaO.h"

ListaO::ListaO()
{
    Head=nullptr;
    N=valorDeck=0;
}

bool ListaO::Push(Carta *Dat)
{
    Node<Carta>* C=Node<Carta>::MontaNode(Dat);
    if (!C)
        return false;

    Node<Carta>**P=&Head;
    while (*P and ((*P)->D) > *Dat)
    {
        P=&((*P)->Next);
    }
    if (!(*P))
    {//ultima posicao
        *P=C;
    }
    else
    {
        //tem coisa la
//        C->Next=(*P)->Next;
        C->Next=(*P);
        *P=C;
    }
    N++;

    int x=Dat->getValor();
    valorDeck=valorDeck + x;

    return true;
}

bool ListaO::Remove(Carta* k, Carta *Dat)
{
    if (!Head)
    {
        return false;
    }
    if (k->Naipe=='Z')
    {//PRIMEIRA RODADA = LIXO VAZIO = K = NULL
        Node<Carta>*Aux=Head;
        Head=Head->Next;
        N--;
        *Dat=Node<Carta>::DesmontaNode(Aux);

        int x=Dat->getValor();
        valorDeck=valorDeck - x;

        return true;
    }
    Node<Carta>**P=&Head;
    while (*P and ((*P)->D) != *k)
    {
        P=&((*P)->Next);
    }
    if (!(*P))
        return false;
    //Achooou
    Node<Carta>*Aux=*P;
    *P=(*P)->Next;
    N--;
    *Dat=Node<Carta>::DesmontaNode(Aux);

    int x=Dat->getValor();
    valorDeck=valorDeck - x;

    return true;
}

bool ListaO::Search(Carta k, Carta *Dat)
{
    Node<Carta>*P=Head;
    while (P and (P->D) != k)
    {
        P=P->Next;
    }
    if (!P)
        return false;
    *Dat=P->D;
    return true;
}

int ListaO::getValorDeck()
{
    return valorDeck;
}


bool ListaO::IsEmpty()
{
    return !N;
}

int ListaO::Size()
{
    return N;
}

void ListaO::Clear()
{
    N=0;
    while (Head)
    {
        Node<Carta>* aux=Head;
        Head=Head->Next;
        Node<Carta>::DesmontaNode(aux);
    }
}
