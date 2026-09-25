#include "binarySearchTree.h"
#include "AVLTree.h"
#include <iostream>
#include <random>
#include <chrono>

// M05 part b lab
// create the node for a b-tree
// from the slide show
// Each node has m-1 elements
// And m pointers to child trees

int main()
{
    BinarySearchTree<int> tree3;
    AVLTree<int> tree;
    AVLTree<int> tree2;
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(5, 100);
    std::default_random_engine generator(rd()); // alternatively use code in block below
    /*auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
      std::default_random_engine generator(static_cast<unsigned int>(seed));
    */
    int num = distribution(generator);
    for (int i = 0; i < num; i++)
    {
        try
        {
            int x = distribution(generator);
            tree.insert(x);
            tree2.insert(x);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << tree.inorderTraversal() << std::endl;
    std::cout << tree.preorderTraversal() << std::endl;
    std::cout << tree.postorderTraversal() << std::endl;
    std::cout << "Generated num: " << num << std::endl;
    std::cout << "Tree Height: " << tree.treeHeight() << std::endl;
    std::cout << "Tree Nodes: " << tree.treeNodeCount() << std::endl;
    std::cout << "Tree Leaves: " << tree.treeLeavesCount() << std::endl;
    auto it = tree2.begin();
    int del = *it;
    tree.deleteNode(del);
    std::cout << tree.inorderTraversal() << std::endl;
    return 0;
}
