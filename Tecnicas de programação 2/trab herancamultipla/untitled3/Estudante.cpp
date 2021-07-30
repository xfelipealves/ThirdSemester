#include "Estudante.h"

Estudante::Estudante()
{
    matricula=0;
    nome=curso="";
}

Estudante::Estudante(QString nome, int matricula, QString curso)
{
    setNome(nome);
    setMatricula(matricula);
    setCurso(curso);
}

QString Estudante::getNome()
{
    return nome;
}

int Estudante::getMatricula()
{
    return matricula;
}

QString Estudante::getCurso()
{
    return curso;
}

void Estudante::setNome(QString nome)
{
    this->nome=nome;
}

void Estudante::setMatricula(int matricula)
{
    if (matricula<0)
        throw QString("Negativo");
    this->matricula=matricula;
}

void Estudante::setCurso(QString curso)
{
    this->curso=curso;
}

QString Estudante::print()
{
    return QString("\nNome: " + nome + "\nMatricula: " + QString::number(matricula) + "\nCurso: " + curso);
}
