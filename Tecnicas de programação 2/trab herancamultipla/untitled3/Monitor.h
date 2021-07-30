#ifndef MONITOR_H
#define MONITOR_H
#include "Estudante.h"
#include "Funcionario.h"

class Monitor: public Estudante, public Funcionario
{
private:
    QString disciplina;
    int cargaHoraria;
public:
    Monitor();
    Monitor(QString nome, int matricula, QString curso, double salario, QString turno, int rg, QString disciplina, int cargaHoraria);
    QString getDisciplina();
    int getCargaHoraria();
    void setDisciplina(QString disciplina);
    void setCargaHoraria(int cargaHoraria);
    QString print() override;
};

#endif // MONITOR_H
