#ifndef CARROPASSEIO_H
#define CARROPASSEIO_H
#include "Veiculo.h"
#include "Motor.h"
#include <QString>
namespace trab {
    class CarroPasseio : public Veiculo, public Motor
    {
    private:
        QString cor, modelo;
    public:
        CarroPasseio();
        CarroPasseio(double peso, double velocidadeMaxima, double preco, int numCilindros, int potencia, QString cor, QString modelo);
        QString getCor();
        QString getModelo();
        void setCor(QString cor);
        void setModelo(QString modelo);
        QString print() override;
    };
}


#endif // CARROPASSEIO_H
