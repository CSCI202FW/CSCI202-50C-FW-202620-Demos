#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
#include <unordered_set>
#include <thread>
#include "unorderedLinkedList.h"
#include "searchSort.h"
#include "person.h"
#include "block.h"

// M08 lab create a block chain class using your choice of linkedQueue, linkedStack, or unorderedLinkedList
// have a method to add a message
// have a method to go through and verify the blocks.

const int NUM_SIZE = 10000;

void setup();
int compareInt(int &first, int &second);
int compareByName(Person *&, Person *&);
int compareByAge(Person *&, Person *&);
int compareByHeight(Person *&, Person *&);
void printPeopleList(Person **, int);
void startBubbleSort(UnorderedLinkedList<int> &list);
void startSelectionSort(UnorderedLinkedList<int> &list);
void startInsertionSort(std::vector<int> &list);
void startQuickSort(std::vector<int> &list);
void startMergeSortVector(std::vector<int> &list);
void startMergeSortLL(UnorderedLinkedList<int> &list);
void startSeqSearch(UnorderedLinkedList<int> &list, int search);
void startBinarySearch(std::vector<int> &list, int search);

int main()
{
    unsigned char hash[SHA256_DIGEST_LENGTH] = {0};
    Block b(0, "Start message", hash);
    setup();
    UnorderedLinkedList<int> list;
    UnorderedLinkedList<int> blist;
    UnorderedLinkedList<int> slist;
    UnorderedLinkedList<int> mlist;
    std::vector<int> iList;
    std::vector<int> qList;
    std::vector<int> mList;
    // int iList[1000000];
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(1, 2000000);

    std::ifstream in("input.txt");
    int i = 0;
    while (!in.eof())
    {
        int x;
        in >> x;
        list.insert(x);
        iList.push_back(x);
    }
    blist = list;
    slist = list;
    mlist = list;
    qList = iList;
    mList = iList;
    int searchTerm = distribution(generator);
    int count = 0;

    // std::cout << "Start merge sort." << std::endl;
    //   bubbleSort(blist);
    //   selectionSort(slist);
    //  insertionSort(iList, 1000000);
    //  quickSort(iList, 0, 999999, compareInt);
    //  mergeSort(iList, 0, 999999);
    // blist.mergeSort();
    // std::cout << "Merge Sort Finished" << std::endl;

    std::thread bubble(startBubbleSort, std::ref(blist));
    std::thread selection(startSelectionSort, std::ref(slist));
    std::thread insertion(startInsertionSort, std::ref(iList));
    std::thread quick(startQuickSort, std::ref(qList));
    std::thread mergeV(startMergeSortVector, std::ref(mList));
    std::thread mergeL(startMergeSortLL, std::ref(mlist));
    std::thread ssearch(startSeqSearch, std::ref(list), searchTerm);
    quick.join();
    std::thread bsearch(startBinarySearch, std::ref(qList), searchTerm);
    bubble.join();
    selection.join();
    insertion.join();
    ssearch.join();
    mergeV.join();
    mergeL.join();
    bsearch.join();

    /*  Person **people = new Person *[10];
     people[0] = new Person("Brian Busch", 32, 168);
     people[1] = new Person("Amber Hammond", 49, 155);
     people[2] = new Person("Jason Buckles", 28, 182);
     people[3] = new Person("Richard Asbury", 42, 182);
     people[4] = new Person("Rebecca Rivera", 69, 174);
     people[5] = new Person("Nikia Shurtleff", 51, 163);
     people[6] = new Person("Derek Hancock", 29, 168);
     people[7] = new Person("Elias Gomez", 47, 184);
     people[8] = new Person("Timothy Michael", 49, 170);
     people[9] = new Person("Bernard McElroy", 60, 183);
     quickSort(people, 0, 9, compareByName);
     std::cout << "Sorted by name" << std::endl;
     printPeopleList(people, 10);
     std::cout << std::endl;
     quickSort(people, 0, 9, compareByAge);
     std::cout << "Sorted by age" << std::endl;
     printPeopleList(people, 10);
     std::cout << std::endl;
     quickSort(people, 0, 9, compareByHeight);
     std::cout << "Sorted by Height" << std::endl;
     printPeopleList(people, 10);
     std::cout << std::endl; */
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
    while (nums.size() != NUM_SIZE)
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
int compareByName(Person *&person1, Person *&person2)
{
    if (person1->getName() > person2->getName())
    {
        return 1;
    }
    else if (person1->getName() == person2->getName())
    {
        return 0;
    }
    else if (person1->getName() < person2->getName())
    {
        return -1;
    }
    return 0;
}

int compareByAge(Person *&person1, Person *&person2)
{
    if (person1->getAge() > person2->getAge())
    {
        return 1;
    }
    else if (person1->getAge() == person2->getAge())
    {
        return 0;
    }
    else if (person1->getAge() < person2->getAge())
    {
        return -1;
    }
    return 0;
}

int compareByHeight(Person *&person1, Person *&person2)
{
    if (person1->getHeight() > person2->getHeight())
    {
        return 1;
    }
    else if (person1->getHeight() == person2->getHeight())
    {
        return 0;
    }
    else if (person1->getHeight() < person2->getHeight())
    {
        return -1;
    }
    return 0;
}

void printPeopleList(Person **p, int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << *p[i] << std::endl;
    }
}

void startBubbleSort(UnorderedLinkedList<int> &list)
{
    std::cout << "Start Bubble Sort" << std::endl;
    bubbleSort(list);
    std::cout << "Bubble Sort Finished" << std::endl;
}

void startSelectionSort(UnorderedLinkedList<int> &list)
{
    std::cout << "Start Selection Sort" << std::endl;
    selectionSort(list);
    std::cout << "Selection Sort Finished" << std::endl;
}

void startInsertionSort(std::vector<int> &list)
{
    std::cout << "Start Insertion Sort" << std::endl;
    insertionSort(list, list.size());
    std::cout << "Insertion Sort Finished" << std::endl;
}

void startQuickSort(std::vector<int> &list)
{
    std::cout << "Start Quick Sort" << std::endl;
    quickSort(list, 0, list.size() - 1, compareInt);
    std::cout << "Quick Sort Finished" << std::endl;
}

void startMergeSortVector(std::vector<int> &list)
{
    std::cout << "Start Merge Sort Vector" << std::endl;
    mergeSort(list, 0, list.size() - 1);
    std::cout << "Merge Vector Sort Finished" << std::endl;
}

void startMergeSortLL(UnorderedLinkedList<int> &list)
{
    std::cout << "Start Merge Sort Linked List" << std::endl;
    list.mergeSort();
    std::cout << "Merge Sort Linked List Finished" << std::endl;
}

void startSeqSearch(UnorderedLinkedList<int> &list, int search)
{
    std::cout << "Start sequential search for " << search << std::endl;
    int count = 0;
    LinkedListIterator<int> it = seqSearch(list, search, count);
    if (it == list.end())
    {
        std::cout << "The item was not found in the list" << std::endl;
    }
    else
    {
        std::cout << *it << " is in the list on line " << count << std::endl;
    }
}

void startBinarySearch(std::vector<int> &list, int search)
{
    std::cout << "Start binary search for " << search << std::endl;
    int comparisons = 0;
    int index = binarySearch(list, list.size(), search, comparisons, 0, list.size() - 1);
    std::cout << search << " found at index " << index << " in " << comparisons << " comparisons." << std::endl;
}
