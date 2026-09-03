#include "node.h"
#include "donut.h"

int main()
{
    Node<Donut> *newNode;
    newNode = new Node<Donut>(Donut("none", "none", "none"));
    return 0;
}