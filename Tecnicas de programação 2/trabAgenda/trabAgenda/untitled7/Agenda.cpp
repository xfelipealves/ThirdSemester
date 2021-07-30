#include "Agenda.h"

ag::Agenda::Agenda()
{
    Head=nullptr;
    N=0;
}

void ag::Agenda::ordena()
{
    if (!Head)
    {
        QString x="Agenda Vazia";
        throw x;
    }
    Pessoa* Aux;
    Pessoa* P=Head;
    Pessoa* k;
    std::string a,b;
    for(int i=0;i<N-1;i++)
    {
        Aux=P->getNext();
        a=typeid (P).name();//o atual
        b=typeid (Aux).name();//o prox
        for(int j=i+1;j<N;j++)
        {
            k=nullptr;
            if (a.find("PessoaJuridica") and b.find("PessoaFisica"))
            {
                if (P==Head)
                {
                    Head=Aux;
                }

                if (Aux->getNext() and Aux->getNext()!=P)
                {//antes tem que vir o troca prev do next
                    ( Aux->getNext() )->setPrev(P);
                }

                if (P->getNext() and P->getNext()!=Aux)
                {//antes tem que vir o troca prev do next
                    ( P->getNext() )->setPrev(Aux);
                }

                k=nullptr;
                //Nextz
                if (P->getNext()!=Aux)
                {//Aux->Next recebe o P -> Next e deixa o seu next salvo em k
                    k=Aux->getNext();
                    Aux->setNext(P->getNext());
                }
                else
                {//P->Next == Aux
                    k=Aux->getNext();
                    Aux->setNext(P);
                }

                if  (Aux->getNext()!=P)
                {//P->Next recebe o Aux -> Next e deixa o seu next salvo em k
                    P->setNext(k);
                }
                else
                {//
                    P->setNext(Aux);
                }

                if (Aux->getPrev() and Aux->getPrev()!=P)
                {//antes tem que vir o troca prev do next
                    ( Aux->getPrev() )->setNext(P);
                }

                if (P->getPrev() and P->getPrev()!=Aux)
                {//antes tem que vir o troca prev do next
                    ( P->getPrev() )->setNext(Aux);
                }

                k=nullptr;
                //Prevz
                if (P->getPrev()!=Aux)
                {//Aux->Prev recebe o P -> Prev e deixa o seu Prev salvo em k
                    k=Aux->getPrev();
                    Aux->setPrev(P->getPrev());
                }
                else
                {//P->Prev == Aux
                    k=Aux->getPrev();
                    Aux->setPrev(P);
                }

                if(Aux->getPrev()!=P)
                {
                    P->setPrev(k);
                }
                else
                {
                    P->setPrev(Aux);
                }
            }
            else
            {
                if ( a.find("PessoaFisica") and b.find("PessoaFisica")  )
                {//PF e PF
                    if(P->getCPFNJ()>Aux->getCPFNJ())
                    {//so troca
                        if (P==Head)
                        {
                            Head=Aux;
                        }
                        if (Aux->getNext() and Aux->getNext()!=P)
                        {//antes tem que vir o troca prev do next
                            ( Aux->getNext() )->setPrev(P);
                        }

                        if (P->getNext() and P->getNext()!=Aux)
                        {//antes tem que vir o troca prev do next
                            ( P->getNext() )->setPrev(Aux);
                        }

                        k=nullptr;
                        //Nextz
                        if (P->getNext()!=Aux)
                        {//Aux->Next recebe o P -> Next e deixa o seu next salvo em k
                            k=Aux->getNext();
                            Aux->setNext(P->getNext());
                        }
                        else
                        {//P->Next == Aux
                            k=Aux->getNext();
                            Aux->setNext(P);
                        }

                        if  (Aux->getNext()!=P)
                        {//P->Next recebe o Aux -> Next e deixa o seu next salvo em k
                            P->setNext(k);
                        }
                        else
                        {//
                            P->setNext(Aux);
                        }

                        if (Aux->getPrev() and Aux->getPrev()!=P)
                        {//antes tem que vir o troca prev do next
                            ( Aux->getPrev() )->setNext(P);
                        }

                        if (P->getPrev() and P->getPrev()!=Aux)
                        {//antes tem que vir o troca prev do next
                            ( P->getPrev() )->setNext(Aux);
                        }

                        k=nullptr;
                        //Prevz
                        if (P->getPrev()!=Aux)
                        {//Aux->Prev recebe o P -> Prev e deixa o seu Prev salvo em k
                            k=Aux->getPrev();
                            Aux->setPrev(P->getPrev());
                        }
                        else
                        {//P->Prev == Aux
                            k=Aux->getPrev();
                            Aux->setPrev(P);
                        }

                        if(Aux->getPrev()!=P)
                        {
                            P->setPrev(k);
                        }
                        else
                        {
                            P->setPrev(Aux);
                        }
                    }

                }
                else {
                    if ( a.find("PessoaJuridica") and b.find("PessoaJuridica") )
                    {//PJ e PJ
                        if (P->getCPFNJ()>Aux->getCPFNJ())
                        {//so troca
                            if (P==Head)
                            {
                                Head=Aux;
                            }
                            if (Aux->getNext() and Aux->getNext()!=P)
                            {//antes tem que vir o troca prev do next
                                ( Aux->getNext() )->setPrev(P);
                            }

                            if (P->getNext() and P->getNext()!=Aux)
                            {//antes tem que vir o troca prev do next
                                ( P->getNext() )->setPrev(Aux);
                            }

                            k=nullptr;
                            //Nextz
                            if (P->getNext()!=Aux)
                            {//Aux->Next recebe o P -> Next e deixa o seu next salvo em k
                                k=Aux->getNext();
                                Aux->setNext(P->getNext());
                            }
                            else
                            {//P->Next == Aux
                                k=Aux->getNext();
                                Aux->setNext(P);
                            }

                            if  (Aux->getNext()!=P)
                            {//P->Next recebe o Aux -> Next e deixa o seu next salvo em k
                                P->setNext(k);
                            }
                            else
                            {//
                                P->setNext(Aux);
                            }

                            if (Aux->getPrev() and Aux->getPrev()!=P)
                            {//antes tem que vir o troca prev do next
                                ( Aux->getPrev() )->setNext(P);
                            }

                            if (P->getPrev() and P->getPrev()!=Aux)
                            {//antes tem que vir o troca prev do next
                                ( P->getPrev() )->setNext(Aux);
                            }

                            k=nullptr;
                            //Prevz
                            if (P->getPrev()!=Aux)
                            {//Aux->Prev recebe o P -> Prev e deixa o seu Prev salvo em k
                                k=Aux->getPrev();
                                Aux->setPrev(P->getPrev());
                            }
                            else
                            {//P->Prev == Aux
                                k=Aux->getPrev();
                                Aux->setPrev(P);
                            }

                            if(Aux->getPrev()!=P)
                            {
                                P->setPrev(k);
                            }
                            else
                            {
                                P->setPrev(Aux);
                            }
                        }
                    }
                }
            }
            Aux=Aux->getNext();
        }
        P=P->getNext();
    }
}

bool ag::Agenda::adiciona(Pessoa *Busca)
{
    if (!Head)
    {//agenda vazia
        (Head)=Busca;
        Head->setNext(nullptr);
        Head->setPrev(nullptr);
        N++;
        return true;
    }
    Busca->setNext(Head);
    Busca->setPrev(nullptr);
    if (Head)
    {
        (Head)->setPrev(Busca);
    }
    Head=Busca;
    N++;
    return true;
}

bool ag::Agenda::remove(QString nome)
{
    if(!Head)
    {
        QString x="Agenda Vazia";
        throw x;
    }
    Pessoa*P=Head;
    while (P!=nullptr)
    {
        if (P->getNome()==nome)
        {
            if (P->getPrev())
            {//tem anterior
                (P->getPrev())->setNext(P->getNext());
            }
            else
            {//ele é o primeiro
                (Head)=P->getNext();
            }
            if (P->getNext())
            {//tem proximo
                (P->getNext())->setPrev(P->getPrev());
            }
            N--;
            return true;
        }
        P=P->getNext();
    }
    return false;
}

QString ag::Agenda::buscarContato(QString nome)
{
    if(!Head)
    {
        QString x="Agenda Vazia";
        throw x;
    }
    Pessoa*P=Head;
    while (P!=nullptr)
    {
        if (P->getNome()==nome)
            return P->print();
        P=P->getNext();
    }
    QString x="Contato nao existente";
    return x;
}

QString ag::Agenda::printTodos()
{
    if(!Head)
    {
        QString x="Agenda Vazia";
        throw x;
    }
    Pessoa*P=Head;
    QString a="";
    while (P!=nullptr)
    {
        a = a +  P->print() + "\n" + "\n";
        P=P->getNext();
    }
    return a;
}
