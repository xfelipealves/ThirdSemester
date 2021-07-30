#include "Estudante.h"
using namespace Quest1;
Estudante::Estudante():Pessoa(), matricula(0), curso("Curso nao informado"), campus("Campus nao informado")
{
}

long Estudante::getMatricula()
{
    return matricula;
}

QString Estudante::getCurso()
{
    return curso;
}

QString Estudante::getCampus()
{
    return campus;
}

void Estudante::setMatricula(long *matricula)
{
    this->matricula=*matricula;
}

void Estudante::setCurso(QString *curso)
{
    this->curso=*curso;
}

void Estudante::setCampus(QString *campus)
{
    this->campus=*campus;
}

QString Estudante::print()
{
    return Pessoa::print() + QString ("\nMatricula: " +  QString::number(matricula)
                                      +"\nCurso: " + curso + "\nCampus: " + campus);
}

