#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include "QString"
using namespace std;
namespace Quest1 {
    class Pessoa
    {
    private:
        QString nome;
        QString endereco;
        long telefone;
        QString email;
    public:
        Pessoa();
        QString getNome();
        QString getEndereco();
        QString getEmail();
        long getTelefone();
        void setNome(QString* nome);
        void setEndereco(QString* endereco);
        void setEmail(QString* email);
        void setTelefone(long* telefone);
        virtual QString print();
    };
}


#endif // PESSOA_H
