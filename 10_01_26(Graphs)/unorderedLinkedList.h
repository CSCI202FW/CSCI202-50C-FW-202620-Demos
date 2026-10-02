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
    void mergeSort();

private:
    directionType direction;
    void insertFirst(Node<t> *newNode);
    void insertLast(Node<t> *newNode);
    void recMergeSort(Node<t> *&start);
    void divideList(Node<t> *left, Node<t> *&right);
    Node<t> *mergeList(Node<t> *left, Node<t> *right);
};

template <class t>
UnorderedLinkedList<t>::UnorderedLinkedList(directionType d) : direction(d)
{
}

template <class t>
void UnorderedLinkedList<t>::insert(const t &newData)
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
void UnorderedLinkedList<t>::deleteNode(const t &deleteItem)
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
bool UnorderedLinkedList<t>::search(const t &searchItem)
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
void UnorderedLinkedList<t>::insertFirst(Node<t> *newNode)
{
    newNode->link = this->head; // put new item on front of list
    this->head = newNode;       // moves the head to the new first node
}

template <class t>
void UnorderedLinkedList<t>::insertLast(Node<t> *newNode)
{
    this->tail->link = newNode; // put the new item on teh end of the list
    this->tail = newNode;       // move tail to the new last node
}

template <class t>
void UnorderedLinkedList<t>::mergeSort()
{
    recMergeSort(this->head);
    if (this->head == nullptr)
    {
        this->tail = nullptr;
    }
    else
    {
        this->tail = this->head;
        while (this->tail->link != nullptr)
        {
            this->tail = this->tail->link;
        }
    }
}

template <class t>
void UnorderedLinkedList<t>::recMergeSort(Node<t> *&start)
{
    Node<t> *otherStart;
    if (start != nullptr)
    {
        if (start->link != nullptr)
        {
            divideList(start, otherStart);
            recMergeSort(start);
            recMergeSort(otherStart);
            start = mergeList(start, otherStart);
        }
    }
}

template <class t>
void UnorderedLinkedList<t>::divideList(Node<t> *left, Node<t> *&right)
{
    Node<t> *middle;
    Node<t> *current;
    if (left == nullptr || left->link == nullptr)
    {
        right = nullptr;
    }
    else
    {
        middle = left;
        current = left->link;
        if (current != nullptr)
        {
            current = current->link;
        }
        while (current != nullptr)
        {
            middle = middle->link;
            current = current->link;
            if (current != nullptr)
            {
                current = current->link;
            }
        }
        right = middle->link;
        middle->link = nullptr;
    }
}

template <class t>
Node<t> *UnorderedLinkedList<t>::mergeList(Node<t> *left, Node<t> *right)
{
    Node<t> *lastSmall;
    Node<t> *newHead;
    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    if (left->data <= right->data)
    {
        newHead = left;
        left = left->link;
    }
    else
    {
        newHead = right;
        right = right->link;
    }
    lastSmall = newHead;
    while (left != nullptr && right != nullptr)
    {
        if (left->data <= right->data)
        {
            lastSmall->link = left;
            left = left->link;
        }
        else
        {
            lastSmall->link = right;
            right = right->link;
        }
        lastSmall = lastSmall->link;
    }
    if (left == nullptr)
    {
        lastSmall->link = right;
    }
    else
    {
        lastSmall->link = left;
    }
    return newHead;
}
#endif