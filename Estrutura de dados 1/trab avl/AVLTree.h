//
// Created by Alexssander Pereira on 29/05/2020.
//

#ifndef TREE_AVLTREE_H
#define TREE_AVLTREE_H
#include "Node.h"
template <class thing>
class AVLTree{
    private:
        Node<thing> *Root;
        static bool InsertR(Node<thing>** R,Node<thing>* Aux);//ok
        static bool SearchR(int x,int y,Node<thing>* P,thing *Dat);//ok
        static bool RemoveAVL(int x,int y,Node<thing>** R,thing* Dat);
        static Node<thing>* Maximus(Node<thing>* R);//ok
        static void RSE(Node<thing>** R);//ok
        static void RSD(Node<thing>** R);//ok
        static void RDD(Node<thing>** R);//ok
        static void RDE(Node<thing>** R);//ok
        static bool ABRE(Node<thing>**R);//Avaliador de Balanceamento Remove Esquerda
        static bool ABRD(Node<thing>**R);//Avaliador de Balanceamento Remove Direita
    public:
        AVLTree();
        bool Insert(thing *Dat);//ok
        bool Search(int x,int y,thing * Dat);//ok
        bool Remove(int x,int y,thing* Dat);//ok
};

template<class thing>
AVLTree<thing>::AVLTree() {
    Root = nullptr;
}

template<class thing>
bool AVLTree<thing>::InsertR(Node<thing> **R, Node<thing> *Aux) {
    if(!*R){//xuxa la
        *R = Aux;
        Aux->fb=0;
        return true;
    }
    if((Aux->D) < ((*R)->D)) {//vai inserir á esquerda
        if (AVLTree<thing>::InsertR(&((*R)->Left), Aux)) {//A subarvore da esquerda cresceu
            if ((*R)->fb == 1) {
                (*R)->fb = 0;
                return false;
            }
            if ((*R)->fb == 0) {
                (*R)->fb = -1;
                return true;
            }
            //fb é -1 fudeu iria para -2
            //avaliar qual tipo de rotação a ser feita
            if (((*R)->Left)->fb == -1) {//rotação simples à direita
                AVLTree::RSD(R);
                return false;
            }
            //fb do filho à esquerda é +1
            AVLTree::RDD(R);
            return false;
        }
        return false;
    }
    //vai inserir á direita
    if(AVLTree<thing>::InsertR(&((*R)->Right),Aux)){//A subarvore da direita cresceu
        if((*R)->fb == -1){
            (*R)->fb = 0;
            return false;
        }
        if((*R)->fb == 0){
            (*R)->fb = 1;
            return true;
        }
        //fb é +1 fudeu iria para +2
        //avaliar qual tipo de rotação a ser feita
        if(((*R)->Right)->fb == 1){//rotação simples à esquerda
            AVLTree::RSE(R);
            return false;
        }
        //fb do filho à direita e -1
        AVLTree::RDE(R);
        return false;
    }
    return false;
}

template<class thing>
bool AVLTree<thing>::Insert(thing *Dat) {
    Node<thing> *Aux = Node<thing>::montaNode(Dat);
    if(!Aux)
        return false;
    AVLTree::InsertR(&Root,Aux);
    return true;
}

template<class thing>
bool AVLTree<thing>::Search(int x, int y, thing *Dat) {
    return AVLTree<thing>::SearchR(x,y,Root,Dat);
}

template<class thing>
bool AVLTree<thing>::SearchR(int x, int y, Node<thing> *P, thing *Dat) {
    if(!P)//Acabou e não achou
        return false;
    if(x == P->D.x && y == P->D.y){//Achou
        *Dat = P->D;
        return true;
    }
    if(y < P->D.y)//Nao acabou e vai pra esquerda
        return AVLTree<thing>::SearchR(x,y,P->Left,Dat);
    if(y == P->D.y)
        if(x < P->D.x)
            return AVLTree<thing>::SearchR(x,y,P->Left,Dat);
        return AVLTree<thing>::SearchR(x,y,P->Right,Dat);
     return AVLTree<thing>::SearchR(x,y,P->Right,Dat);//Nao acabou e vai pra direita
}

template<class thing>
bool AVLTree<thing>::RemoveAVL(int x, int y, Node<thing> **R, thing *Dat) {
    if(!(*R)){//não achou
        Dat = nullptr;
        return false;
    }
    if(y < ((*R)->D).y){//vai para a esquerda
        if(AVLTree<thing>::RemoveAVL(x,y,&((*R)->Left),Dat)){//A altura da sub à esquerda diminuiu
            return AVLTree<thing>::ABRE(R);
        }
        return false;
    }
    if(y > ((*R)->D).y){//vai para a direita
        if(AVLTree<thing>::RemoveAVL(x,&((*R)->Right)),Dat){//A altura da sub à direita diminui
            return AVLTree<thing>::ABRD(R);
        }
        return false;
    }
    if(x < ((*R)->D).x){//vai para a esquerda
        if(AVLTree<thing>::RemoveAVL(x,y,&((*R)->Left),Dat)){//A altura da sub à esquerda diminuiu
            return AVLTree<thing>::ABRE(R);
        }
        return false;
    }
    if(x > ((*R)->D).x){//vai para a direita
        if(AVLTree<thing>::RemoveAVL(x,y,&((*R)->Right)),Dat){//A altura da sub à direita diminui
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
    swap((*R)->D,Aux->D);
    if(AVLTree::RemoveAVL(x,&((*R)->Left),Dat)){
        if((*R)->fb==0){
            (*R)->fb=1;
            return false;
        }
        if((*R)->fb==-1){
            (*R)->fb = 0;
            return true;
        }
        //era +1 e iria para +2,mas não vai
        //verificar se a rotação e simples ou dupla
        if(((*R)->Right)->fb==1){//Rotação simples à esquerda
            AVLTree::RSE(R);
            return false;
        }
        if(((*R)->Right)->fb==0){//Rotação Simples à esquerda
            AVLTree::RSE(R);
            return false;
        }
        //filho à tem fb = -1 (fb(b)=-1)
        AVLTree::RDE(R);
        return true;
    }
    return false;
}

template <class thing>
bool AVLTree<thing>::Remove(int x,int y,thing *Dat){
    AVLTree::RemoveAVL(x,y,&Root,Dat);
    if(!Dat){//não achou
        return false;
    }
    return true;
}

template<class thing>
Node<thing> *AVLTree<thing>::Maximus(Node<thing> *R) {
    if(!R)
        return nullptr;
    if(!R->Right)
        return R;
    return AVLTree::Maximus(R->Right);
}

template<class thing>
void AVLTree<thing>::RSE(Node<thing> **R) {
    Node<thing>* a = *R;
    Node<thing>* b = a->Right;
    a->Right = b->Left;
    b->Left = a;
    *R = b;
    if(b->fb==1){
        a->fb = b->fb = 0;
    }else{
        a->fb = 1;
        b->fb = -1;
    }
}

template<class thing>
void AVLTree<thing>::RSD(Node<thing> **R) {
    Node<thing>* a = *R;
    Node<thing>* b = a->Left;
    a->Left = b->Right;
    b->Right = a;
    *R = b;
    if(b->fb==-1){
        a->fb = b->fb = 0;
    }else{//b->fb = 0
        a->fb = -1;
        b->fb = 1;
    }
}

template<class thing>
void AVLTree<thing>::RDD(Node<thing> **R) {
    Node<thing>* a = *R;
    Node<thing>* b = a->Left;
    Node<thing>* c = b->Right;
    b->Right = c->Left;
    a->Left = c->Right;
    c->Left = b;
    c->Right = a;
    *R = c;
    if(c->fb == 1){
        b->fb=-1;
        a->fb=0;
    } else {
        if(c->fb == -1){
            b->fb = 0;
            a->fb = 1;
        } else {//fb(c) = 0​
            b->fb = a->fb = 0;
        }
    }
    c->fb = 0;
}

template<class thing>
void AVLTree<thing>::RDE(Node<thing> **R) {
    Node<thing>* a = *R;
    Node<thing>* b = a->Right;
    Node<thing>* c = b->Left;
    b->Left = c->Right;
    a->Right = c->Left;
    c->Right = b;
    c->Left = a;
    *R = c;
    if(c->fb == -1){
        b->fb = 1;
        a->fb = 0;
    } else {
        if(c->fb == 1){
            b->fb = 0;
            a->fb = -1;
        } else {//fb(c) = 0
            b->fb = a->fb = 0;
        }
    }
    c->fb = 0;
}

template <class thing>
bool AVLTree<thing>::ABRE(Node<thing>**R){
    if((*R)->fb==0){
        (*R)->fb = 1;
        return false;
    }
    if((*R)->fb==-1){
        (*R)->fb=0;
        return true;
    }
    //era +1 e iria para +2, mais não vai
    //verificar se a rotação é simples ou dupla
    if(((*R)->Right)->fb==1){//Rotação simples à esquerda
        AVLTree::RSE(R);
        return true;
    }
    if(((*R)->Right)->fb==0){//Rotação simles à esquerda
        AVLTree::RSE(R);
        return false;
    }
    //filho à tem fb = -1 (fb(b)=-1)
    AVLTree::RDE(R);
    return true;
}

template <class thing>
bool AVLTree<thing>::ABRD(Node<thing>**R){
    if((*R)->fb==0){
        (*R)->fb = -1;
        return false;
    }
    if((*R)->fb==1){
        (*R)->fb = 0;
        return true;
    }
    //era +1 e iria para +2,mais não vai
    //verificar se a rotação é simples ou dupla
    if(((*R)->Left)->fb==-1){//rotação simples à direita
        AVLTree::RSD(R);
        return true;
    }
    if(((*R)->Right)->fb==0){//rotação simples à direita
        AVLTree::RSD(R);
        return false;
    }
    //filho à tem fb = 1 (fb(b)= 1)
    AVLTree::RDD(R);
    return true;
}

#endif //TREE_AVLTREE_H
