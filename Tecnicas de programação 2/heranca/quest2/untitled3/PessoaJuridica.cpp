#include "PessoaJuridica.h"

Quest2::PessoaJuridica::PessoaJuridica() : Pessoa()
{
    CNPJ=-1;
    razaoSocial="";
}

Quest2::PessoaJuridica::PessoaJuridica(QString nome, QString endereco, long telefone, QString email, double rendaBruta, long CNPJ, QString razaoSocial)
 : Pessoa(nome,endereco,telefone,email,rendaBruta)
{
    setCNPJ(CNPJ);
    this->razaoSocial=razaoSocial;
}

void Quest2::PessoaJuridica::setCNPJ(long CNPJ)
{
    if (CNPJ<0)
        throw QString ("ERRO");
    this->CNPJ=CNPJ;
}

void Quest2::PessoaJuridica::setRazaoSocial(QString razaoSocial)
{
    this->razaoSocial=razaoSocial;
}

long Quest2::PessoaJuridica::getCNPJ()
{
    return CNPJ;
}

QString Quest2::PessoaJuridica::getRazaoSocial()
{
    return razaoSocial;
}

QString Quest2::PessoaJuridica::calcularImposto()
{
    double x=Pessoa::getRendaBruta()*12*0.08;
    return QString::number(x);
}

QString Quest2::PessoaJuridica::print()
{
    return Pessoa::print() + QString ("\nCNPJ: " + QString::number(CNPJ)
                                      + "\nRazaoSocial: " + razaoSocial);
}
