#ifndef UNORDERED_H
#define UNORDERED_H
#include <stdexcept>
#include "linkedList.h"

template <class t>
class UnorderedLinkedList : public LinkedList<t>
{
public:
    enum class directionType
    {
        FORWARD,
        BACKWARD
    };
    UnorderedLinkedList(directionType = directionType::FORWARD);
    void insert(const t &newData);
    void deleteNode(const t &deleteItem);
    bool search(const t &searchItem);

private:
    directionType direction;
    void insertFirst(Node<t> *newNode);
    void insertLast(Node<t> *newNode);
};

#endif

template <class t>
inline UnorderedLinkedList<t>::UnorderedLinkedList(directionType d) : direction(d)
{
}

template <class t>
inline void UnorderedLinkedList<t>::insert(const t &newData)
{
    Node<t> *newNode;
    newNode = new Node(newData);
    if (this->isEmptyList())
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else if (direction == directionType::FORWARD)
    {
        insertLast(newNode);
    }
    else
    {
        insertFirst(newNode);
    }
    this->count++;
}

template <class t>
inline void UnorderedLinkedList<t>::deleteNode(const t &deleteItem)
{
    Node<t> *current;
    Node<t> *trailCurrent; // one behind current in the list
    bool found;
    if (this->isEmptyList())
    {
        throw std::out_of_range("Cannot delete from an empty list.");
    }
    if (this->head->data == deleteItem)
    {
        current = this->head;
        this->head = this->head->link; // move head node forward
        if (this->head == nullptr)
        {
            this->tail = nullptr;
        }
    }
    else
    {
        found = false;
        trailCurrent = this->head;
        current = this->head->link;
        while (current != nullptr && !found)
        {
            if (current->data != deleteItem)
            {
                trailCurrent = current;  // move the pointer trailing current ahead by 1
                current = current->link; // move current ahead by 1
            }
            else
            {
                found = true;
            }
        }
        if (found)
        {
            trailCurrent->link = current->link; // remove current from the navigation
            if (this->tail == current)
            {
                this->tail = trailCurrent;
            }
        }
        else
        {
            throw std::out_of_range("Item to be deleted is not found in the list");
        }
    }
    delete current;
    this->count--;
}

template <class t>
inline bool UnorderedLinkedList<t>::search(const t &searchItem)
{
    Node<t> *current;
    bool found = false;
    current = this->head;
    while (current != nullptr && !found)
    {
        if (current->data == searchItem)
        {
            found = true;
        }
        else
        {
            current = current->link;
        }
    }
    return found;
}

template <class t>
inline void UnorderedLinkedList<t>::insertFirst(Node<t> *newNode)
{
    newNode->link = this->head; // put new item on front of list
    this->head = newNode;       // moves the head to the new first node
}

template <class t>
inline void UnorderedLinkedList<t>::insertLast(Node<t> *newNode)
{
    this->tail->link = newNode; // put the new item on teh end of the list
    this->tail = newNode;       // move tail to the new last node
}
