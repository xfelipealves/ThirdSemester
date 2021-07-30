#include "FiguraGeometrica.h"

namespace TP2 {
    FiguraGeometrica::FiguraGeometrica():raio(1)
    {}

    FiguraGeometrica::FiguraGeometrica(float raio)
    {
        setRaio(raio);
    }

    void FiguraGeometrica::setRaio(float raio){
        if(raio<=0)
            throw QString ("Raio inválido.");
        this->raio = raio;
    }

    float FiguraGeometrica::getRaio() const{
        return raio;
    }
}

