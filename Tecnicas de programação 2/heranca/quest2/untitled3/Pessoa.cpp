#include "Pessoa.h"

Quest2::Pessoa::Pessoa()
{
    nome=endereco=email="";
    telefone=rendaBruta=0;
}

Quest2::Pessoa::Pessoa(QString nome, QString endereco, long telefone, QString email, double rendaBruta)
{
    this->nome=nome;
    this->endereco=endereco;
    this->email=email;
    setTelefone(telefone);
    setRendaBruta(rendaBruta);
}

void Quest2::Pessoa::setNome(QString nome)
{
    this->nome=nome;
}

void Quest2::Pessoa::setEndereco(QString endereco)
{
    this->endereco=endereco;
}

void Quest2::Pessoa::setTelefone(long telefone)
{
    if (telefone<0)
        throw QString ("ERRO");
    this->telefone=telefone;
}

void Quest2::Pessoa::setEmail(QString email)
{
    this->email=email;
}

void Quest2::Pessoa::setRendaBruta(double rendaBruta)
{
    if (rendaBruta<0)
        throw QString ("ERRO");
    this->rendaBruta=rendaBruta;
}

QString Quest2::Pessoa::getNome()
{
    return nome;
}

QString Quest2::Pessoa::getEndereco()
{
    return endereco;
}

long Quest2::Pessoa::getTelefone()
{
    return telefone;
}

QString Quest2::Pessoa::getEmail()
{
    return email;
}

double Quest2::Pessoa::getRendaBruta()
{
    return rendaBruta;
}

QString Quest2::Pessoa::print()
{
    return QString ("Nome: " + nome + "\nEndereco: " + endereco +
            "\nEmail: " + email + "\nTelefone: " + QString::number(telefone)
            + "\nRendaBruta: " + QString::number(rendaBruta));
}
