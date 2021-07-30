#ifndef AVLTREE_H
#define AVLTREE_H
#include "Node.h"

template <class thing>
class AVLTree
{
private:
    Node<thing>* Root;
public:
    AVLTree();
    bool insert(thing* Dat); //ARRUMADO
    static bool InsertR(Node<thing>**R, Node<thing>* Aux); //ARRUMADO
    bool Search(int k, thing* Dat);
    bool Search2(int k, thing* Dat);
    static bool SearchR(int k, Node<thing>* P, thing* Dat);
    static Node<thing>* Maximus(Node<thing>* R);
    bool Remove(int k, thing* Dat); //ARRUMADO
    static bool RemoveR(int k, Node<thing>**R, thing* Dat); //ARRUMADO

    static void RSE(Node<thing>**R);
    static void RSD(Node<thing>**R);
    static void RDE(Node<thing>**R);
    static void RDD(Node<thing>**R);
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
    if((Aux->D).Key < ((*R)->D).Key)
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
bool AVLTree<thing>::Search(int k, thing *Dat)
{
    Node<thing>* P=Root;
    while(P and k!= P->D.Key)
    {
        if (k < P->D.Key)
        {
            P=P->Left;
        }
        else
        {
            P=P->Right;
        }
    }
    if (!P)//ACABOU E NAO ACHOU
        return false;
    //ACHOU
    *Dat=P->D;
    return true;
}

template<class thing>
bool AVLTree<thing>::Search2(int k, thing *Dat)
{
    return AVLTree<thing>::SearchR(k,Root,Dat);
}

template<class thing>
bool AVLTree<thing>::SearchR(int k, Node<thing> *P, thing *Dat)
{
    if (!P)//ACABOU E NAO ACHOU
        return false;
    if (k == P->D.Key)
    {//ACHOU
        *Dat=P->D;
        return true;
    }
    if (k < P->D.Key)//NAO ACABOU E VAI PRA ESQUERDA
        return SearchR(k,P->Left,Dat);
    return SearchR(k,P->Right,Dat);//NAO ACABOU E VAI PRA DIREITA
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
bool AVLTree<thing>::Remove(int k, thing *Dat)
{
    return !AVLTree::RemoveR(k,&Root,Dat);
}

template<class thing>
bool AVLTree<thing>::RemoveR(int k, Node<thing> **R, thing *Dat)
{
    if(!(*R))//nao achou
        return false;
    if(k < ((*R)->D).Key)//vai para a esquerda
    {
        if( AVLTree::RemoveR(k, &((*R)->Left), Dat))
        {//A altura da sub à esquerda diminuiu
            if((*R)->fb==0)
            {
                (*R)->fb=+1;
                return false;
            }
            if((*R)->fb==-1)
            {
                (*R)->fb=0;
                return true;
            }
            //era +1 e iria para +2, mas não vai
            // verificar se a rotação é simples ou dupla
            if(((*R)->Right)->fb==+1)
            {//Rotação Simples à esquerda
                AVLTree::RSE(R);
                return true;
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
    if(k > ((*R)->D).Key)//vai para a direita
        return AVLTree::RemoveR(k, &((*R)->Right), Dat);

    //ACHOU!!!!
    //vamos ver se não tem filho à esquerda
    if(!(*R)->Left)
    {
        Node<thing>*Aux = *R;
        *R = Aux->Right;
        *Dat=Node<thing>::DesmontaNode(Aux);
        return true;
    }
    // Ele tem filho à esquerda, vamos ver se não tem filho à direita
    if(!(*R)->Right)
    {
        Node<thing>*Aux = *R;
        *R = Aux->Left;
        *Dat=Node<thing>::DesmontaNode(Aux);
        return true;
    }
    //Ele tem dois filhos
    // escolhemos trabalhar com o antecessor
    // maior elemento da subárvore à esquerda
    Node<thing>*Aux = AVLTree::Maximus((*R)->Left);
    swap((*R)->D, Aux->D);
    if(AVLTree::RemoveR(k, &((*R)->Left), Dat))
    {
        if((*R)->fb==0)
        {
            (*R)->fb=+1;
            return false;
        }
        if((*R)->fb==-1)
        {
            (*R)->fb=0;
            return true;
        }
        //era +1 e iria para +2, mas não vai
        // verificar se a rotação é simples ou dupla
        if(((*R)->Right)->fb==+1)
        {//Rotação Simples à esquerda
            AVLTree::RSE(R);
            return true;
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
    b->left = c->Right;
    a->Right = c->Left;
    c->Right = b;
    c->Left = a;
    *R = c;
    if(c->fb == 1)
    {
        b->fb=0;
        a->fb=-1;
    }
    else
    {
        if(c->fb == -1)
        {
            b->fb=+1;
            a->fb=0;
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
            a->fb=+1;
        }
        else
        {//fb(c) = 0
            b->fb=a->fb=0;
        }
    }
    c->fb=0;
}

#endif // AVLTREE_H
