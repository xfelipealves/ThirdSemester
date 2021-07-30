#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <Pessoa.h>
#include <QString>
namespace Quest2 {
    class PessoaJuridica : public Pessoa
    {
    private:
        long CNPJ;
        QString razaoSocial;
    public:
        PessoaJuridica();
        PessoaJuridica(QString nome, QString endereco, long telefone,
                       QString email, double rendaBruta, long CNPJ, QString razaoSocial);
        void setCNPJ(long CNPJ);
        void setRazaoSocial(QString razaoSocial);
        long getCNPJ();
        QString getRazaoSocial();
        QString calcularImposto();
        QString print() override;
    };
}


#endif // PESSOAJURIDICA_H
