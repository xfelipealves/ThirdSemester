#ifndef CILINDRO_H
#define CILINDRO_H

#include<FiguraGeometrica.h>

namespace TP2 {
    class Cilindro : public FiguraGeometrica
    {
        private:
            float altura;
        public:
            Cilindro();
            Cilindro(float raio, float altura);
            void setAltura(float altura);
            float getAltura() const;
            float calcularAreaLateral()const;
            virtual float calcularAreaTotal()const;
            virtual float calcularVolume()const;
            virtual QString getTipoDaFigura() const;
    };
}
#endif // CILINDRO_H
