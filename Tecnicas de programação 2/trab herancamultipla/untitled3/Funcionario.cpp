#include "Funcionario.h"

Funcionario::Funcionario()
{
    salario=rg=0;
    nome=turno="";
}

Funcionario::Funcionario(QString nome, double salario, QString turno, int rg)
{
    setNome(nome);
    setSalario(salario);
    setTurno(turno);
    setRg(rg);
}

QString Funcionario::getNome()
{
    return nome;
}

double Funcionario::getSalario()
{
    return salario;
}

QString Funcionario::getTurno()
{
    return turno;
}

int Funcionario::getRg()
{
    return rg;
}

void Funcionario::setNome(QString nome)
{
    this->nome=nome;
}

void Funcionario::setSalario(double salario)
{
    if (salario<0)
        throw QString("Negativo");
    this->salario=salario;
}

void Funcionario::setTurno(QString turno)
{
    this->turno=turno;
}

void Funcionario::setRg(int rg)
{
    if (rg<0)
        throw QString("Negativo");
    this->rg=rg;
}

QString Funcionario::print()
{
    return QString("\nNome: " + nome + "\nSalario: " + QString::number(salario) + "\nTurno: " + turno + "\nRg: " + QString::number(rg));
}
