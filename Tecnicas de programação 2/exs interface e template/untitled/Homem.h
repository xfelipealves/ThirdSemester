#ifndef HOMEM_H
#define HOMEM_H
#include <Animal.h>
#include <QString>
class Homem : public Animal
{
public:
    Homem();
    QString falar();
};

#endif // HOMEM_H
