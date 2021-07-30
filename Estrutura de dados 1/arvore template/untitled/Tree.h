#ifndef TREE_H
#define TREE_H
#include "Node.h"

template <class thing>
class Tree
{
private:
    Node<thing>* Root;
public:
    Tree();
    bool insert(thing* Dat);
    static void InsertR(Node<thing>**P, Node<thing>* Aux);
    bool Search(int k, thing* Dat);
    bool Search2(int k, thing* Dat);
    static bool SearchR(int k, Node<thing>* P, thing* Dat);
    static Node<thing>* Maximus(Node<thing>* R);
    bool Remove(int k, thing* Dat);
    static bool RemoveR(int k, Node<thing>**R, thing* Dat);

};

template<class thing>
Tree<thing>::Tree()
{
    Root=nullptr;
}

template<class thing>
void Tree<thing>::InsertR(Node<thing> **P, Node<thing> *Aux)
{
    if (!*P)
    {//xuxa la
        *P=Aux;
    }
    else
    {
        if ((Aux->D).Key < ((*P)->D).Key)
        {//insere na subarvore a esquerda
            Tree::InsertR(&((*P)->Left),Aux);
        }
        else
        {//insere na subarvore a direita
            Tree::InsertR(&((*P)->Right),Aux);
        }
    }
}

template<class thing>
bool Tree<thing>::insert(thing *Dat)
{
    Node<thing>*Aux=Node<thing>::montaNode(Dat);
    if (!Aux)
        return false;
    Tree<thing>::InsertR(&Root, Aux);
    return true;
}

template<class thing>
bool Tree<thing>::Search(int k, thing *Dat)
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
bool Tree<thing>::Search2(int k, thing *Dat)
{
    return Tree<thing>::SearchR(k,Root,Dat);
}

template<class thing>
bool Tree<thing>::SearchR(int k, Node<thing> *P, thing *Dat)
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
Node<thing> *Tree<thing>::Maximus(Node<thing> *R)
{//BUSCA O ANTECESSOR NO MAXIMO DA DIREITA //R TEM QUE RECEBER O LEFT
    if (!R)
        return nullptr;
    if (!R->Right)
        return R;
    return Tree::Maximus(R->Right);
}

template<class thing>
bool Tree<thing>::Remove(int k, thing *Dat)
{
    return Tree::RemoveR(k,&Root,Dat);
}

template<class thing>
bool Tree<thing>::RemoveR(int k, Node<thing> **R, thing *Dat)
{
    if (!(*R))
        return false;
    if (k < ((*R)->D).Key )//VAI PRA ESQUERDA
        return Tree::RemoveR(k,&((*R)->Left),Dat);
    if (k > ((*R)->D).Key )//VAI PRA DIREITA
        return Tree::RemoveR(k,&((*R)->Right),Dat);
    //ACHOU
    //vamos ver se não tem filho à esquerda
    if(!(*R)->Left)
    {
        Node<thing>* Aux=*R;
        *R=Aux->Right;
        *Dat=Node<thing>::desmontaNode(Aux);
        return true;
    }
    //ELE TEM FILHO A ESQUERDA
    //vamos ver se não tem filho à direita
    if (!(*R)->Right)
    {
        Node<thing>* Aux=*R;
        *R=Aux->Left;
        *Dat=Node<thing>::desmontaNode(Aux);
        return true;
    }
    //Ele tem dois filhos
    //agora tem que usar o antecessor
    //maior elemento da subarvore à esquerda
    Node<thing>* Aux=Tree<thing>::Maximus((*R)->Left);
    swap((*R)->D,Aux->D);//TROCA O D DA RAIZ COM O D DO AUX
    //thing X = Aux->D;
    //Aux->D = (R)->D;
    //(*R)->D = X;
    return Tree<thing>::RemoveR(k, &((*R)->Left), Dat);//MANDA REMOVER
}


#endif // TREE_H
