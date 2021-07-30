#ifndef JOGO_H
#define JOGO_H
#include <ListaC.h>
#include <Pilha.h>
#include <Jogador.h>
#include <Node.h>
class Jogo
{
public:
    Jogo(int QntJgd);
    void DistribuirCartas();
    void ReporMonte();
    bool DescartaUma(Carta* L);
    bool CompraUma();
    void ProximoJogador();
    bool Vez();
    int getQntJgd();
    void Rodada(Jogador* Vencedor);
    Pilha Monte;
    void Clear();
private:
    Pilha Lixo;
    int QntJgd;
    bool sentido; //true HORARIO
    //false ANTIHORARIO
    ListaC Jogadores;
};

#endif // JOGO_H
