#ifndef SEARCH_H
#define SEARCH_H

#include <fstream>
#include "unorderedLinkedList.h"

template <class t>
LinkedListIterator<t> seqSearch(UnorderedLinkedList<t> &list, const t &item, int &count)
{
    count = 0;
    bool found = false;
    LinkedListIterator<t> itRet;
    for (LinkedListIterator<t> it = list.begin(); it != list.end() && !found; ++it)
    {
        count++;
        if (*it == item)
        {
            found = true;
            itRet = it;
        }
    }
    return itRet;
}

//======================== Sort Algorithms ===========================

template <class t>
void bubbleSort(UnorderedLinkedList<t> &list)
{
    for (int iteration = 1; iteration < list.length(); iteration++)
    {
        LinkedListIterator<t> it1;
        for (LinkedListIterator<t> it = it1 = list.begin(); ++it1 != list.end(); ++it)
        {
            if (*it > *it1)
            {
                swap(it, it1);
            }
        }
    }
}
template <class t>
void swap(LinkedListIterator<t> &first, LinkedListIterator<t> &second)
{
    t temp = *first;
    *first = *second;
    *second = temp;
}

#endif