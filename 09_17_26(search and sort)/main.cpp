#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include "unorderedLinkedList.h"
#include "searchSort.h"

int compareInt(int &first, int &second);

int main()
{
    UnorderedLinkedList<int> list;
    UnorderedLinkedList<int> blist;
    UnorderedLinkedList<int> slist;
    int iList[1000000];

    std::ifstream in("input.txt");
    int i = 0;
    while (!in.eof())
    {
        int x;
        in >> x;
        list.insert(x);
        iList[i++] = x;
    }
    blist = list;
    slist = list;
    int searchTerm = 517717;
    int count = 0;
    LinkedListIterator<int> it = seqSearch(list, searchTerm, count);
    if (it == list.end())
    {
        std::cout << "The item was not found in the list" << std::endl;
    }
    else
    {
        std::cout << *it << " is in the list on line " << count << std::endl;
    }
    std::cout << "Start quick sort." << std::endl;
    //  bubbleSort(blist);
    //  selectionSort(slist);
    // insertionSort(iList, 1000000);
    quickSort(iList, 0, 999999, compareInt);
    std::cout << "quick Sort Finished" << std::endl;
    int comparisons = 0;
    int index = binarySearch(iList, 1000000, searchTerm, comparisons, 0, 999999);
    std::cout << searchTerm << " found at index " << index << " in " << comparisons << " comparisons." << std::endl;
    return 0;
}

void setup()
{
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(1, 2000000);
    std::unordered_set<int> nums;
    std::ofstream out("input.txt");
    while (nums.size() != 1000000)
    {
        nums.insert(distribution(generator));
    }
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        out << *it << std::endl;
    }
}

int compareInt(int &first, int &second)
{
    if (first < second)
    {
        return -1;
    }
    else if (first == second)
    {
        return 0;
    }
    else // first > second
    {
        return 1;
    }
    return 0;
}
