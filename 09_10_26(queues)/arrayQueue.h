#ifndef ARRAYQ_H
#define ARRAYQ_H
#include "queueADT.h"
template <class t>
class ArrayQueue : QueueADT<t>
{
public:
    ArrayQueue(int = QueueADT<t>::DEFAULT_QUEUE_SIZE);
    ArrayQueue(const ArrayQueue<t> &queueToCopy);
    const ArrayQueue<t> &operator=(const ArrayQueue<t> &queueToCopy);
    ~ArrayQueue();
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    t front() const;
    t back() const;
    void enqueue(const t &queueElement);
    t dequeue();

private:
    t **list;
    int maxQueueSize;
    int queueFront;
    int queueRear;
    int count;
    void copyQueue(const ArrayQueue<t> &queueToCopy);
};
#endif