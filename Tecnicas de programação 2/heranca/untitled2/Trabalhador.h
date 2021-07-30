#ifndef TRABALHADOR_H
#define TRABALHADOR_H
#include "Pessoa.h"
#include "QString"
namespace Quest1 {
    class Trabalhador : public Pessoa
    {
    private:
        QString funcao;
        QString departamento;
        long salario;
    public:
        Trabalhador();
        QString getFuncao();
        QString getDepartamento();
        long getSalario();
        void setFuncao(QString* funcao);
        void setDepartamento (QString* departamento);
        void setSalario(long* salario);
        QString print();
    };
}


#endif // TRABALHADOR_H
