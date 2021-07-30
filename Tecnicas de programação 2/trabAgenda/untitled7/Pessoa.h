#ifndef PESSOA_H
#define PESSOA_H
#include <QString>

namespace ag{
    class Pessoa
    {
    private:
        QString nome,endereco,email;
        Pessoa* Next;
    public:
        Pessoa();
        Pessoa(QString nome, QString endereco, QString email);
        void setNome(QString nome);
        void setEndereco(QString endereco);
        void setEmail(QString email);
        QString getNome();
        QString getEndereco();
        QString getEmail();
        virtual QString print();

        void setNext(Pessoa* Next);
        Pessoa* getNext();

        virtual long long getCPFNJ()=0;
    };
}
#endif // PESSOA_H
