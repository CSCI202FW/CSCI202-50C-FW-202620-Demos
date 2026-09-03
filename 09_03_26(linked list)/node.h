#ifndef NODE_H
#define NODE_H
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