#ifndef CONE_H
#define CONE_H

#include <Cilindro.h>

namespace TP2 {

    class Cone : public Cilindro
    {
        public:
            Cone();
            Cone(float raio, float altura);
            float calcularGeratriz() const;
            float calcularAreaLateral() const;
            virtual float calcularAreaTotal() const;
            virtual float calcularVolume() const;
            virtual QString getTipoDaFigura() const;
    };
}
#endif // CONE_H
