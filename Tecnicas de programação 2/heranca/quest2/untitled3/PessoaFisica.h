#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <Pessoa.h>
#include <QString>
namespace Quest2 {
    class PessoaFisica : public Pessoa
    {
    private:
        long CPF;
        QString sexo;
    public:
        PessoaFisica();
        PessoaFisica(QString nome, QString endereco, long telefone, QString email, double rendaBruta, long CPF, QString sexo);
        void setCPF(long CPF);
        void setSexo(QString sexo);
        long getCPF();
        QString getSexo();
        QString calcularImposto();
        QString print() override;
    };
}


#endif // PESSOAFISICA_H
