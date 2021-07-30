#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include<QString>
#include<math.h>

namespace TP2 {

    class FiguraGeometrica
    {
        private:
            float raio;
        public:
            FiguraGeometrica();
            FiguraGeometrica(float raio);
            void setRaio(float raio);
            float getRaio() const;
            virtual float calcularAreaTotal() const=0;
            virtual float calcularVolume() const=0;
            virtual QString getTipoDaFigura()const=0;
    };
}
#endif // FIGURAGEOMETRICA_H
