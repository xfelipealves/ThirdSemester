#ifndef NUMEROCOMPLEXO_H
#define NUMEROCOMPLEXO_H
#include <iostream>
using namespace std;

class NumeroComplexo;
class NumeroComplexo
{
private:
    float parteReal;
    float parteImaginaria;
public:
    NumeroComplexo();
    NumeroComplexo(float pr,float pi);
    float parte_real();
    float parte_imginaria();
    NumeroComplexo soma(NumeroComplexo n);
    NumeroComplexo subtrai(NumeroComplexo n);
    NumeroComplexo multiplica(NumeroComplexo n);
    NumeroComplexo divide(NumeroComplexo n);
    void imprimir();
};

#endif // NUMEROCOMPLEXO_H
