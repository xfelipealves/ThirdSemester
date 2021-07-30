#ifndef GATO_H
#define GATO_H
#include "Animal.h"

namespace TP2 {

class Gato : public Animal
{
public:
    Gato();
    QString falar(){return "Miau";}
};
}
#endif // GATO_H
