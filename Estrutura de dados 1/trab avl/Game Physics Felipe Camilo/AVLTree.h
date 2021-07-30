#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"
#include "Objeto.h"
#include "ListaC.h"
#include <algorithm>
template <class thing>
class AVLTree
{
private:
    Node<thing>* Root;
public:
    AVLTree();
    bool insert(thing* Dat);
    static bool InsertR(Node<thing>**R, Node<thing>* Aux);
    bool Search(int x, int y, thing* Dat);
    bool Search2(int x, int y, thing* Dat);
    static bool SearchR(int x, int y, Node<thing>* P, thing* Dat);
    static Node<thing>* Maximus(Node<thing>* R);
    bool Remove(int x, int y, thing* Dat);
    static bool RemoveR(int x, int y, Node<thing>**R, thing* Dat);

    static void RSE(Node<thing>**R);
    static void RSD(Node<thing>**R);
    static void RDE(Node<thing>**R);
    static void RDD(Node<thing>**R);
    static bool ABRE(Node<thing>**R);//Avaliador de Balanceamento Remove Esquerda
    static bool ABRD(Node<thing>**R);//Avaliador de Balanceamento Remove Direita
};

template<class thing>
AVLTree<thing>::AVLTree()
{
    Root=nullptr;
}

template<class thing>
bool AVLTree<thing>::InsertR(Node<thing> **R, Node<thing> *Aux)
{
    if(!*R)
    {//xuxa lá
        *R = Aux;
        Aux->fb=0;
        return true;
    }
    if((Aux->D) < ((*R)->D))
    {// vai inserir à esquerda
        if(AVLTree<thing>::InsertR(&((*R)->Left), Aux))
        {// A subárvore da esquerda cresceu
            if((*R)->fb==1)
            {
                (*R)->fb=0;
                return false;
            }
            if((*R)->fb==0)
            {
                (*R)->fb=-1;
                return true;
            }
            //fb é -1 FUDEU iria para -2
            //avaliar qual tipo de rotação a ser feita
            if(((*R)->Left)->fb == -1)
            {//rotação simples à direita
                AVLTree<thing>::RSD(R);
                return false;
            }
            //fb do filho à esquerda é +1
            AVLTree<thing>::RDD(R);
            return false;
        }
        //A subárvore da esquerda não cresceu
        return false;
    }

    // vai inserir à direita
    if(AVLTree<thing>::InsertR(&((*R)->Right), Aux))
    {// A subárvore da direita cresceu
        if((*R)->fb==-1)
        {
            (*R)->fb=0;
            return false;
        }
        if((*R)->fb==0)
        {
            (*R)->fb=+1;
            return true;
        }
        //fb é +1 FUDEU iria para +2
        //avaliar qual tipo de rotação a ser feita
        if(((*R)->Right)->fb == +1)
        {//rotação simples à direita
            AVLTree<thing>::RSE(R);
            return false;
        }
        //fb do filho à direita é -1
        AVLTree<thing>::RDE(R);
        return false;
    }
    //A subárvore da direita não cresceu
    return false;
}

template<class thing>
bool AVLTree<thing>::insert(thing *Dat)
{
    Node<thing>*Aux=Node<thing>::montaNode(Dat);
    if (!Aux)
        return false;
    return !AVLTree<thing>::InsertR(&Root, Aux);;
}

template<class thing>
bool AVLTree<thing>::Search(int x, int y, thing *Dat)
{
    Node<thing>* P=Root;
    while(P and (x!= P->D.x or y!= P->D.y) )
    {
        if (x < P->D.x)
        {
            P=P->Left;
        }
        else
        {
            if (x==P->D.x)
            {//x igual
                if (y < P->D.y)
                {
                    P=P->Left;
                }
                else
                {
                    P=P->Right;
                }
            }
            else
            {//x maior
                P=P->Right;
            }
        }
    }
    if (!P)//ACABOU E NAO ACHOU
        return false;
    //ACHOU
    *Dat=P->D;
    return true;
}

template<class thing>
bool AVLTree<thing>::Search2(int x, int y, thing *Dat)
{
    return AVLTree<thing>::SearchR(x,y,Root,Dat);
}

template<class thing>
bool AVLTree<thing>::SearchR(int x, int y, Node<thing> *P, thing *Dat)
{
    if (!P)//ACABOU E NAO ACHOU
        return false;
    if (x == P->D.x and y == P->D.y)
    {//ACHOU
        *Dat=P->D;
        return true;
    }
    if (x < P->D.x)//NAO ACABOU E VAI PRA ESQUERDA
        return SearchR(x,y,P->Left,Dat);
    if (x == P->D.x and y < P->D.y)
        return SearchR(x,y,P->Left,Dat);
    return SearchR(x,y,P->Right,Dat);//NAO ACABOU E VAI PRA DIREITA
}

template<class thing>
Node<thing> *AVLTree<thing>::Maximus(Node<thing> *R)
{//BUSCA O ANTECESSOR NO MAXIMO DA DIREITA //R TEM QUE RECEBER O LEFT
    if (!R)
        return nullptr;
    if (!R->Right)
        return R;
    return AVLTree::Maximus(R->Right);
}

template<class thing>
bool AVLTree<thing>::Remove(int x, int y, thing *Dat)
{
    return !AVLTree::RemoveR(x, y,&Root,Dat);
}

template<class thing>
bool AVLTree<thing>::RemoveR(int x, int y, Node<thing> **R, thing *Dat)
{
    if(!(*R)){//não achou
        Dat = nullptr;
        return false;
    }
    if(x < ((*R)->D).x)
    {//vai para a esquerda
        if(AVLTree<thing>::RemoveR(x,y,&((*R)->Left),Dat))
        {//A altura da sub à esquerda diminuiu
            return AVLTree<thing>::ABRE(R);
        }
        return false;
    }
    if(x > ((*R)->D).x)
    {//vai para a direita
        if(AVLTree<thing>::RemoveR(x,y,&((*R)->Right),Dat))
        {//A altura da sub à direita diminui
            return AVLTree<thing>::ABRD(R);
        }
        return false;
    }
    if(y < ((*R)->D).y)
    {//vai para a esquerda
        if(AVLTree<thing>::RemoveR(x,y,&((*R)->Left),Dat))
        {//A altura da sub à esquerda diminuiu
            return AVLTree<thing>::ABRE(R);
        }
        return false;
    }
    if(y > ((*R)->D).y)
    {//vai para a direita
        if(AVLTree<thing>::RemoveR(x,y,&((*R)->Right),Dat))
        {//A altura da sub à direita diminui
            return AVLTree<thing>::ABRD(R);
        }
        return false;
    }
    //Achou!!!
    //vamos ver se não tem filho a esquerda
    Node<thing> * Aux;
    if(!(*R)->Left)
    {
        Aux = *R;
        *R = Aux->Right;
        *Dat=Node<thing>::desmontaNode(Aux);
        return true;
    }
    //ele tem filho à esquerda, vamos ver se não tem filho à direita
    if(!(*R)->Right)
    {
        Aux = *R;
        *R = Aux->Left;
        *Dat = Node<thing>::desmontaNode(Aux);
        return true;
    }
    //ele tem dois filhos
    //escolhemos trabalhar com o antecessor
    //maior elemento da subárvore à esquerda
    Aux = AVLTree::Maximus((*R)->Left);
    std::swap((*R)->D,Aux->D);
//    thing ob=(*R)->D;
//    (*R)->D=Aux->D;
//    Aux->D=ob;
    if( AVLTree::RemoveR(x,y,&((*R)->Left),Dat) )
    {
        if((*R)->fb==0)
        {
            (*R)->fb=1;
            return false;
        }
        if((*R)->fb==-1)
        {
            (*R)->fb = 0;
            return true;
        }
        //era +1 e iria para +2,mas não vai
        //verificar se a rotação e simples ou dupla
        if(((*R)->Right)->fb==1)
        {//Rotação simples à esquerda
            AVLTree::RSE(R);
            return false;
        }
        if(((*R)->Right)->fb==0)
        {//Rotação Simples à esquerda
            AVLTree::RSE(R);
            return false;
        }
        //filho à tem fb = -1 (fb(b)=-1)
        AVLTree::RDE(R);
        return true;
    }
    return false;
}

template<class thing>
void AVLTree<thing>::RSE(Node<thing> **R)
{
    Node<thing>* a = *R;
    Node<thing>* b = a->Right;
    a -> Right = b -> Left;
    b->Left = a;
    *R = b;
    if(b->fb==+1)
    {
        a->fb = b->fb =0;
    }
    else
    {//b->fb =0
        a->fb = +1;
        b->fb = -1;
    }
}

template<class thing>
void AVLTree<thing>::RSD(Node<thing> **R)
{
    Node<thing>* a = *R;
    Node<thing>* b = a->Left;
    a -> Left = b -> Right;
    b->Right = a;
    *R = b;
    if(b->fb==-1)
    {
        a->fb = b->fb =0;
    }
    else
    {//b->fb =0
        a->fb = -1;
        b->fb = +1;
    }
}

template<class thing>
void AVLTree<thing>::RDE(Node<thing> **R)
{
    Node<thing>* a = *R;
    Node<thing>* b = a->Right;
    Node<thing>* c = b->Left;
    b->Left = c->Right;
    a->Right = c->Left;
    c->Right = b;
    c->Left = a;
    *R = c;
    if(c->fb == -1)
    {
        b->fb=1;
        a->fb=0;
    }
    else
    {
        if(c->fb == 1)
        {
            b->fb=0;
            a->fb=-1;
        }
        else
        {//fb(c) = 0
            b->fb=a->fb=0;
        }
    }
    c->fb=0;
}

template<class thing>
void AVLTree<thing>::RDD(Node<thing> **R)
{
    Node<thing>* a = *R;
    Node<thing>* b = a->Left;
    Node<thing>* c = b->Right;
    b->Right = c->Left;
    a->Left = c->Right;
    c->Left = b;
    c->Right = a;
    *R = c;
    if(c->fb == 1)
    {
        b->fb=-1;
        a->fb=0;
    }
    else
    {
        if(c->fb == -1)
        {
            b->fb=0;
            a->fb=1;
        }
        else
        {//fb(c) = 0
            b->fb=a->fb=0;
        }
    }
    c->fb=0;
}

template <class thing>
bool AVLTree<thing>::ABRE(Node<thing>**R)
{
    if((*R)->fb==0)
    {
        (*R)->fb = 1;
        return false;
    }
    if((*R)->fb==-1)
    {
        (*R)->fb=0;
        return true;
    }
    //era +1 e iria para +2, mais não vai
    //verificar se a rotação é simples ou dupla
    if(((*R)->Right)->fb==1)
    {//Rotação simples à esquerda
        AVLTree::RSE(R);
        return true;
    }
    if(((*R)->Right)->fb==0)
    {//Rotação simles à esquerda
        AVLTree::RSE(R);
        return false;
    }
    //filho à tem fb = -1 (fb(b)=-1)
    AVLTree::RDE(R);
    return true;
}

template <class thing>
bool AVLTree<thing>::ABRD(Node<thing>**R)
{
    if((*R)->fb==0)
    {
        (*R)->fb = -1;
        return false;
    }
    if((*R)->fb==1)
    {
        (*R)->fb = 0;
        return true;
    }
    //era -1 e iria para -2,mais não vai
    //verificar se a rotação é simples ou dupla
    if(((*R)->Left)->fb==-1)
    {//rotação simples à direita
        AVLTree::RSD(R);
        return true;
    }
    if(((*R)->Left)->fb==0)
    {//rotação simples à direita
        AVLTree::RSD(R);
        return false;
    }
    //filho à tem fb = 1 (fb(b)= 1)
    AVLTree::RDD(R);
    return true;
}

#endif // AVLTREE_H
