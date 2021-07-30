#ifndef LISTAC_H
#define LISTAC_H
#include <Node.h>
#include <Objeto.h>
#include <iostream>
//Jogadores
class ListaC
{
private:
    Node<Objeto>* Head;
    Node<Objeto>* IT;
    int N;
public:
    ListaC();
    bool Push(Objeto* Dat);
    bool Remove(int j);
    void NextIT();
    void PrevIT();
    void ResetIT();
    Node<Objeto>* getIT();
    int Size();
    void print();
};

#endif // LISTAC_H
