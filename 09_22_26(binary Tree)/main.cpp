#include "binarySearchTree.h"
#include <iostream>
#include <random>
#include <chrono>

// M05 a lab
// ask the ai engine of your choice (don't pay)
// to add a function to binary search tree
// that prints the binary search tree in a tree shape

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
    std::cout << tree.inorderTraversal() << std::endl;

    return 0;
}