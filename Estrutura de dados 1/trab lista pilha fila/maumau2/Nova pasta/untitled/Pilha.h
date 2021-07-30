#ifndef PILHA_H
#define PILHA_H

#include <Carta.h>
#include <Node.h>
//Monte e Lixo
class Pilha
{    
private:
    Node<Carta>* Head;
    int N;
public:
    Pilha();
    bool Push(Carta* Dat);
    bool Pop(Carta* Dat);
    bool Pop();
    void trocaPoder();
    Carta Top();
    bool IsEmpty();
    int size();
    void clear();
};

#endif // PILHA_H
