#ifndef PQUEUE_H
#define PQUEUE_H
#include "linkedQueue.h"
template <class t>
class PriorityQueue : public LinkedQueue<t>
{
public:
    void enqueue(const t &queueElement);
};

template <class t>
inline void PriorityQueue<t>::enqueue(const t &queueElement)
{
    Node<t> *newNode;
    Node<t> *current;
    Node<t> *trailCurrent = nullptr;
    bool found = false;
    newNode = new Node(queueElement);
    if (this->isEmptyQueue())
    {
        this->queueFront = newNode;
        this->queueRear = newNode;
    }
    else
    {
        current = this->queueFront;
        while (current != nullptr && !found)
        {
            if (current->data < queueElement)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == this->queueFront)
        {
            newNode->link = this->queueFront;
            this->queueFront = newNode;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == nullptr)
            {
                this->queueRear = newNode;
            }
        }
    }
}
#endif