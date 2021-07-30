#ifndef CAO_H
#define CAO_H
#include "Animal.h"
namespace TP2 {

class Cao : public Animal
{
    public:
        Cao();
        QString falar(){return "Au Au";}
};

}
#endif // CAO_H
