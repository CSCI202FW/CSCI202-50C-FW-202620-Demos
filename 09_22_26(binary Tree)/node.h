#ifndef NODE_H
#define NODE_H

template <class t>
struct BinaryNode
{
    t data;
    BinaryNode<t> *lLink;
    BinaryNode<t> *rLink;
    BinaryNode(t data);
};

template <class t>
BinaryNode<t>::BinaryNode(t data) : data(data)
{
    rLink = nullptr;
    lLink = nullptr;
}
#endif