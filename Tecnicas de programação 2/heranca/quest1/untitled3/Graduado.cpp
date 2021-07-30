#include "Graduado.h"
using namespace Quest1;
Graduado::Graduado():Pessoa(),anodeconclusao(0),anodecolacao(0),numdiploma(0)
{
}


int Quest1::Graduado::getAnodeconclusao()
{
    return anodeconclusao;
}

int Quest1::Graduado::getAnodecolacao()
{
    return anodecolacao;
}

int Quest1::Graduado::getNumdiploma()
{
    return numdiploma;
}

void Quest1::Graduado::setAnodeconclusao(int a)
{
    if (a<0)
        throw QString ("Matricula invalido");
    anodeconclusao=a;
}

void Quest1::Graduado::setAnodecolacao(int a)
{
    if (a<0)
        throw QString ("Matricula invalido");
    anodecolacao=a;
}

void Quest1::Graduado::setNumdiploma(int n)
{
    if (n<0)
        throw QString ("NumDiploma invalido");
    numdiploma=n;
}

QString Graduado::print()
{
    return Pessoa::print() + QString ("\nAnoDeConclusao: " + QString::number(anodeconclusao)
                                      + "\nAnoDeColacao: " + QString::number(anodecolacao)
                                      + "\nNumDiploma: " + QString::number(numdiploma));
}
