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