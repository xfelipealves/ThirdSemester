#ifndef NODE_H
#define NODE_H

template <class thing>
class Node
{
private:
    thing D;
    Node* Left;
    Node* Right;
    char fb;//VAI SER USADO SO NA AVL
public:
    Node();
    static Node<thing>* montaNode(thing* Dat);
    static thing desmontaNode(Node<thing>* P);
};

template <class thing>
Node<thing>::Node()
{
    Left=Right=nullptr;
    fb=0;
}
template <class thing>
Node<thing>* Node<thing>::montaNode(thing* Dat)
{
    Node<thing>*P= new Node<thing>;
    if (P)
    {
        P->D=*Dat;
        P->Left=P->Right=nullptr;
        P->fb=0;
    }
    return P;
}
template <class thing>
thing Node<thing>::desmontaNode(Node<thing>* P)
{
    thing x= P->D;
    delete P;
    return x;
}


#endif // NODE_H
