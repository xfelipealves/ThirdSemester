#include "Trabalhador.h"

Quest1::Trabalhador::Trabalhador():Pessoa(),funcao("funcao nao informada"),departamento("departamento nao informado"),salario(0)
{
}

QString Quest1::Trabalhador::getFuncao()
{
    return funcao;
}

QString Quest1::Trabalhador::getDepartamento()
{
    return departamento;
}

long Quest1::Trabalhador::getSalario()
{
    return salario;
}

void Quest1::Trabalhador::setFuncao(QString *funcao)
{
    this->funcao=*funcao;
}

void Quest1::Trabalhador::setDepartamento(QString *departamento)
{
    this->departamento=*departamento;
}

void Quest1::Trabalhador::setSalario(long *salario)
{
    this->salario=*salario;
}

QString Quest1::Trabalhador::print()
{
    return Pessoa::print() + QString("\nFuncao: " + funcao + "\nDepartamento: " + departamento + "\nSalario: " + QString::number(salario));
}
