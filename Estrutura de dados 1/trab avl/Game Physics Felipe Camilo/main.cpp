#include <iostream>
#include <AVLTree.h>
#include "Objeto.h"
#include "ListaC.h"
using namespace std;
int main()
{
    int n;//Quantidade de jogadores
    int x,y;//Posições
    int v,a;//HP e Ataque
    int lx,ly;//limite do mapa
    AVLTree<Objeto> nozes; //Criar a arvore de objeto
    ListaC players; //lista de players

    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x>>y>>v>>a;
        Objeto* bola= new Objeto(x,y,v,a,i+1);
        Objeto* jbl= new Objeto(x,y,v,a,i+1);
        nozes.insert(bola); //insert player na arvore
        players.Push(jbl); //insert player na lista
    }

    cin>>lx>>ly;//limite do mapa

    cin>>x>>y;
    while (x>=0 and y>=0)
    {
        nozes.insert(new Objeto(x,y)); //insert pedra na arvore
        cin>>x>>y;
    }


    int mov;
    Node<Objeto>* jogador;

    //movimentos
    players.ResetIT();
    jogador=players.getIT();//pega o player atual
    while (true)
    {
        mov=5;
        //leitura dos movimentos
        char xx,yy;
        cin>>xx>>yy;
        while (mov>0 and xx!='F' and yy!='0')
        {
            if (xx=='M' and mov>=1)
            {//MOVER
                mov=mov-1;
                int vx,vy;//novas direçoes
                if (yy=='2')
                {//baixo, vai ter q mudar o Y/LINHA
                    vx=jogador->D.x;//o x mantem
                    if (jogador->D.y!=ly-1)//se nao tiver limite de linhas
                    {//as linhas sao validas
                        vy=jogador->D.y+1;
                        Objeto* cc=new Objeto;
                        if (!nozes.Search(vx,vy,cc))
                        {//nao tem nada naquela posição
                            nozes.Remove(vx,vy-1,cc);//remove o player
                            nozes.insert(new Objeto(vx,vy,jogador->D.hp,jogador->D.dano,jogador->D.j));
                            //player movido de lugar
                            jogador->D.y=vy;//atualiza o jogador na lista
                        }
                    }
                }
                else {
                    if (yy=='4')
                    {//esquerda, vai ter q mudar o X/COLUNA
                        vy=jogador->D.y;//o y mantem
                        if (jogador->D.y!=0)//se nao tiver limite de colunas
                        {//as colunas sao validas
                            vx=jogador->D.x-1;
                            Objeto* cc=new Objeto;
                            if (!nozes.Search(vx,vy,cc))
                            {//nao tem nada naquela posição
                                nozes.Remove(vx+1,vy,cc);//remove o player
                                nozes.insert(new Objeto(vx,vy,jogador->D.hp,jogador->D.dano,jogador->D.j));
                                //player movido de lugar
                                jogador->D.x=vx;//atualiza o jogador na lista
                            }
                        }
                    }
                    else {
                        if (yy=='6')
                        {//direita, vai ter q mudar o X/COLUNA
                            vy=jogador->D.y;//o y mantem
                            if (jogador->D.y!=lx-1)//se nao tiver limite de colunas
                            {//as colunas sao validas
                                vx=jogador->D.x+1;
                                Objeto* cc=new Objeto;
                                if (!nozes.Search(vx,vy,cc))
                                {//nao tem nada naquela posição
                                    nozes.Remove(vx-1,vy,cc);//remove o player
                                    nozes.insert(new Objeto(vx,vy,jogador->D.hp,jogador->D.dano,jogador->D.j));
                                    //player movido de lugar
                                    jogador->D.x=vx;//atualiza o jogador na lista
                                }
                            }

                        }
                        else {
                            if (yy=='8')
                            {//cima, vai ter q mudar o Y/LINHA
                                vx=jogador->D.x;//o x mantem
                                if (jogador->D.y!=0)//se nao tiver limite de linhas
                                {//as linhas sao validas
                                    vy=jogador->D.y-1;
                                    Objeto* cc=new Objeto;
                                    if (!nozes.Search(vx,vy,cc))
                                    {//nao tem nada naquela posição
                                        nozes.Remove(vx,vy+1,cc);//remove o player
                                        nozes.insert(new Objeto(vx,vy,jogador->D.hp,jogador->D.dano,jogador->D.j));
                                        //player movido de lugar
                                        jogador->D.y=vy;//atualiza o jogador na lista
                                    }
                                }

                            }
                        }
                    }
                }
//                cout<<"Moveu pra "<<vx<<vy<<endl;
            }
            else {
                if (xx=='A' and mov>=1)
                {
                    mov=mov-1;
                    int ix, iy;
                    if (yy=='2')
                    {//atacar pra baixo // vai ir mudando o Y para baixo Y++
                        Objeto* cc=new Objeto;
                        for (ix=jogador->D.x, iy=jogador->D.y+1; iy<ly and !nozes.Search(ix,iy,cc); iy++);
                        if (iy<ly and cc->id)
                        {//nao chegou no limite e tem um player
                            //ix e iy tem as coordenadas do player;
                            cc->hp=cc->hp-jogador->D.dano;//toma o dano (atoa, pq é só copia)
                            int vidaNova=cc->hp;//salva a nova vida em danim
                            int Idz=cc->j;
                            nozes.Remove(ix,iy,cc);//remove o antigo da arvore

                            //tem q atualizar na lista
                            players.NextIT();
                            while (players.getIT()!=jogador)
                            {//vai buscando o proximo
                                if (players.getIT()->D.j==Idz)
                                {
                                    players.getIT()->D.hp = vidaNova;//atualiza o dano na lista
                                    if (vidaNova>0)
                                    {//ele continua na arvore
                                        nozes.insert(new Objeto (ix,iy,vidaNova,players.getIT()->D.dano,players.getIT()->D.j));
                                    }
                                }
                                //o loop vai ser dado ate voltar pro jogador q fez a acao
                                players.NextIT();
                            }
                        }
                    }
                    else {
                        if (yy=='4')
                        {//atacar pra esquerda // vai ir mudando o X para esquerda X--
                            Objeto* cc=new Objeto;
                            for (ix=jogador->D.x-1, iy=jogador->D.y; ix>=0 and !nozes.Search(ix,iy,cc); ix--);
                            if (ix>=0 and cc->id)
                            {//nao chegou no limite e tem um player
                                //ix e iy tem as coordenadas do player;
                                cc->hp=cc->hp-jogador->D.dano;//toma o dano (atoa, pq é só copia)
                                int vidaNova=cc->hp;//salva a nova vida em danim
                                int Idz=cc->j;
                                nozes.Remove(ix,iy,cc);//remove o antigo da arvore

                                //tem q atualizar na lista
                                players.NextIT();
                                while (players.getIT()!=jogador)
                                {//vai buscando o proximo
                                    if (players.getIT()->D.j==Idz)
                                    {
                                        players.getIT()->D.hp = vidaNova;//atualiza o dano na lista
                                        if (vidaNova>0)
                                        {//ele continua na arvore
                                            nozes.insert(new Objeto (ix,iy,vidaNova,players.getIT()->D.dano,players.getIT()->D.j));
                                        }
                                    }
                                    //o loop vai ser dado ate voltar pro jogador q fez a acao
                                    players.NextIT();
                                }
                            }
                        }
                        else {
                            if (yy=='6')
                            {//atacar pra direita // vai ir mudando o X para direita X++
                                Objeto* cc=new Objeto;
                                for (ix=jogador->D.x+1, iy=jogador->D.y; ix<lx and !nozes.Search(ix,iy,cc); ix++);
                                if (ix<lx and cc->id)
                                {//nao chegou no limite e tem um player
                                    //ix e iy tem as coordenadas do player;
                                    cc->hp=cc->hp-jogador->D.dano;//toma o dano (atoa, pq é só copia)
                                    int vidaNova=cc->hp;//salva a nova vida em danim
                                    int Idz=cc->j;
                                    nozes.Remove(ix,iy,cc);//remove o antigo da arvore

                                    //tem q atualizar na lista
                                    players.NextIT();
                                    while (players.getIT()!=jogador)
                                    {//vai buscando o proximo
                                        if (players.getIT()->D.j==Idz)
                                        {
                                            players.getIT()->D.hp = vidaNova;//atualiza o dano na lista
                                            if (vidaNova>0)
                                            {//ele continua na arvore
                                                nozes.insert(new Objeto (ix,iy,vidaNova,players.getIT()->D.dano,players.getIT()->D.j));
                                            }
                                        }
                                        //o loop vai ser dado ate voltar pro jogador q fez a acao
                                        players.NextIT();
                                    }
                                }
                            }
                            else {
                                if (yy=='8')
                                {//atacar pra cima // vai ir mudando o Y para cima Y--
                                    Objeto* cc=new Objeto;
                                    for (ix=jogador->D.x, iy=jogador->D.y-1; iy>=0 and !nozes.Search(ix,iy,cc); iy--);
                                    if (iy>=0 and cc->id)
                                    {//nao chegou no limite e tem um player
                                        //ix e iy tem as coordenadas do player;
                                        cc->hp=cc->hp-jogador->D.dano;//toma o dano (atoa, pq é só copia)
                                        int vidaNova=cc->hp;//salva a nova vida em danim
                                        int Idz=cc->j;
                                        nozes.Remove(ix,iy,cc);//remove o antigo da arvore

                                        //tem q atualizar na lista
                                        players.NextIT();
                                        while (players.getIT()!=jogador)
                                        {//vai buscando o proximo
                                            if (players.getIT()->D.j==Idz)
                                            {
                                                players.getIT()->D.hp = vidaNova;//atualiza o dano na lista
                                                if (vidaNova>0)
                                                {//ele continua na arvore
                                                    nozes.insert(new Objeto (ix,iy,vidaNova,players.getIT()->D.dano,players.getIT()->D.j));
                                                }
                                            }
                                            //o loop vai ser dado ate voltar pro jogador q fez a acao
                                            players.NextIT();
                                        }
                                    }
                                }
                            }
                        }
                    }
//                    cout<<"Atacou pra "<<ix<<iy<<endl;
                }
                else {
                    if (xx=='C' and mov>=4)
                    {
                        mov=mov-4;
                        int vx,vy;//coordenadas do novo bloco
                        if (yy=='2')
                        {//CONSTRUIR UM BLOCO EM BAIXO
                            vx=jogador->D.x;
                            vy=jogador->D.y+1;
                            if (vy!=ly)
                            {//nao ta no limite
                                Objeto* cc=new Objeto;
                                if (!nozes.Search(vx,vy,cc))
                                {//nao tem nada naquele lugar
                                    nozes.insert(new Objeto(vx,vy));//insert da pedra
                                }
                            }
                        }
                        else {
                            if (yy=='4')
                            {//CONSTRUIR UM BLOCO NA ESQUERDA
                                vx=jogador->D.x;
                                vy=jogador->D.y;
                                if (vx!=0)
                                {//nao ta no limite
                                    Objeto* cc=new Objeto;
                                    if (!nozes.Search(vx-1,vy,cc))
                                    {//nao tem nada naquele lugar
                                        nozes.insert(new Objeto(vx-1,vy));//insert da pedra
                                    }
                                }
                            }
                            else {
                                if (yy=='6')
                                {//CONSTRUIR UM BLOCO NA DIREITA
                                    vx=jogador->D.x;
                                    vy=jogador->D.y;
                                    if (vx!=lx-1)
                                    {//nao ta no limite
                                        Objeto* cc=new Objeto;
                                        if (!nozes.Search(vx+1,vy,cc))
                                        {//nao tem nada naquele lugar
                                            nozes.insert(new Objeto(vx+1,vy));//insert da pedra
                                        }
                                    }
                                }
                                else {
                                    if (yy=='8')
                                    {//CONSTRUIR UM BLOCO EM CIMA
                                        vx=jogador->D.x;
                                        vy=jogador->D.y;
                                        if (vy!=0)
                                        {//nao ta no limite
                                            Objeto* cc=new Objeto;
                                            if (!nozes.Search(vx,vy-1,cc))
                                            {//nao tem nada naquele lugar
                                                nozes.insert(new Objeto(vx,vy-1));//insert da pedra
                                            }
                                        }
                                    }
                                }
                            }
                        }
//                        cout<<"Construiu pra "<<vx<<vy<<endl;
                    }
                    else {
                        if (xx=='D' and mov>=3)
                        {
                            mov=mov-3;
                            int vx,vy;//coordenadas do bloco
                            if (yy=='2')
                            {//DESTRUIR UM BLOCO EM BAIXO
                                vx=jogador->D.x;
                                vy=jogador->D.y+1;
                                if (vy!=ly)
                                {//nao ta no limite
                                    Objeto* cc=new Objeto;
                                    if (nozes.Search(vx,vy,cc))
                                    {//tem alguma coisa naquele lugar
                                        if (!cc->id)
                                        {//nao éh player, entao remove
                                            nozes.Remove(vx,vy,cc);//remove da pedra
                                        }
                                    }
                                }
                            }
                            else {
                                if (yy=='4')
                                {//DESTRUIR UM BLOCO NA ESQUERDA
                                    vx=jogador->D.x;
                                    vy=jogador->D.y;
                                    if (vx!=0)
                                    {//nao ta no limite
                                        Objeto* cc=new Objeto;
                                        if (nozes.Search(vx-1,vy,cc))
                                        {//tem alguma coisa naquele lugar
                                            if (!cc->id)
                                            {//nao éh player, entao remove
                                                nozes.Remove(vx-1,vy,cc);//remove da pedra
                                            }
                                        }
                                    }
                                }
                                else {
                                    if (yy=='6')
                                    {//DESTRUIR UM BLOCO NA DIREITA
                                        vx=jogador->D.x;
                                        vy=jogador->D.y;
                                        if (vx!=lx-1)
                                        {//nao ta no limite
                                            Objeto* cc=new Objeto;
                                            if (nozes.Search(vx+1,vy,cc))
                                            {//tem alguma coisa naquele lugar
                                                if (!cc->id)
                                                {//nao éh player, entao remove
                                                    nozes.Remove(vx+1,vy,cc);//remove da pedra
                                                }
                                            }
                                        }
                                    }
                                    else {
                                        if (yy=='8')
                                        {//DESTRUIR UM BLOCO EM CIMA
                                            vx=jogador->D.x;
                                            vy=jogador->D.y;
                                            if (vy!=0)
                                            {//nao ta no limite
                                                Objeto* cc=new Objeto;
                                                if (nozes.Search(vx,vy-1,cc))
                                                {//tem alguma coisa naquele lugar
                                                    if (!cc->id)
                                                    {//nao éh player, entao remove
                                                        nozes.Remove(vx,vy-1,cc);//remove da pedra
                                                    }
                                                }
                                            }

                                        }
                                    }
                                }
                            }
//                            cout<<"Desconstruiu pra "<<vx<<vy<<endl;
                        }
                        else {//nao deu certo alguma jogada, logo ele perdeu a vez
                            mov=0;
//                            cout<<"Perdeu a vez"<<endl;
                        }
                    }
                }
            }
            if (mov>0)
            {
                cin>>xx>>yy;
            }
        }
//        cout<<jogador->D.j<<" "<<jogador->D.hp<<endl<<endl;
        players.NextIT();
        while (players.getIT()->D.hp<=0)
        {//enquanto o player estiver morto, passa pro proximo;
            players.NextIT();
        }
        if (players.getIT()->D.j==jogador->D.j)
        {//voltou pro mesmo player, então para
            break;//para o while, e o jogo para!
        }
        //chegou aqui, então ainda tem jogo!
        jogador=players.getIT();
    }
    players.print();//imprime os status de cada um

    return 0;
}
