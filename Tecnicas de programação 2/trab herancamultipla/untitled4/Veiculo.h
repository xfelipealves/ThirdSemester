#ifndef VEICULO_H
#define VEICULO_H
#include <QString>
namespace trab {
    class Veiculo
    {
    private:
        double peso,velocidadeMaxima,preco;
    public:
        Veiculo();
        Veiculo(double peso, double velocidadeMaxima, double preco);
        double getPeso();
        double getVelocidadeMaxima();
        double getPreco();
        void setPeso(double peso);
        void setVelocidadeMaxima(double velocidadeMaxima);
        void setPreco(double preco);
        virtual QString print();
    };
}


#endif // VEICULO_H
