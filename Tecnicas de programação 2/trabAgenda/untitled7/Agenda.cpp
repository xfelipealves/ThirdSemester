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
    Pessoa* t;
    Pessoa* Aux=Head;
    Pessoa* k;
    std::string a,b;
    while(Aux)
    {
        t=Aux->getNext();
        a=typeid (Aux).name();//o atual
        b=typeid (t).name();//o prox
        while (t)
        {
            k=nullptr;
            if (a.find("PessoaJuridica") and b.find("PessoaFisica"))
            {
                k=t;
                t=Aux;
                Aux=t;
            }
            else
            {
                if ( a.find("PessoaFisica") and b.find("PessoaFisica")  )
                {//PF e PF
                    if(Aux->getCPFNJ()>t->getCPFNJ())
                    {//so troca
                        k=t;
                        t=Aux;
                        Aux=t;
                    }

                }
                else {
                    if ( a.find("PessoaJuridica") and b.find("PessoaJuridica") )
                    {//PJ e PJ
                        if (Aux->getCPFNJ()>t->getCPFNJ())
                        {//so troca
                            k=t;
                            t=Aux;
                            Aux=t;
                        }
                    }
                }
            }
            t=t->getNext();
        }
        Aux=Aux->getNext();
    }
}

bool ag::Agenda::adiciona(Pessoa *Busca)
{
    if (!Head)
    {//agenda vazia
        (Head)=Busca;
        Head->setNext(nullptr);
        N++;
        return true;
    }
    Busca->setNext(Head);
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
    while (P && P->getNome()!=nome)
    {
        P=P->getNext();
    }
    if (!P)
        return false;
    //encontrou
    P=P->getNext();
    return true;
}

QString ag::Agenda::buscarContato(QString nome)
{
    if(!Head)
    {
        QString x="Agenda Vazia";
        throw x;
    }
    Pessoa*P=Head;
    while (P)
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
    while (P)
    {
        a = a +  P->print() + "\n" + "\n";
        P=P->getNext();
    }
    return a;
}
