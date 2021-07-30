#ifndef ESTUDANTE_H
#define ESTUDANTE_H
#include "Pessoa.h"
#include "QString"
namespace Quest1{
    class Estudante : public Pessoa
    {
    private:
        long matricula;
        QString curso;
        QString campus;
    public:
        Estudante();
        long getMatricula();
        QString getCurso();
        QString getCampus();
        void setMatricula(long* matricula);
        void setCurso(QString* curso);
        void setCampus(QString* campus);
        QString print();
    };
}
#endif // ESTUDANTE_H
