#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>

class Animal
{
public:
    Animal();
    virtual QString falar()=0;
};

#endif // ANIMAL_H
