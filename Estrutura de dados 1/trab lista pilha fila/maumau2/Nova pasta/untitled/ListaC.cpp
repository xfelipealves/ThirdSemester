#include "ListaC.h"

ListaC::ListaC()
{
    Head=nullptr;
    N=0;
    IT=nullptr;
}

bool ListaC::Push(Jogador *Dat)
{
    Node<Jogador>* Aux=Node<Jogador>::MontaNode(Dat);
    if (!Aux)
        return false;
    if (!Head)
    {//vazio
        Head = IT =  Aux->Next = Aux->Prev = Aux;
    }
    else
    {//ultimo apontar pro aux
        Head->Prev->Next=Aux;
        //aux apontar pro ultimo
        Aux->Prev=Head->Prev;
        //Next do aux apontar pro head
        Aux->Next=Head;
        //prev do head apontar pro aux
        Head->Prev=Aux;
    }
    N++;
    return true;
}

bool ListaC::Remove(int id)
{
    if (!Head)
        return false;

    Node<Jogador>* aux= Head;

    while (aux->Next != Head and aux->D.getId() < id)
        aux=aux->Next;

    if (aux->D.getId() != id)
        return false;

    if (aux->Next==aux)
    {
        Head=nullptr;
    }
    else
    {
        if (aux==Head)
        {
            Head=Head->Next;
        }
    }

    aux->Prev->Next = aux->Next;
    aux->Next->Prev = aux->Prev;

    N--;
    Node<Jogador>::DesmontaNode(aux);
    return true;
}

void ListaC::NextIT()
{
    if (!IT) return;
    IT=IT->Next;
}

void ListaC::PrevIT()
{
    if (!IT) return;
    IT=IT->Prev;
}

void ListaC::ResetIT()
{
    IT=Head;
}

Node<Jogador> *ListaC::getIT()
{
    return IT;
}

int ListaC::Size()
{
    return N;
}
