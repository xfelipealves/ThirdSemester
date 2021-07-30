#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <QString>
#include <Pessoa.h>

namespace ag {
    class PessoaJuridica : public Pessoa
    {
    private:
        int inscrEstadual;
        QString razaoSocial;
        long long CNPJ;
    public:
        PessoaJuridica();
        PessoaJuridica(QString nome, QString endereco, QString email, int inscrEstadual, QString razaoSocial, long long CNPJ);
        void setInscr(int inscrEstadual);
        void setRazaoSocial(QString razaoSocial);
        void setCNPJ(long long CNPJ);
        int getIsncrEstadual();
        QString getRazaoSocial();
        virtual long long getCPFNJ();
        QString print();
    };
}


#endif // PESSOAJURIDICA_H
