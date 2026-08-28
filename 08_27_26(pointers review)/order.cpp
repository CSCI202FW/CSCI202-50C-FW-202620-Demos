#include "order.h"

Order::Order()
{
    donutList = nullptr;
    numDonuts = 0;
}

Order::Order(const Order &orderToCopy)
{
    donutList = nullptr;
    numDonuts = 0;
    copyOrder(orderToCopy);
}

const Order &Order::operator=(const Order &orderToCopy)
{
    if (this != &orderToCopy) // self copy check x = x
    {
        copyOrder(orderToCopy);
    }
    return *this;
}

void Order::operator+(const Donut &d)
{
    numDonuts++;
    if (donutList == nullptr)
    {
        donutList = new Donut *[numDonuts];
    }
    else
    {
        Donut **temp = donutList;
        donutList = new Donut *[numDonuts];
        for (int i = 0; i < numDonuts - 1; i++)
        {
            donutList[i] = temp[i];
        }
        delete[] temp;
    }
    donutList[numDonuts - 1] = new Donut(d);
}

int Order::donutCount() const
{
    return 0;
}

Order::~Order()
{
    destroyList();
}

void Order::copyOrder(const Order &orderToCopy)
{
    if (this->donutList != nullptr)
    {
        destroyList();
    }
    this->numDonuts = orderToCopy.numDonuts;
    this->donutList = new Donut *[this->numDonuts];
    for (int i = 0; i < this->numDonuts; i++)
    {
        donutList[i] = new Donut(*(orderToCopy.donutList[i]));
    }
}

void Order::destroyList()
{
    for (int i = 0; i < numDonuts; i++)
    {
        delete donutList[i];
    }
    delete[] donutList;
}

std::ostream &operator<<(std::ostream &out, const Order &orderToPrint)
{
    for (int i = 0; i < orderToPrint.numDonuts; i++)
    {
        out << *orderToPrint.donutList[i] << std::endl;
    }
    return out;
}
