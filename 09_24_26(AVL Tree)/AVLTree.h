#ifndef AVLTREE_H
#define AVLTREE_H

#include "binarySearchTree.h"
#include <sstream>
#include <iostream>

template <class t>
class AVLTree : public BinarySearchTree<t>
{
public:
    AVLTree(int (*comp)(const t &, const t &) = cmp);
    void insert(const t &insertItem);

private:
    void insertIntoAVL(BinaryNode<t> *&currentNode, BinaryNode<t> *newNode, bool &isTaller);
    void balanceFromLeft(BinaryNode<t> *&currentNode);
    void balanceFromRight(BinaryNode<t> *&currentNode);
    void rotateToLeft(BinaryNode<t> *&currentNode);
    void rotateToRight(BinaryNode<t> *&currentNode);
};

#endif

template <class t>
inline AVLTree<t>::AVLTree(int (*comp)(const t &, const t &)) : BinarySearchTree(comp)
{
}

template <class t>
inline void AVLTree<t>::insert(const t &insertItem)
{
    BinaryNode<t> *newNode = new BinaryNode(insertItem);
    bool isTaller = false;
    insertIntoAVL(this->root, newNode, isTaller);
}

template <class t>
inline void AVLTree<t>::insertIntoAVL(BinaryNode<t> *&currentNode, BinaryNode<t> *newNode, bool &isTaller)
{
    if (currentNode == nullptr)
    {
        currentNode = newNode;
        isTaller = true;
    }
    else
    {
        int compareValue = this->compare(newNode->data, currentNode->data);
        if (compareValue == 0)
        {
            delete newNode;
            throw std::invalid_argument("No Duplicates Allowed");
        }
        else if (compareValue == -1)
        {
            insertIntoAVL(currentNode->lLink, newNode, isTaller);
            if (isTaller)
            {
                switch (currentNode->bfactor)
                {
                case -1:
                    balanceFromLeft(currentNode); // left high
                    isTaller = false;
                    break;
                case 0:
                    currentNode->bfactor = -1; // equal high
                    isTaller = true;
                    break;
                case 1:
                    currentNode->bfactor = 0; // right high
                    isTaller = false;
                }
            }
        }
        else
        {
            insertIntoAVL(currentNode->rLink, newNode, isTaller);
            if (isTaller)
            {
                switch (currentNode->bfactor)
                {
                case -1:
                    currentNode->bfactor = 0; // left high
                    isTaller = false;
                    break;
                case 0:
                    currentNode->bfactor = 1; // equal high
                    isTaller = true;
                    break;
                case 1:
                    balanceFromRight(currentNode); // right high
                    isTaller = false;
                    break;
                }
            }
        }
    }
}

template <class t>
inline void AVLTree<t>::balanceFromLeft(BinaryNode<t> *&currentNode)
{
    BinaryNode<t> *lChild;
    BinaryNode<t> *lChild_rChild;
    lChild = currentNode->lLink;
    switch (lChild->bfactor)
    {
    case 0:
    case -1:
        currentNode->bfactor = 0;
        lChild->bfactor = 0;
        rotateToRight(currentNode);
        break;
    case 1:
        lChild_rChild = lChild->rLink;
        switch (lChild_rChild->bfactor)
        {
        case -1:
            currentNode->bfactor = 1;
            lChild->bfactor = 0;
            break;
        case 0:
            currentNode->bfactor = 0;
            lChild->bfactor = 0;
            break;
        case 1:
            currentNode->bfactor = 0;
            lChild->bfactor = -1;
            break;
        }
        lChild_rChild->bfactor = 0;
        rotateToLeft(currentNode->lLink);
        rotateToRight(currentNode);
        break;
    }
}

template <class t>
inline void AVLTree<t>::rotateToRight(BinaryNode<t> *&currentNode)
{
    BinaryNode<t> *newRootNode;
    if (currentNode == nullptr || currentNode->lLink == nullptr)
    {
        throw std::out_of_range("Cannot rotate empty node.");
    }
    newRootNode = currentNode->lLink;
    currentNode->lLink = newRootNode->rLink;
    newRootNode->rLink = currentNode;
    currentNode = newRootNode;
}
