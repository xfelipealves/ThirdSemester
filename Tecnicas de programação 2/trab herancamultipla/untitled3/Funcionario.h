#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <QString>

class Funcionario
{
private:
    QString nome;
    double salario;
    QString turno;
    int rg;
public:
    Funcionario();
    Funcionario(QString nome, double salario, QString turno, int rg);
    QString getNome();
    double getSalario();
    QString getTurno();
    int getRg();
    void setNome(QString nome);
    void setSalario(double salario);
    void setTurno(QString turno);
    void setRg(int rg);
    virtual QString print();
};

#endif // FUNCIONARIO_H
