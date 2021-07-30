#ifndef CAMINHAO_H
#define CAMINHAO_H
#include "Motor.h"
#include "Veiculo.h"
#include <QString>
namespace trab {
    class Caminhao : public Veiculo, public Motor
    {
    private:
        double toneladas, alturaMaxima, comprimento;
    public:
        Caminhao();
        Caminhao(double peso, double velocidadeMaxima, double preco, int numCilindros, int potencia, double toneladas, double alturaMaxima, double comprimento);
        double getToneladas();
        double getAlturaMaxima();
        double getComprimento();
        void setToneladas(double toneladas);
        void setAlturaMaxima(double alturaMaxima);
        void setComprimento(double comprimento);
        QString print() override;
    };
}


#endif // CAMINHAO_H
