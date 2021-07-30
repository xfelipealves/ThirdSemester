#ifndef LISTAC_H
#define LISTAC_H
#include <Node.h>
#include <Jogador.h>
//Jogadores
class ListaC
{
private:
    Node<Jogador>* Head;
    Node<Jogador>* IT;
    int N;
public:
    ListaC();
    bool Push(Jogador* Dat);
    bool Remove(int id);
    void NextIT();
    void PrevIT();
    void ResetIT();
    Node<Jogador>* getIT();
    int Size();
};

#endif // LISTAC_H
