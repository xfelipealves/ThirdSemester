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
    bool x;
    while(P)
    {
        if (P->getNext())
        {
            Aux=P->getNext();
        }
        else
        {
            Aux=nullptr;
        }
        while(Aux)
        {
            x=false;
            k=nullptr;
            a=typeid (*P).name();//o atual
            b=typeid (*Aux).name();//o prox
            int c=a.find("PessoaJuridica");
            int d=b.find("PessoaFisica");
            if (c==6 and d==6)
            {
                x=true;
                k = P->getNext();
                P->setNext(Aux->getNext());
                Aux->setNext(k);

                k = P->getPrev();
                P->setPrev(Aux->getPrev());
                Aux->setPrev(k);

                if(P->getNext() == P){
                    P->setNext(Aux);
                    Aux->setPrev(P);
                }
                if(Aux->getNext() == Aux){
                    Aux->setNext(P);
                    P->setPrev(Aux);
                }

                if(P->getNext())
                    P->getNext()->setPrev(P);
                if(P->getPrev())
                    P->getPrev()->setNext(P);
                if(Aux->getNext())
                    Aux->getNext()->setPrev(Aux);
                if(Aux->getPrev())
                    Aux->getPrev()->setNext(Aux);

                if(P==Head)
                {
                    Head =Aux;
                }
                else{
                    if(Aux==Head)
                        Head = P;
                }
            }
            else
            {
                c=a.find("PessoaFisica");
                d=b.find("PessoaFisica");
                if ( c==6 and d==6  )
                {//PF e PF
                    if(P->getCPFNJ()>Aux->getCPFNJ())
                    {//so troca
                        x=true;
                        k = P->getNext();
                        P->setNext(Aux->getNext());
                        Aux->setNext(k);

                        k = P->getPrev();
                        P->setPrev(Aux->getPrev());
                        Aux->setPrev(k);

                        if(P->getNext() == P){
                            P->setNext(Aux);
                            Aux->setPrev(P);
                        }
                        if(Aux->getNext() == Aux){
                            Aux->setNext(P);
                            P->setPrev(Aux);
                        }

                        if(P->getNext())
                            P->getNext()->setPrev(P);
                        if(P->getPrev())
                            P->getPrev()->setNext(P);
                        if(Aux->getNext())
                            Aux->getNext()->setPrev(Aux);
                        if(Aux->getPrev())
                            Aux->getPrev()->setNext(Aux);

                        if(P==Head)
                        {
                            Head =Aux;
                        }
                        else{
                            if(Aux==Head)
                                Head = P;
                        }
                    }

                }
                else {
                    c=a.find("PessoaJuridica");
                    d=b.find("PessoaJuridica");
                    if ( c==6 and d==6 )
                    {//PJ e PJ
                        if (P->getCPFNJ()>Aux->getCPFNJ())
                        {//so troca
                            x=true;
                            k = P->getNext();
                            P->setNext(Aux->getNext());
                            Aux->setNext(k);

                            k = P->getPrev();
                            P->setPrev(Aux->getPrev());
                            Aux->setPrev(k);

                            if(P->getNext() == P){
                                P->setNext(Aux);
                                Aux->setPrev(P);
                            }
                            if(Aux->getNext() == Aux){
                                Aux->setNext(P);
                                P->setPrev(Aux);
                            }

                            if(P->getNext())
                                P->getNext()->setPrev(P);
                            if(P->getPrev())
                                P->getPrev()->setNext(P);
                            if(Aux->getNext())
                                Aux->getNext()->setPrev(Aux);
                            if(Aux->getPrev())
                                Aux->getPrev()->setNext(Aux);

                            if(P==Head)
                            {
                                Head =Aux;
                            }
                            else{
                                if(Aux==Head)
                                    Head = P;
                            }
                        }
                    }
                }
            }
            if (x)
            {
                Aux=P->getNext();
            }
            else
            {
                Aux=Aux->getNext();
            }
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
