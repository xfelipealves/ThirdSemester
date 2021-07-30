#include "NumeroComplexo.h"
#include <string>
namespace Felipao{

    NumeroComplexo::NumeroComplexo():parteReal(0),parteImag(0)
    {
    }//só pode implementar assim no construtor sem parametro.

    void NumeroComplexo::set(float parteReal, float parteImag)
    {
        this->parteReal=parteReal;
        this->parteImag=parteImag;
    }

    NumeroComplexo::NumeroComplexo(float parteReal, float parteImag)
    {
        set(parteReal,parteImag);
    }

    QString NumeroComplexo::get() const
    {
        QString saida;
        saida=QString::number(parteReal);
        if(parteImag>=0)
            saida=saida+" + ";
        saida=saida+QString::number(parteImag)+" i";

        return saida;
    }

    NumeroComplexo NumeroComplexo::operator +(NumeroComplexo numero)
    {
        NumeroComplexo obj(this->parteReal+numero.parteReal, this->parteImag+numero.parteImag);
        return obj;
    }

    NumeroComplexo NumeroComplexo::operator -(NumeroComplexo numero)
    {
        NumeroComplexo obj(this->parteReal-numero.parteReal, this->parteImag-numero.parteImag);
        return obj;
    }

    NumeroComplexo NumeroComplexo::operator *(NumeroComplexo numero)
    {
        float real=(this->parteReal*numero.parteReal)-(this->parteImag*numero.parteImag);
        float imag=(this->parteReal*numero.parteImag)+(this->parteImag*numero.parteReal);
        NumeroComplexo obj(real, imag);
        return obj;
    }

    NumeroComplexo NumeroComplexo::operator /(NumeroComplexo numero)
    {
        //a +bi
        // c+di

        //(ac+bd)/(c*c+d*d);    real
        //(cb-ad)i)/(c*c+d*d);  imag
        float use=(numero.parteReal*numero.parteReal)+(numero.parteImag*numero.parteImag);

        //parte real
        float real=( (this->parteReal*numero.parteReal)+(this->parteImag*numero.parteImag) )/use;

        //parte imag
        float imag=( (this->parteImag*numero.parteReal)-(this->parteReal*numero.parteImag) )/use;

        NumeroComplexo obj(real, imag);
        return obj;
    }

    QString NumeroComplexo::operator ==(NumeroComplexo numero)
    {
        if (this->parteReal==numero.parteReal and this->parteImag==numero.parteImag)
            return "Sim";
        return "Nao";
    }

    QString NumeroComplexo::operator !=(NumeroComplexo numero)
    {
        if (this->parteReal!=numero.parteReal and this->parteImag!=numero.parteImag)
            return "Sim";
        return "Nao";
    }
}
