#ifndef HOMEM_H
#define HOMEM_H

#include "Animal.h"

namespace TP2 {

class Homem: public Animal
{
public:
    Homem();
    QString falar(){return "Oi";}
};

}
#endif // HOMEM_H
