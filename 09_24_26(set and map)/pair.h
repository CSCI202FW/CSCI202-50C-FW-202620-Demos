#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template <class k, class v>
class Pair
{
public:
    Pair(const k &key, const v &value);
    Pair(const k &key);
    v &getValue();
    k getKey() const;
    void setValue(const v &value);
    bool operator>(const Pair<k, v> &oth) const;
    bool operator>=(const Pair<k, v> &oth) const;
    bool operator<(const Pair<k, v> &oth) const;
    bool operator<=(const Pair<k, v> &oth) const;
    bool operator==(const Pair<k, v> &oth) const;
    bool operator!=(const Pair<k, v> &oth) const;
    bool operator>(const k &key) const;
    bool operator>=(const k &key) const;
    bool operator<(const k &key) const;
    bool operator<=(const k &key) const;
    bool operator==(const k &key) const;
    bool operator!=(const k &key) const;
    friend std::ostream &operator<<(std::ostream &out, Pair<k, v> p)
    {
        out << p.key;
        return out;
    };

private:
    k key;
    v value;
};

template <class k, class v>
Pair<k, v>::Pair(const k &key, const v &value) : key(key), value(value)
{
}

template <class k, class v>
Pair<k, v>::Pair(const k &key) : key(key)
{
}

template <class k, class v>
v &Pair<k, v>::getValue()
{
    return value;
}

template <class k, class v>
k Pair<k, v>::getKey() const
{
    return key;
}

template <class k, class v>
void Pair<k, v>::setValue(const v &value)
{
    this->value = value;
}

template <class k, class v>
bool Pair<k, v>::operator>(const Pair<k, v> &oth) const
{
    return this->key > oth.key;
}

template <class k, class v>
bool Pair<k, v>::operator>=(const Pair<k, v> &oth) const
{
    return this->key >= oth.key;
}

template <class k, class v>
bool Pair<k, v>::operator<(const Pair<k, v> &oth) const
{
    return this->key < oth.key;
}

template <class k, class v>
bool Pair<k, v>::operator<=(const Pair<k, v> &oth) const
{
    return this->key <= oth.key;
}

template <class k, class v>
bool Pair<k, v>::operator==(const Pair<k, v> &oth) const
{
    return this->key == oth.key;
}

template <class k, class v>
bool Pair<k, v>::operator!=(const Pair<k, v> &oth) const
{
    return this->key != oth.key;
}

template <class k, class v>
bool Pair<k, v>::operator>(const k &key) const
{
    return this->key > key;
}

template <class k, class v>
bool Pair<k, v>::operator>=(const k &key) const
{
    return this->key >= key;
}

template <class k, class v>
bool Pair<k, v>::operator<(const k &key) const
{
    return this->key < key;
}

template <class k, class v>
bool Pair<k, v>::operator<=(const k &key) const
{
    return this->key <= key;
}

template <class k, class v>
bool Pair<k, v>::operator==(const k &key) const
{
    return this->key == key;
}

template <class k, class v>
bool Pair<k, v>::operator!=(const k &key) const
{
    return this->key != key;
}
#endif