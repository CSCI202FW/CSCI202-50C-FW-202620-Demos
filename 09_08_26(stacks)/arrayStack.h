#ifndef ASTACK_H
#define ASTACK_H
#include "stackADT.h"

template <class t>
class ArrayStack : public StackADT<t>
{
public:
    ArrayStack(int = StackADT<t>::DEFAULT_STACK_SIZE);
    ArrayStack(const ArrayStack<t> &);
    const ArrayStack<t> &operator=(const ArrayStack<t> &);
    void initializeStack();
    bool isFullStack() const;
    bool isEmptyStack() const;
    void push(const t &);
    t peek() const;
    t &top();
    t pop();
    ~ArrayStack();

private:
    void copyStack(const ArrayStack<t> &);
    int stackTop;
    int maxStackSize;
    t **list;
};

#endif