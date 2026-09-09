#ifndef LINKED_H
#define LINKED_H
#include "node.h"
#include "linkedListIterator.h"
#include <iostream>
#include <string>

template <class t>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<t> &listToCopy);
    const LinkedList<t> &operator=(const LinkedList<t> &listToCopy);
    ~LinkedList();
    void destroyList();
    bool isEmptyList() const;
    int length() const;
    t front() const;
    t back() const;
    void print(std::ostream & = std::cout, std::string = " ") const;
    LinkedListIterator<t> begin();
    LinkedListIterator<t> end();
    virtual void insert(const t &newData) = 0;
    virtual void deleteNode(const t &deleteItem) = 0;
    virtual bool search(const t &searchItem) = 0;

protected:
    Node<t> *head;
    Node<t> *tail;
    int count;

private:
    void copyList(const LinkedList<t> &listToCopy);
};

template <class t>
LinkedList<t>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
}

template <class t>
LinkedList<t>::LinkedList(const LinkedList<t> &listToCopy)
{
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
    this->copyList(listToCopy);
}

template <class t>
const LinkedList<t> &LinkedList<t>::operator=(const LinkedList<t> &listToCopy)
{
    if (this != &listToCopy)
    {
        this->copyList(listToCopy);
    }
    return *this;
}

template <class t>
LinkedList<t>::~LinkedList()
{
    this->destroyList();
}

template <class t>
void LinkedList<t>::destroyList()
{
    if (!this->isEmptyList())
    {
        Node<t> *temp;
        while (head != nullptr)
        {
            temp = this->head;
            this->head = this->head->link; // move head forward
            delete temp;
        }
        this->tail = nullptr;
        count = 0;
    }
}

template <class t>
bool LinkedList<t>::isEmptyList() const
{
    return this->head == nullptr || count == 0;
}
template <class t>
int LinkedList<t>::length() const
{
    return count;
}

template <class t>
t LinkedList<t>::front() const
{
    return head.data;
}

template <class t>
t LinkedList<t>::back() const
{
    return tail.data;
}

template <class t>
void LinkedList<t>::print(std::ostream &out, std::string seperator) const
{
    if (!isEmptyList())
    {
        Node<t> *current;
        current = this->head;
        while (current != nullptr)
        {
            out << current->data << seperator;
            current = current->link;
        }
    }
}

template <class t>
void LinkedList<t>::copyList(const LinkedList<t> &listToCopy)
{
    Node<t> *newNode;
    Node<t> *current;
    if (!isEmptyList())
    {
        destroyList();
    }
    if (listToCopy.isEmptyList())
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    else
    {
        // begin the copy
        current = listToCopy.head;
        this->count = listToCopy.count;
        this->head = new Node<t>(listToCopy.head);
        this->tail = this->head;
        current = current->link; // advance current to next node in the list to copy
        while (current != nullptr)
        {
            newNode = new Node<t>(current->data);
            this->tail->link = newNode;
            this->tail = newNode; // move the end of the list
            // this->tail = this->tail->link; same as above
            current = current->link;
        }
    }
}

template <class t>
LinkedListIterator<t> LinkedList<t>::begin()
{
    return LinkedListIterator<t>(this->head);
}

template <class t>
LinkedListIterator<t> LinkedList<t>::end()
{
    return LinkedListIterator<t>();
}
#endif