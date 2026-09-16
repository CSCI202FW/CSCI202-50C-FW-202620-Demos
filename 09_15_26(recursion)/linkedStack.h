#ifndef LSTACK_H
#define LSTACK_H
#include "stackADT.h"
#include "node.h"
#include <stdexcept>

template <class t>
class LinkedStack : public StackADT<t>
{
public:
    LinkedStack(int);
    LinkedStack(const LinkedStack<t> &);
    const LinkedStack<t> &operator=(const LinkedStack<t> &);
    void initializeStack();
    bool isFullStack() const;
    bool isEmptyStack() const;
    void push(const t &);
    t peek() const;
    t &top();
    t pop();
    ~LinkedStack();
    bool operator>(const LinkedStack<t> &);
    bool operator<(const LinkedStack<t> &);
    int getCount() const;

private:
    void copyStack(const LinkedStack<t> &);
    Node<t> *stackTop;
    int count;
    int stackNum;
};

template <class t>
LinkedStack<t>::LinkedStack(int num)
{
    stackTop = nullptr;
    count = 0;
    stackNum = num;
}

template <class t>
LinkedStack<t>::LinkedStack(const LinkedStack<t> &stackToCopy)
{
    stackTop = nullptr;
    count = 0;
    copyStack(stackToCopy);
}

template <class t>
const LinkedStack<t> &LinkedStack<t>::operator=(const LinkedStack<t> &stackToCopy)
{
    if (this != &stackToCopy)
    {
        copyStack(stackToCopy);
    }
    return *this;
}

template <class t>
void LinkedStack<t>::initializeStack()
{
    Node<t> *temp;
    while (stackTop != nullptr)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    count = 0;
}

template <class t>
bool LinkedStack<t>::isFullStack() const
{
    return false;
}

template <class t>
bool LinkedStack<t>::isEmptyStack() const
{
    return stackTop == nullptr;
}

template <class t>
void LinkedStack<t>::push(const t &newItem)
{
    Node<t> *newNode;
    newNode = new Node<t>(newItem);
    newNode->link = stackTop;
    stackTop = newNode;
    count++;
}

template <class t>
t LinkedStack<t>::peek() const
{
    if (isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return stackTop->data;
}

template <class t>
t &LinkedStack<t>::top()
{
    if (isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return stackTop->data;
}

template <class t>
t LinkedStack<t>::pop()
{
    if (isEmptyStack())
    {
        throw std::underflow_error("Stack underflow. Cannot remove from an empty stack.");
    }
    t copy = stackTop->data;
    Node<t> *temp = stackTop;
    stackTop = stackTop->link;
    delete temp;
    count--;
    return copy;
}

template <class t>
LinkedStack<t>::~LinkedStack()
{
    initializeStack();
}

template <class t>
void LinkedStack<t>::copyStack(const LinkedStack<t> &stackToCopy)
{
    Node<t> *newNode;
    Node<t> *current;
    Node<t> *last;
    this->stackNum = stackToCopy.stackNum;
    if (!isEmptyStack())
    {
        initializeStack();
    }
    if (stackToCopy.isEmptyStack())
    {
        this->stackTop = nullptr;
        count = 0;
    }
    else
    {
        current = stackToCopy.stackTop;
        this->stackTop = new Node<t>(current->data);
        last = this->stackTop;
        current = current->link;
        while (current != nullptr)
        {
            newNode = new Node<t>(current->data);
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
        this->count = stackToCopy.count;
    }
}

template <class t>
bool LinkedStack<t>::operator>(const LinkedStack<t> &other)
{
    return this->stackNum > other.stackNum;
}
template <class t>
bool LinkedStack<t>::operator<(const LinkedStack<t> &other)
{
    return this->stackNum < other.stackNum;
}
template <class t>
int LinkedStack<t>::getCount() const
{
    return count;
}
#endif