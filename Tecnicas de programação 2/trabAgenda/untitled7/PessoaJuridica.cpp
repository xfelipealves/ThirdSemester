#include "PessoaJuridica.h"


ag::PessoaJuridica::PessoaJuridica() : Pessoa()
{
    inscrEstadual=CNPJ=-1;
    razaoSocial="";
}

ag::PessoaJuridica::PessoaJuridica(QString nome, QString endereco, QString email, int inscrEstadual, QString razaoSocial, long long CNPJ)
    : Pessoa(nome,endereco,email)
{
    setInscr(inscrEstadual);
    setRazaoSocial(razaoSocial);
    setCNPJ(CNPJ);
}

void ag::PessoaJuridica::setInscr(int inscrEstadual)
{
    if (inscrEstadual<0)
        throw QString ("Inscrição invalida");
    this->inscrEstadual=inscrEstadual;
}

void ag::PessoaJuridica::setRazaoSocial(QString razaoSocial)
{
    this->razaoSocial=razaoSocial;
}

void ag::PessoaJuridica::setCNPJ(long long CNPJ)
{
    if (CNPJ<0)
        throw QString ("CNPJ invalido");
    this->CNPJ=CNPJ;
}

int ag::PessoaJuridica::getIsncrEstadual()
{
    return inscrEstadual;
}

QString ag::PessoaJuridica::getRazaoSocial()
{
    return razaoSocial;
}

long long ag::PessoaJuridica::getCPFNJ()
{
    return CNPJ;
}

QString ag::PessoaJuridica::print()
{
    return Pessoa::print() + QString ("\nInscr Estadual: "+ QString::number(inscrEstadual)
                                      +"\nRazao Social: "+ razaoSocial + "\nCNPJ: " +QString::number(CNPJ));
}

