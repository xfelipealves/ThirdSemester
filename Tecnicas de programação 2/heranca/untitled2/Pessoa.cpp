#include "Pessoa.h"
using namespace Quest1;
Pessoa::Pessoa()
{
    nome="Nome nao informado";
    endereco="Endereco nao informado";
    telefone=0;
    email="Email nao informado";
}

QString Pessoa::getNome()
{
    return nome;
}

QString Pessoa::getEndereco()
{
    return endereco;
}

QString Pessoa::getEmail()
{
    return email;
}

long Pessoa::getTelefone()
{
    return telefone;
}

void Pessoa::setNome(QString *nome)
{
    this->nome=*nome;
}

void Pessoa::setEndereco(QString *endereco)
{
    this->endereco=*endereco;
}

void Pessoa::setEmail(QString *email)
{
    this->email=*email;
}

void Pessoa::setTelefone(long *telefone)
{
    this->telefone=*telefone;
}

QString Pessoa::print()
{
    return QString ("Nome: "+ nome +"\nEndereco: "+ endereco + "\nEmail: " +email + "\nTelefone: " + QString::number(telefone));
}
