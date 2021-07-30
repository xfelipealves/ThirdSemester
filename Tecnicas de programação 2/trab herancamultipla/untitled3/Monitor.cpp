#include "Monitor.h"

Monitor::Monitor(): Estudante(),Funcionario ()
{
    cargaHoraria=0;
    disciplina="";
}

Monitor::Monitor(QString nome, int matricula, QString curso, double salario, QString turno, int rg, QString disciplina, int cargaHoraria)
    : Estudante(nome,matricula,curso), Funcionario(nome,salario,turno,rg)
{
    setDisciplina(disciplina);
    setCargaHoraria(cargaHoraria);
}

QString Monitor::getDisciplina()
{
    return disciplina;
}

int Monitor::getCargaHoraria()
{
    return cargaHoraria;
}

void Monitor::setDisciplina(QString disciplina)
{
    this->disciplina=disciplina;
}

void Monitor::setCargaHoraria(int cargaHoraria)
{
    if (cargaHoraria<0)
        throw QString("Negativo");
    this->cargaHoraria=cargaHoraria;
}

QString Monitor::print()
{
    return QString(Estudante::print() + Funcionario::print() + "\nDisciplina: " + disciplina + "\nCargaHoraria: " + QString::number(cargaHoraria));
}
