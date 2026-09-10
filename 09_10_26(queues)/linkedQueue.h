#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "queueADT.h"
#include "node.h"
template <class t>
class LinkedQueue : public QueueADT<t>
{
public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<t> &queueToCopy);
    const LinkedQueue<t> &operator=(const LinkedQueue<t> &queueToCopy);
    ~LinkedQueue();
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    t front() const;
    t back() const;
    void enqueue(const t &queueElement);
    t dequeue();

private:
    Node<t> *queueFront;
    Node<t> *queueRear;
    void copyQueue(const LinkedQueue<t> &queueToCopy);
};
#endif