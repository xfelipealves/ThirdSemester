#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <QString>
template <class T>
class Calculadora
{
private:
    T num1;
    T num2;
public:
    Calculadora();
    Calculadora(T num1, T num2);
    T adicionar(T num1, T num2);
    T subtrair(T num1, T num2);
    T multiplicar(T num1, T num2);
    T dividir(T num1, T num2);
    QString print();
};

template<class T>
Calculadora<T>::Calculadora()
{
    num1=num2=0;
}

template<class T>
Calculadora<T>::Calculadora(T num1, T num2)
{
    this->num1=num1;
    this->num2=num2;
}

template<class T>
T Calculadora<T>::adicionar(T num1, T num2)
{
    return num1+num2;
}

template<class T>
T Calculadora<T>::subtrair(T num1, T num2)
{
    return num1-num2;
}

template<class T>
T Calculadora<T>::multiplicar(T num1, T num2)
{
    return num1*num2;
}

template<class T>
T Calculadora<T>::dividir(T num1, T num2)
{
    if (num2==0)
        throw QString ("Num2 = 0");
    return num1/num2;
}

template<class T>
QString Calculadora<T>::print()
{
    return QString (QString::number(num1) + " " + QString::number(num2));
}

#endif // CALCULADORA_H
