#ifndef USTACK_H
#define USTACK_H
#include "stackADT.h"
#include "unorderedLinkedList.h"
template <class t>
class ULinkedStack : public StackADT<t>
{
public:
    ULinkedStack();

    void initializeStack();
    bool isFullStack() const;
    bool isEmptyStack() const;
    void push(const t &);
    t peek() const;
    t &top();
    t pop();

private:
    UnorderedLinkedList<t> list;
};

template <class t>
ULinkedStack<t>::ULinkedStack() : list(UnorderedLinkedList::directionType::BACKWARD)
{
}

template <class t>
void ULinkedStack<t>::initializeStack()
{
    list.destroyList();
}

template <class t>
bool ULinkedStack<t>::isFullStack() const
{
    return false;
}

template <class t>
bool ULinkedStack<t>::isEmptyStack() const
{
    return list.isEmptyList();
}

template <class t>
void ULinkedStack<t>::push(const t &newItem)
{
    list.insert(newItem);
}

template <class t>
t ULinkedStack<t>::peek() const
{
    return list.front;
}

template <class t>
t &ULinkedStack<t>::top()
{
    return list.front();
}

template <class t>
t ULinkedStack<t>::pop()
{
    t copy = list.front;
    deleteNode(copy);
    return copy;
}
#endif