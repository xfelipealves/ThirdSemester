#include "Esfera.h"

namespace TP2 {
    Esfera::Esfera():FiguraGeometrica()
    {
    }

    Esfera::Esfera(float raio):FiguraGeometrica(raio)
    {
    }

    QString Esfera::getTipoDaFigura()const{
        return "Esfera";
    }

    float Esfera::calcularAreaTotal () const{
        return 4*M_PI*pow(getRaio(),2);
    }

    float Esfera::calcularVolume() const{
        return (4*M_PI*pow(getRaio(),3))/3;
    }

}
