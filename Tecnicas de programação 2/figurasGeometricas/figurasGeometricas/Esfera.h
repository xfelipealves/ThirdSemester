#ifndef ESFERA_H
#define ESFERA_H

#include<FiguraGeometrica.h>

namespace TP2 {

    class Esfera : public FiguraGeometrica
    {
        public:
            Esfera();
            Esfera(float raio);
            virtual QString getTipoDaFigura()const;
            virtual float calcularAreaTotal() const;
            virtual float calcularVolume() const;
    };
}
#endif // ESFERA_H
