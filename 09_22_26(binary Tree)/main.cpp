#include "binarySearchTree.h"
#include <iostream>
#include <random>
#include <chrono>

// M05 a lab
// ask the ai engine of your choice (don't pay)
// to add a function to binary search tree
// that prints the binary search tree in a tree shape

void treeTest(BinarySearchTree<int> t);

int main()
{
    BinarySearchTree<int> tree;
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(5, 100);
    std::default_random_engine generator(rd());

    int num = distribution(generator);
    for (int i = 0; i < num; i++)
    {
        try
        {
            tree.insert(distribution(generator));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    treeTest(tree);
    std::cout << tree.inorderTraversal() << std::endl;
    std::cout << tree.preorderTraversal() << std::endl;
    std::cout << tree.postorderTraversal() << std::endl;
    std::cout << "Generated num: " << num << std::endl;
    std::cout << "Tree Height: " << tree.treeHeight() << std::endl;
    std::cout << "Tree Nodes: " << tree.treeNodeCount() << std::endl;
    std::cout << "Tree Leaves: " << tree.treeLeavesCount() << std::endl;

    return 0;
}

void treeTest(BinarySearchTree<int> t)
{
}
