#ifndef LINKEDI_H
#define LINKEDI_H
#include "node.h"
#include <stdexcept>

template <class t>
class LinkedListIterator
{
public:
    LinkedListIterator();
    LinkedListIterator(Node<t> *);
    t operator*();
    LinkedListIterator<t> operator++();
    bool operator==(const LinkedListIterator<t> &) const;
    bool operator!=(const LinkedListIterator<t> &) const;

private:
    Node<t> *current;
};

template <class t>
LinkedListIterator<t>::LinkedListIterator()
{
    current = nullptr;
}

template <class t>
LinkedListIterator<t>::LinkedListIterator(Node<t> *n)
{
    current = n;
}

template <class t>
t LinkedListIterator<t>::operator*()
{
    if (current == nullptr)
        throw std::out_of_range("Cannot retrieve data from empty node.");
    return current.data;
}

template <class t>
LinkedListIterator<t> LinkedListIterator<t>::operator++()
{
    if (current != nullptr)
    {
        current = current->link;
    }
    return *this;
}

template <class t>
bool LinkedListIterator<t>::operator==(const LinkedListIterator<t> &otherIter) const
{
    return this->current == otherIter.current;
}

template <class t>
bool LinkedListIterator<t>::operator!=(const LinkedListIterator<t> &otherIter) const
{
    return !(*this == otherIter);
}

#endif