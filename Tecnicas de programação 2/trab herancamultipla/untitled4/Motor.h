#ifndef MOTOR_H
#define MOTOR_H
#include <QString>
namespace trab {
    class Motor
    {
    private:
        int numCilindros,potencia;
    public:
        Motor();
        Motor(int numCilindros, int potencia);
        int getNumCilindros();
        int getPotencia();
        void setNumCilindros(int numCilindros);
        void setPotencia(int potencia);
        virtual QString print();
    };
}


#endif // MOTOR_H
