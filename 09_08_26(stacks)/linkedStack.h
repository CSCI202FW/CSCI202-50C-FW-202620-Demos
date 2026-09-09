#ifndef LSTACK_H
#define LSTACK_H
#include "stackADT.h"
#include "node.h"

template <class t>
class LinkedStack : public StackADT<t>
{
public:
    LinkedStack();
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

private:
    void copyStack(const LinkedStack<t> &);
    Node<t> *stackTop;
    int count;
};
#endif

template <class t>
inline LinkedStack<t>::LinkedStack()
{
    stackTop = nullptr;
    count = 0;
}

template <class t>
inline LinkedStack<t>::LinkedStack(const LinkedStack<t> &stackToCopy)
{
    stackTop = nullptr;
    count = 0;
    copyStack(stackToCopy);
}

template <class t>
inline const LinkedStack<t> &LinkedStack<t>::operator=(const LinkedStack<t> &stackToCopy)
{
    if (this != &stackToCopy)
    {
        copyStack(stackToCopy);
    }
    return *this;
}

template <class t>
inline void LinkedStack<t>::initializeStack()
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
inline bool LinkedStack<t>::isFullStack() const
{
    return false;
}

template <class t>
inline bool LinkedStack<t>::isEmptyStack() const
{
    return stackTop == nullptr;
}

template <class t>
inline void LinkedStack<t>::push(const t &newItem)
{
    Node<t> *newNode;
    newNode = new Node<t>(newItem);
    newNode->link = stackTop;
    stackTop = newNode;
    count++;
}

template <class t>
inline t LinkedStack<t>::peek() const
{
    if (isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return stackTop->data;
}

template <class t>
inline t &LinkedStack<t>::top()
{
    if (isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return stackTop->data;
}

template <class t>
inline t LinkedStack<t>::pop()
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
inline LinkedStack<t>::~LinkedStack()
{
    initializeStack();
}

template <class t>
inline void LinkedStack<t>::copyStack(const LinkedStack<t> &stackToCopy)
{
    Node<t> *newNode;
    Node<t> *current;
    Node<t> *last;
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
