#include "Pessoa.h"

ag::Pessoa::Pessoa()
{
    nome=endereco=email="";
    Next=nullptr;
    Prev=nullptr;
}

ag::Pessoa::Pessoa(QString nome, QString endereco, QString email)
{
    setNome(nome);
    setEndereco(endereco);
    setEmail(email);
}

void ag::Pessoa::setNome(QString nome)
{
    this->nome=nome;
}

void ag::Pessoa::setEndereco(QString endereco)
{
    this->endereco=endereco;
}

void ag::Pessoa::setEmail(QString email)
{
    this->email=email;
}

QString ag::Pessoa::getNome()
{
    return nome;
}

QString ag::Pessoa::getEndereco()
{
    return endereco;
}

QString ag::Pessoa::getEmail()
{
    return email;
}

QString ag::Pessoa::print()
{
    return QString ("Nome: "+ nome +"\nEndereco: "+ endereco + "\nEmail: " +email);
}

void ag::Pessoa::setNext(ag::Pessoa *Next)
{
    this->Next=Next;
}

ag::Pessoa *ag::Pessoa::getNext()
{
    return Next;
}

void ag::Pessoa::setPrev(ag::Pessoa *Prev)
{
    this->Prev=Prev;
}

ag::Pessoa *ag::Pessoa::getPrev()
{
    return Prev;
}
