#ifndef AGENDA_H
#define AGENDA_H
#include <QString>
#include <Pessoa.h>
#include <PessoaFisica.h>
#include <PessoaJuridica.h>
#include <typeinfo>
namespace ag {
    class Agenda
    {
    private:
        Pessoa* Head;
        int N;
    public:
        Agenda();
        void ordena();
        bool adiciona(Pessoa* Busca);
        bool remove(QString nome);
        QString buscarContato(QString nome);
        QString printTodos();
    };
}


#endif // AGENDA_H
