#ifndef PESSOA_H
#define PESSOA_H
#include <QString>
namespace Quest2 {
    class Pessoa
    {
    private:
        QString nome,endereco,email;
        long telefone;
        double rendaBruta;
    public:
        Pessoa();
        Pessoa(QString nome, QString endereco, long telefone, QString email, double rendaBruta);
        void setNome(QString nome);
        void setEndereco(QString endereco);
        void setTelefone(long telefone);
        void setEmail(QString email);
        void setRendaBruta(double rendaBruta);
        QString getNome();
        QString getEndereco();
        long getTelefone();
        QString getEmail();
        double getRendaBruta();
        virtual QString print();
    };
}


#endif // PESSOA_H
