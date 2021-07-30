#include <iostream>
#include <Jogo.h>

int main()
{
    int N; //Quantidade de partidas
    int j; //Quantidade de jogadores

    std::cin>>N;

    for (int batman=0;batman<N;batman++)
    {
        std::cin>>j;

        Jogo MauMau(j);//cria o jogo com a qndt de jgdor
        Jogador Vencedor;
        while (MauMau.getQntJgd()>1)
        {
            char valor,naipe;
            for (int i=0;i<104;i++)
            {//LER BARALHO
                std::cin>>valor>>naipe;
                MauMau.Monte.Push(new Carta(valor,naipe));
                //XUXOU A CARTA NO MONTE
            }
            MauMau.DistribuirCartas();
            MauMau.Rodada(&Vencedor);//FEZ A PRIMEIRA RODADA
        }
        std::cout<<"Vencedor da partida "<<batman+1<<": ";
        std::cout<<"Jogador "<<Vencedor.getId()<<std::endl;
    }

    return 0;
}
