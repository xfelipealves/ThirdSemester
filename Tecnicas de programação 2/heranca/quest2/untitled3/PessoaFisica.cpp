#include "PessoaFisica.h"


Quest2::PessoaFisica::PessoaFisica() : Pessoa()
{
    CPF=-1;
    sexo="";
}

Quest2::PessoaFisica::PessoaFisica(QString nome, QString endereco, long telefone, QString email, double rendaBruta, long CPF, QString sexo)
 : Pessoa(nome,endereco,telefone,email,rendaBruta)
{
    setCPF(CPF);
    this->sexo=sexo;
}

void Quest2::PessoaFisica::setCPF(long CPF)
{
    if (CPF<0)
        throw QString ("ERRO");
    this->CPF=CPF;
}

void Quest2::PessoaFisica::setSexo(QString sexo)
{
    this->sexo=sexo;
}

long Quest2::PessoaFisica::getCPF()
{
    return CPF;
}

QString Quest2::PessoaFisica::getSexo()
{
    return sexo;
}

QString Quest2::PessoaFisica::calcularImposto()
{
    double x=Pessoa::getRendaBruta();
    double imp;
    if (x<=1903.98)
    {
        imp=0;
    }
    else
    {
        if (x<=2826.65)
        {
            imp=x*0.075;
        }
        else
        {
            if (x<=3751.05)
            {
                imp=x*0.15;
            }
            else
            {
                if (x<=4664.68)
                {
                    imp=x*0.225;
                }
                else
                {
                    imp=x*0.275;
                }
            }
        }
    }
    return QString::number(imp);
}

QString Quest2::PessoaFisica::print()
{
    return Pessoa::print() + QString ("\nCPF: " + QString::number(CPF)
                                      + "\nSexo: " + sexo);
}
