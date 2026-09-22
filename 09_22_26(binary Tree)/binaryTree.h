#ifndef BINARY_H
#define BINARY_H

#include <sstream>
#include "node.h"

template <class t>
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(const BinaryTree<t> &treeToCopy);
    const BinaryTree<t> &operator=(const BinaryTree<t> &treeToCopy);
    ~BinaryTree();
    bool isEmpty() const;

protected:
    BinaryNode *root;

private:
    void copyTree(BinaryNode<t> *&myTreeNode, BinaryNode<t> *treeToCopyNode);
    void destroy(BinaryNode<t> *&currentNode);
};

template <class t>
inline BinaryTree<t>::BinaryTree()
{
    root = nullptr;
}
template <class t>
inline BinaryTree<t>::BinaryTree(const BinaryTree<t> &treeToCopy)
{
    root = nullptr;
    copyTree(this->root, treeToCopy.root);
}
template <class t>
inline const BinaryTree<t> &BinaryTree<t>::operator=(const BinaryTree<t> &treeToCopy)
{
    if (this != &treeToCopy)
    {
        if (!this->isEmpty())
        {
            destroy(this->root);
        }
        copyTree(this->root, treeToCopy.root);
    }
}
template <class t>
inline BinaryTree<t>::~BinaryTree()
{
    destroy(this->root);
}
template <class t>
inline bool BinaryTree<t>::isEmpty() const
{
    return root == nullptr;
}
template <class t>
inline void BinaryTree<t>::copyTree(BinaryNode<t> *&myTreeNode, BinaryNode<t> *treeToCopyNode)
{
    if (treeToCopyNode == nullptr)
    {
        myTreeNode = nullptr;
    }
    else
    {
        myTreeNode = new BinaryNode<t>(treeToCopyNode->data);
        copyTree(myTreeNode->lLink, treeToCopyNode->lLink);
        copyTree(myTreeNode->rLink, treeToCopyNode->rLink);
    }
}
template <class t>
inline void BinaryTree<t>::destroy(BinaryNode<t> *&currentNode)
{
    if (currentNode != nullptr)
    {
        destroy(currentNode->lLink);
        destroy(currentNode->rLink);
        delete currentNode;
        currentNode = nullptr;
    }
}
#endif