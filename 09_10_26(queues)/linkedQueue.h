#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "queueADT.h"
#include "node.h"
#include <stdexcept>
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

template <class t>
void LinkedQueue<t>::enqueue(const t &queueElement)
{
    Node<t> *newNode;
    newNode = new Node(queueElement);
    if (this->isEmptyQueue())
    {
        this->queueFront = newNode;
        this->queueRear = newNode;
    }
    else
    {
        this->queueRear->link = newNode; // put the new item on teh end of the list
        this->queueRear = newNode;       // move tail to the new last node
    }
}

template <class t>
t LinkedQueue<t>::dequeue()
{
    if (isEmptyQueue())
    {
        throw std::out_of_range("Cannot delete from an empty queue.");
    }
    Node<t> *temp;
    temp = queueFront;
    queueFront = queueFront->link;
    t copy(temp->data);
    delete temp;
    return copy;
}

template <class t>
void LinkedQueue<t>::copyQueue(const LinkedQueue<t> &queueToCopy)
{
    Node<t> *newNode;
    Node<t> *current;
    if (!isEmptyQueue())
    {
        initializeQueue();
    }
    if (queueToCopy.isEmptyQueue())
    {
        queueFront = nullptr;
        queueRear = nullptr;
    }
    else
    {
        current = queueToCopy.queueFront;
        queueFront = new Node<t>(current->data);
        queueRear = queueFront;
        current = current->link;
        while (current != nullptr)
        {
            newNode = new Node<t>(current->data);
            queueRear->link = newNode;
            queueRear = newNode;
            current = current->link;
        }
    }
}

template <class t>
LinkedQueue<t>::LinkedQueue()
{
    queueFront = nullptr;
    queueRear = nullptr;
}

template <class t>
LinkedQueue<t>::LinkedQueue(const LinkedQueue<t> &queueToCopy)
{
    queueRear = nullptr;
    queueFront = nullptr;
    copyQueue(queueToCopy);
}

template <class t>
const LinkedQueue<t> &LinkedQueue<t>::operator=(const LinkedQueue<t> &queueToCopy)
{
    if (this != &queueToCopy)
    {
        copyQueue(queueToCopy);
    }
    return *this;
}

template <class t>
LinkedQueue<t>::~LinkedQueue()
{
    initializeQueue();
}

template <class t>
bool LinkedQueue<t>::isEmptyQueue() const
{
    return queueFront == nullptr;
}

template <class t>
bool LinkedQueue<t>::isFullQueue() const
{
    return false;
}

template <class t>
void LinkedQueue<t>::initializeQueue()
{
    if (!isEmptyQueue())
    {
        Node<t> *temp;
        while (this->queueFront != nullptr)
        {
            temp = queueFront;
            queueFront = queueFront->link;
            delete temp;
        }
        queueRear = nullptr;
    }
}

template <class t>
t LinkedQueue<t>::front() const
{
    if (isEmptyQueue())
    {
        throw std::out_of_range("Cannot get the first item of an empty queue.");
    }
    return queueFront->data;
}

template <class t>
t LinkedQueue<t>::back() const
{
    if (isEmptyQueue())
    {
        throw std::out_of_range("Cannot get the last item of an empty queue.");
    }
    return queueRear->data;
}
#endif