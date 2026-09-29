#ifndef MAP_H
#define MAP_H

#include "pair.h"
#include "AVLTree.h"

template <class k, class v>
class Map
{
public:
    v at(const k &) const;
    v &operator[](const k &);
    class Iterator
    {
    public:
        Iterator(typename AVLTree<Pair<k, v>>::Iterator it);
        Iterator operator++();
        Pair<k, v> operator*();
        bool operator==(const Iterator oth) const;
        bool operator!=(const Iterator oth) const;
        Pair<k, v> *operator->();

    private:
        typename AVLTree<Pair<k, v>>::Iterator it;
    };
    Pair<bool, Iterator> insert(const k &, const v &);
    Iterator begin() { return Iterator(tree.begin()); };
    Iterator end() { return Iterator(tree.end()); };
    v deleteItem(const k &key);
    std::string preorder();

protected:
    AVLTree<Pair<k, v>> tree;
};

template <class k, class v>
v Map<k, v>::at(const k &key) const
{
    Pair<k, v> pairForComp(key);
    typename AVLTree<Pair<k, v>>::Iterator item = tree.find(pairForComp);
    if (item == tree.end())
    {
        throw std::out_of_range("The item is not in the map.");
    }
    return item->getValue();
}

template <class k, class v>
v &Map<k, v>::operator[](const k &key)
{
    Pair<k, v> pairForComp(key);
    typename AVLTree<Pair<k, v>>::Iterator item = tree.find(pairForComp);
    if (item == tree.end())
    {
        item = tree.insertAVL(pairForComp);
    }
    return item->getValue();
}

template <class k, class v>
Pair<bool, typename Map<k, v>::Iterator> Map<k, v>::insert(const k &key, const v &value)
{
    bool insert = true;
    Iterator inst(tree.end());
    Pair<k, v> p(key, value);
    try
    {
        inst = Iterator(tree.insertAVL(p));
    }
    catch (std::invalid_argument e)
    {
        insert = false;
        inst = Iterator(tree.find(p));
    }

    return Pair<bool, Iterator>(insert, inst);
}

template <class k, class v>
v Map<k, v>::deleteItem(const k &key)
{
    Pair<k, v> deleteItem(key);
    auto it = tree.find(deleteItem);
    v cpy = it->getValue();
    tree.deleteNode(deleteItem);
    return cpy;
}

template <class k, class v>
std::string Map<k, v>::preorder()
{
    return tree.preorderTraversal();
}
template <class k, class v>
Map<k, v>::Iterator::Iterator(typename AVLTree<Pair<k, v>>::Iterator it)
{
    this->it = it;
}
template <class k, class v>
Pair<k, v> Map<k, v>::Iterator::operator*()
{
    return *it;
}

template <class k, class v>
Pair<k, v> *Map<k, v>::Iterator::operator->()
{
    return it.operator->();
}
template <class k, class v>
bool Map<k, v>::Iterator::operator==(const Iterator oth) const
{
    return this->it == oth.it;
}
template <class k, class v>
bool Map<k, v>::Iterator::operator!=(const Iterator oth) const
{
    return this->it != oth.it;
}
template <class k, class v>
typename Map<k, v>::Iterator Map<k, v>::Iterator::operator++()
{
    ++it;
    return *this;
}
#endif