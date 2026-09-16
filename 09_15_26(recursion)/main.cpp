#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "linkedStack.h"

const int DEFAULT = 0;

void resetStream();
int factorial(int n);
bool isNum(int = DEFAULT, int = DEFAULT, int = DEFAULT) { return true; }
int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int) = isNum, int low = DEFAULT, int high = DEFAULT);
bool intInRange(int n, int lower, int upper);
bool intGTX(int n, int x, int = DEFAULT);
bool intLTX(int n, int x, int = DEFAULT);
bool intGTEQX(int n, int x, int = DEFAULT);
bool intLTEQX(int n, int x, int = DEFAULT);
bool intNotInRange(int n, int lower, int upper);
bool intEQX(int n, int x, int = DEFAULT);
bool intNEX(int n, int x, int = DEFAULT);

long fibonacci(long f1, long f2, long n);
long fibNum(long f[], long n);
void moveDisks(int, char source, char destination, char spare);
void moveDisks(int disk, LinkedStack<int> &source, LinkedStack<int> &destination, LinkedStack<int> &spare, char, char, char);
void printTowers(LinkedStack<int> t1, LinkedStack<int> t2, LinkedStack<int> t3);

int main()
{
    int n = inputInt("Enter a number between 1 and 10: ", "That is not a number between 1 and 10.", intInRange, 1, 10);
    std::cout << factorial(n) << std::endl;
    int fib1 = inputInt("Enter a number greater than 0: ", "That is not a number greater than 0.", intGTX);
    std::string prompt2 = "Enter a number greater than or equal to " + std::to_string(fib1) + ": ";
    std::string err2 = "That is not a number greater than or equal to " + std::to_string(fib1) + ".";
    int fib2 = inputInt(prompt2, err2, intGTEQX, fib1);
    int nth = inputInt("Which fibbonacci number do you want to see? ", "Please enter a number greater than 2.", intGTX, 2);
    std::cout << "The " << nth << "th fibonacci number is " << fibonacci(fib1, fib2, nth) << std::endl;
    long *f = new long[nth];
    for (int i = 0; i < nth; i++)
    {
        f[i] = -1;
    }
    f[0] = fib1;
    f[1] = fib2;
    std::cout << "The " << nth << "th fibonacci number is " << fibNum(f, nth) << std::endl;
    moveDisks(5, 'A', 'C', 'B');
    LinkedStack<int> source(1);
    LinkedStack<int> spare(2);
    LinkedStack<int> destination(3);
    for (int i = 5; i > 0; i--)
    {
        source.push(i);
    }
    std::cout << std::endl
              << std::endl;
    moveDisks(5, source, destination, spare, 'A', 'C', 'B');
    return 0;
}

int factorial(int n)
{
    n = abs(n);
    if (n == 0)
    {
        return 1;
    }
    // n! = n * (n-1)!
    return n * factorial(n - 1);
}

int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low, int high)
{
    int num;
    std::cout << prompt;
    std::cin >> num;
    if (std::cin && valid(num, low, high))
    {
        return num;
    }
    if (!std::cin)
    {
        resetStream();
    }
    std::cout << err << std::endl;
    return inputInt(prompt, err, valid, low, high); // start over
    /* standard input err checking
    while(!std::cin || num < low || num > high)
    {
        if(!std::cin)
        {
            resetStream();
        }
        std::cout << err << std::endl;
        std::cout << prompt;
        std::cin >> num;
    } */
    // return num;
}

bool intInRange(int n, int lower, int upper)
{
    return n >= lower && n <= upper;
}

bool intGTX(int n, int x, int)
{
    return n > x;
}

bool intLTX(int n, int x, int)
{
    return n < x;
}

bool intGTEQX(int n, int x, int)
{
    return n >= x;
}

bool intLTEQX(int n, int x, int)
{
    return n <= x;
}

bool intNotInRange(int n, int lower, int upper)
{
    return n < lower || n > upper;
}

bool intEQX(int n, int x, int)
{
    return n == x;
}

bool intNEX(int n, int x, int)
{
    return n != x;
}

long fibonacci(long f1, long f2, long n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return f1;
    }
    if (n == 2)
    {
        return f2;
    }
    return fibonacci(f1, f2, n - 1) + fibonacci(f1, f2, n - 2);
}

long fibNum(long f[], long n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (f[n - 1] != -1)
    {
        return f[n - 1];
    }
    f[n - 1] = fibNum(f, n - 1) + fibNum(f, n - 2);
    return f[n - 1];
}

void moveDisks(int count, char source, char destination, char spare)
{
    if (count > 0)
    {
        moveDisks(count - 1, source, spare, destination);
        std::cout << "Move disk " << count << " from " << source << " to " << destination << std::endl;
        moveDisks(count - 1, spare, destination, source);
    }
}

void moveDisks(int disk, LinkedStack<int> &source, LinkedStack<int> &destination, LinkedStack<int> &spare, char s, char d, char sp)
{
    if (disk == 0)
    {
        return;
    }
    moveDisks(disk - 1, source, spare, destination, s, sp, d);
    destination.push(source.pop());
    std::cout << "Move Disk" << disk << " from " << s << " to " << d << std::endl;
    printTowers(source, destination, spare);
    moveDisks(disk - 1, spare, destination, source, sp, d, s);
}

void printTowers(LinkedStack<int> t1, LinkedStack<int> t2, LinkedStack<int> t3)
{
    LinkedStack<int> *source;
    LinkedStack<int> *spare;
    LinkedStack<int> *dest;

    if (t2 > t1)
    {
        if (t3 > t2)
        {
            dest = &t3;
            spare = &t2;
            source = &t1;
        }
        else if (t3 > t1)
        {
            dest = &t2;
            spare = &t3;
            source = &t1;
        }
        else
        {
            dest = &t2;
            spare = &t1;
            source = &t3;
        }
    }
    else if (t3 > t1)
    {
        dest = &t3;
        spare = &t1;
        source = &t2;
    }
    else if (t2 > t3)
    {
        dest = &t1;
        spare = &t2;
        source = &t3;
    }
    else
    {
        dest = &t1;
        spare = &t3;
        source = &t2;
    }
    int count = source->getCount();
    if (count < spare->getCount())
    {
        count = spare->getCount();
    }
    if (count < dest->getCount())
    {
        count = dest->getCount();
    }
    while (source->getCount() < count)
    {
        source->push(0);
    }
    while (spare->getCount() < count)
    {
        spare->push(0);
    }
    while (dest->getCount() < count)
    {
        dest->push(0);
    }
    std::cout << std::setfill('-');
    while (!t1.isEmptyStack() || !t2.isEmptyStack() || !t3.isEmptyStack())
    {
        int s = source->pop();
        int sp = spare->pop();
        int d = dest->pop();
        if (s != 0)
        {
            std::cout << std::setw(s) << "-" << "\t\t\t";
        }
        else
        {
            std::cout << "  |  " << "\t\t\t";
        }
        if (sp != 0)
        {
            std::cout << std::setw(sp) << "-" << "\t\t\t";
        }
        else
        {
            std::cout << "  |  " << "\t\t\t";
        }
        if (d != 0)
        {
            std::cout << std::setw(d) << "-" << std::endl;
        }
        else
        {
            std::cout << "  |  " << std::endl;
        }
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}