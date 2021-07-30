#ifndef NODE_H
#define NODE_H

template <class Thing>
class Node
{
public:
    Thing D;
    Node* Next;
    Node* Prev;
    Node();
    static Node<Thing>* MontaNode(Thing* Dat);
    static Thing DesmontaNode(Node<Thing>* p);
};

template <class Thing>
Node<Thing>::Node()
{

}

template <class  Thing>
Node<Thing>* Node<Thing>::MontaNode(Thing *Dat)
{
    Node<Thing>* P = new Node<Thing>;
    if(P)
    {
        P->D = *Dat;
        P->Next = P->Prev = nullptr;
    }
    return P;
}

template <class Thing>
Thing Node<Thing>::DesmontaNode(Node<Thing> *P)
{
    Thing x = P->D;
    delete P;
    return x;
}

#endif // NODE_H
