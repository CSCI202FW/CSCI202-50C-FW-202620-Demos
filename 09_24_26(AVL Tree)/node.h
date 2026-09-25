#ifndef NODE_H
#define NODE_H

template <class t>
struct BinaryNode
{
    t data;
    BinaryNode<t> *lLink;
    BinaryNode<t> *rLink;
    int bfactor;
    BinaryNode(t data);
};

template <class t>
BinaryNode<t>::BinaryNode(t data) : data(data)
{
    rLink = nullptr;
    lLink = nullptr;
    bfactor = 0;
}

template <class t>
struct Node
{
    t data;
    Node<t> *link;
    Node(t data, Node<t> *link = nullptr);
};

template <class t>
Node<t>::Node(t data, Node<t> *link) : data(data)
{
    this->link = link;
}

#endif