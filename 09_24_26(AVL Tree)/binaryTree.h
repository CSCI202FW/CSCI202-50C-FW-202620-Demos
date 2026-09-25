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
    std::string inorderTraversal() const;
    std::string preorderTraversal() const;
    std::string postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    virtual void insert(const t &insertItem) = 0;
    virtual bool search(const t &searchItem) const = 0;
    virtual void deleteNode(const t &deleteItem) = 0;

protected:
    BinaryNode<t> *root;

private:
    void copyTree(BinaryNode<t> *&myTreeNode, BinaryNode<t> *treeToCopyNode);
    void destroy(BinaryNode<t> *&currentNode);
    void inorder(BinaryNode<t> *currentNode, std::ostringstream &out) const;
    void preorder(BinaryNode<t> *currentNode, std::ostringstream &out) const;
    void postorder(BinaryNode<t> *currentNode, std::ostringstream &out) const;
    int nodeCount(BinaryNode<t> *currentNode) const;
    int height(BinaryNode<t> *currentNode) const;
    int leavesCount(BinaryNode<t> *currentNode) const;
    int max(int x, int y) const;
};

template <class t>
BinaryTree<t>::BinaryTree()
{
    root = nullptr;
}
template <class t>
BinaryTree<t>::BinaryTree(const BinaryTree<t> &treeToCopy)
{
    root = nullptr;
    copyTree(this->root, treeToCopy.root);
}
template <class t>
const BinaryTree<t> &BinaryTree<t>::operator=(const BinaryTree<t> &treeToCopy)
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
BinaryTree<t>::~BinaryTree()
{
    destroy(this->root);
}
template <class t>
bool BinaryTree<t>::isEmpty() const
{
    return root == nullptr;
}
template <class t>
std::string BinaryTree<t>::inorderTraversal() const
{
    std::ostringstream out;
    inorder(root, out);
    return out.str();
}
template <class t>
std::string BinaryTree<t>::preorderTraversal() const
{
    std::ostringstream out;
    preorder(root, out);
    return out.str();
}
template <class t>
std::string BinaryTree<t>::postorderTraversal() const
{
    std::ostringstream out;
    postorder(root, out);
    return out.str();
}
template <class t>
int BinaryTree<t>::treeHeight() const
{

    return height(this->root);
}
template <class t>
int BinaryTree<t>::treeNodeCount() const
{
    return nodeCount(this->root);
}
template <class t>
int BinaryTree<t>::treeLeavesCount() const
{
    return leavesCount(this->root);
}
template <class t>
void BinaryTree<t>::copyTree(BinaryNode<t> *&myTreeNode, BinaryNode<t> *treeToCopyNode)
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
void BinaryTree<t>::destroy(BinaryNode<t> *&currentNode)
{
    if (currentNode != nullptr)
    {
        destroy(currentNode->lLink);
        destroy(currentNode->rLink);
        delete currentNode;
        currentNode = nullptr;
    }
}
template <class t>
void BinaryTree<t>::inorder(BinaryNode<t> *currentNode, std::ostringstream &out) const
{
    /*  Traverse the left subtree
        Visit the node
        Traverse the right subtree */
    if (currentNode != nullptr)
    {
        inorder(currentNode->lLink, out);
        out << currentNode->data << " "; // visit the node
        inorder(currentNode->rLink, out);
    }
}
template <class t>
void BinaryTree<t>::preorder(BinaryNode<t> *currentNode, std::ostringstream &out) const
{
    /*  Visit the node
       Traverse the left subtree
       Traverse the right subtree */
    if (currentNode != nullptr)
    {
        out << currentNode->data << " "; // visit the node
        preorder(currentNode->lLink, out);
        preorder(currentNode->rLink, out);
    }
}
template <class t>
void BinaryTree<t>::postorder(BinaryNode<t> *currentNode, std::ostringstream &out) const
{
    /*  Traverse the left subtree
        Traverse the right subtree
        Visit the node */
    if (currentNode != nullptr)
    {

        postorder(currentNode->lLink, out);
        postorder(currentNode->rLink, out);
        out << currentNode->data << " "; // visit the node
    }
}
template <class t>
int BinaryTree<t>::nodeCount(BinaryNode<t> *currentNode) const
{
    if (currentNode == nullptr)
    {
        return 0;
    }
    return nodeCount(currentNode->lLink) + nodeCount(currentNode->rLink) + 1;
}
template <class t>
int BinaryTree<t>::height(BinaryNode<t> *currentNode) const
{
    if (currentNode == nullptr)
    {
        return 0;
    }
    return max(height(currentNode->lLink), height(currentNode->rLink)) + 1;
}
template <class t>
int BinaryTree<t>::leavesCount(BinaryNode<t> *currentNode) const
{
    if (currentNode == nullptr)
    {
        return 0;
    }
    if (currentNode->lLink == nullptr && currentNode->rLink == nullptr)
    {
        return 1;
    }
    return leavesCount(currentNode->lLink) + leavesCount(currentNode->rLink);
}
template <class t>
int BinaryTree<t>::max(int x, int y) const
{

    return x >= y ? x : y; // if(x>=y) return x; else return y;
}
#endif