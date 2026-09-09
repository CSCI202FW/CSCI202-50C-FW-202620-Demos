#ifndef VSTACK_H
#define VSTACK_H
#include "stackADT.h"
#include <stdexcept>
#include <vector>

template <class t>
class VectorStack : public StackADT<t>
{
public:
    VectorStack(int = StackADT<t>::DEFAULT_STACK_SIZE);

    void initializeStack();
    bool isFullStack() const;
    bool isEmptyStack() const;
    void push(const t &);
    t peek() const;
    t &top();
    t pop();

private:
    int stackTop;
    std::vector<t> list;
};

template <class t>
VectorStack<t>::VectorStack(int max)
{
    if (max <= 0)
    {
        max = StackADT<t>::DEFAULT_STACK_SIZE;
    }
    list.resize(max);
}
template <class t>
void VectorStack<t>::initializeStack()
{
    stackTop = 0;
}
template <class t>
bool VectorStack<t>::isFullStack() const
{
    return stackTop == list.capacity();
}
template <class t>
bool VectorStack<t>::isEmptyStack() const
{
    return stackTop = 0;
}
template <class t>
void VectorStack<t>::push(const t &newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;
        stackTop++;
    }
    else
    {
        throw std::overflow_error("Stack Overflow. Cannot add to a full stack.")
    }
}
template <class t>
t VectorStack<t>::peek() const
{
    if (isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return list[stackTop - 1];
}
template <class t>
t &VectorStack<t>::top()
{
    if (isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return list[stackTop - 1];
}
template <class t>
t VectorStack<t>::pop()
{
    if (isEmptyStack())
    {
        throw std::underflow_error("Stack underflow. Cannot remove from an empty stack.");
    }
    stackTop--;
    return list[stackTop];
}
#endif