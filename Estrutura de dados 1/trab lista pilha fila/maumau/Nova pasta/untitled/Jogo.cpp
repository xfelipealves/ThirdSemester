#include "Jogo.h"

Jogo::Jogo(int QntJgd)
{
    this->QntJgd=QntJgd;

    for (int i=0;i<QntJgd;i++)
    {//Criando jogadores
        Jogadores.Push(new Jogador(i+1));
    }
    sentido=true; //HORARIO
}

void Jogo::DistribuirCartas()
{
    Jogadores.ResetIT();
    if (Monte.IsEmpty())    return;
    for (int i=0;i<Jogadores.Size();i++)
    {
        for (int j=0;j<5;j++)
        {
            Carta Dat;
            Monte.Pop(&Dat);
            Jogadores.getIT()->D.Compra(&Dat);
        }
        Jogadores.NextIT();
    }
}

void Jogo::ReporMonte()
{
    Carta*TopLixo;
    if (!Lixo.IsEmpty())
        *TopLixo=Lixo.Top();//salva o topo
    while (Lixo.size())
    {
        Carta Dat;
        Lixo.Pop(&Dat);//tira do lixo
        Monte.Push(&Dat);//poe no monte
    }
    //tirou TUDO
    Lixo.Push(TopLixo);//coloca o topo de volta
}

bool Jogo::DescartaUma(Carta *L)
{
    if(!Jogadores.getIT())
    {//ta vazia;
        return false;
    }
    //Jogador IT descarta Uma;
    Carta C;
    bool x=((Jogadores.getIT())->D).Descarta(L,&C);
    if (x)
        Lixo.Push(&C);//novo topo do lixo
    return x;
}

bool Jogo::CompraUma()
{
    if(!Jogadores.getIT())
    {//ta vazia;
        return false;
    }
    if (Monte.IsEmpty())//se o monte tiver vazio
        ReporMonte();//repoe o monte
    Carta X;
    Monte.Pop(&X);//tira do monte
    return ((Jogadores.getIT())->D).Compra(&X);//bota no deck
}

void Jogo::ProximoJogador()
{
    if(!Jogadores.getIT())
    {//ta vazia;
        return ;
    }
    if (!Lixo.IsEmpty() and Lixo.Top().Valor=='L' and Lixo.Top().poder==true)//dama inverte a direçao
    {
        Lixo.trocaPoder();
        sentido=!sentido;
    }
    if (sentido)
    {//HORARIO
        Jogadores.NextIT();
        if (!Lixo.IsEmpty() and Lixo.Top().Valor=='A' and Lixo.Top().poder==true)//pula ele
        {
            Lixo.trocaPoder();
            Jogadores.NextIT();
        }
    }
    else
    {//ANTIHORARIO
        Jogadores.PrevIT();
        if (!Lixo.IsEmpty() and Lixo.Top().Valor=='A' and Lixo.Top().poder==true)//pula ele
        {
            Lixo.trocaPoder();
            Jogadores.PrevIT();
        }
    }
}

bool Jogo::Vez()
{
    if(!Jogadores.getIT())
    {//ta vazia;
        return false;
    }

    if (!Lixo.IsEmpty())
    {
        if (Lixo.Top().Valor=='G' and Lixo.Top().poder==true)//7=2 cartas comprar
        {
            Lixo.trocaPoder();
            CompraUma();
            CompraUma();
            return false;//NAO PODE JOGAR
        }
        if (Lixo.Top().Valor=='I' and Lixo.Top().poder==true)//9=3 cartas comprar
        {
            Lixo.trocaPoder();
            CompraUma();
            CompraUma();
            CompraUma();
            return false;//NAO PODE JOGAR
        }
    }

    Carta L;
    if (!Lixo.IsEmpty())
        L=Lixo.Top();//carta do topo do lixo

    if(!DescartaUma(&L))
    {//NAO CONSEGUIU DESCARTAR, ENTAO COMPRA UMA
        CompraUma();
        DescartaUma(&L);//TENTA DESCARTAR DENOVO
    }

    if (Jogadores.getIT()->D.Venceu())
        return true;

    ProximoJogador();
    return false;
}

int Jogo::getQntJgd()
{
    return QntJgd;
}

void Jogo::Rodada(Jogador *Vencedor)
{
    while (!Vez());
    *Vencedor=Jogadores.getIT()->D;//vencedor da rodada
    Clear();//limpa o lixo, baralho, e exclui
    //o jogador com mais pontos
}

void Jogo::Clear()
{
    Monte.clear();
    Lixo.clear();
    int a=0;
    int Excluir=0;
    Node<Jogador>* P=Jogadores.getIT();
    Jogadores.NextIT();
    while (Jogadores.getIT()!= P)
    {
        if (Jogadores.getIT()->D.getValorDeck()>a)
        {
            a=Jogadores.getIT()->D.getValorDeck();
            Excluir=Jogadores.getIT()->D.getId();
        }
        Jogadores.NextIT();
    }
    if (a>0)
    {//REMOVE O JOGADOR COM MAIS PONTO
        Jogadores.Remove(Excluir);
        QntJgd--;
    }
    Jogadores.ResetIT();
}
