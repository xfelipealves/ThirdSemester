#include "PessoaFisica.h"


ag::PessoaFisica::PessoaFisica() : Pessoa()
{
    nascimento=estadoCivil="";
    CPF=-1;
}

ag::PessoaFisica::PessoaFisica(QString nome, QString endereco, QString email, QString nascimento, QString estadoCivil, long long CPF)
 : Pessoa(nome,endereco,email)
{
    setNascimento(nascimento);
    setEstadoCivil(estadoCivil);
    setCPF(CPF);
}

void ag::PessoaFisica::setNascimento(QString nascimento)
{
    this->nascimento=nascimento;
}

void ag::PessoaFisica::setEstadoCivil(QString estadoCivil)
{
    this->estadoCivil=estadoCivil;
}

void ag::PessoaFisica::setCPF(long long CPF)
{
    if (CPF<0)
        throw QString ("CPF Invalido");
    this->CPF=CPF;
}

QString ag::PessoaFisica::getNascimento()
{
    return nascimento;
}

QString ag::PessoaFisica::getEstadoCivil()
{
    return estadoCivil;
}

long long ag::PessoaFisica::getCPFNJ()
{
    return CPF;
}

QString ag::PessoaFisica::print()
{
    return Pessoa::print() + QString ("\nNascimento: "+ nascimento +"\nEstadoCivil: "+ estadoCivil + "\nCPF: " +QString::number(CPF));
}
