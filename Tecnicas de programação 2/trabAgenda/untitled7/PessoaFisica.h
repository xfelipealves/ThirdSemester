#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <QString>
#include <Pessoa.h>

namespace ag {
    class PessoaFisica : public Pessoa
    {
    private:
        QString nascimento,estadoCivil;
        long long CPF;
    public:
        PessoaFisica();
        PessoaFisica(QString nome, QString endereco, QString email, QString nascimento, QString estadoCivil, long long CPF);
        void setNascimento(QString nascimento);
        void setEstadoCivil(QString estadoCivil);
        void setCPF(long long CPF);
        QString getNascimento();
        QString getEstadoCivil();
        virtual long long getCPFNJ();
        QString print();
    };
}

#endif // PESSOAFISICA_H
