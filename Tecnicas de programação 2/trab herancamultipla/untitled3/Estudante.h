#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include <QString>

class Estudante
{
private:
    QString nome;
    int matricula;
    QString curso;
public:
    Estudante();
    Estudante(QString nome, int matricula, QString curso);
    QString getNome();
    int getMatricula();
    QString getCurso();
    void setNome(QString nome);
    void setMatricula(int matricula);
    void setCurso(QString curso);
    virtual QString print();
};

#endif // ESTUDANTE_H
