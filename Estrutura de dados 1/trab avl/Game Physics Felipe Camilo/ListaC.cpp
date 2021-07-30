#include "ListaC.h"

ListaC::ListaC()
{
    Head=nullptr;
    N=0;
    IT=nullptr;
}

bool ListaC::Push(Objeto *Dat)
{
    Node<Objeto>* Aux=Node<Objeto>::montaNode(Dat);
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

bool ListaC::Remove(int j)
{
    if (!Head)
        return false;

    Node<Objeto>* aux= Head;

    while (aux->Next != Head and aux->D.j < j)
        aux=aux->Next;

    if (aux->D.j != j)
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
    Node<Objeto>::desmontaNode(aux);
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

Node<Objeto> *ListaC::getIT()
{
    return IT;
}

int ListaC::Size()
{
    return N;
}

void ListaC::print()
{
    if (Head->D.hp>0)
    {
        std::cout<<"Jogador "<<Head->D.j<<": ("<<Head->D.x<<","<<Head->D.y<<") HP: "<<Head->D.hp<<"\n";
    }
    ResetIT();
    NextIT();
    while (IT!=Head)
    {//imprime cada jogador
        if (IT->D.hp<=0)
        {
            std::cout<<"Jogador "<<IT->D.j<<": MORTO"<<"\n";
        }
        else
        {
            std::cout<<"Jogador "<<IT->D.j<<": ("<<IT->D.x<<","<<IT->D.y<<") HP: "<<IT->D.hp<<"\n";
        }
        NextIT();
    }
}
