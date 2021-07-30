#ifndef GRADUADO_H
#define GRADUADO_H
#include "Pessoa.h"
#include "QString"
namespace Quest1 {
    class Graduado : public Pessoa
    {
    private:
        int anodeconclusao;
        int anodecolacao;
        int numdiploma;
    public:
        Graduado();
        int getAnodeconclusao();
        int getAnodecolacao();
        int getNumdiploma();
        void setAnodeconclusao(int a);
        void setAnodecolacao(int a);
        void setNumdiploma(int n);
        QString print();
    };
}


#endif // GRADUADO_H
