#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

const int DEFAULT = 0;

void resetStream();
int factorial(int n);
int inputInt(std::string prompt, std::string err, bool (*valid)(int, int, int), int low = DEFAULT, int high = DEFAULT);
bool intInRange(int n, int lower, int upper);
bool intGTX(int n, int x, int = DEFAULT);
bool intLTX(int n, int x, int = DEFAULT);
bool intGTEQX(int n, int x, int = DEFAULT);
bool intLTEQX(int n, int x, int = DEFAULT);
bool intNotInRange(int n, int lower, int upper);
bool intEQX(int n, int x, int = DEFAULT);
bool intNEX(int n, int x, int = DEFAULT);
bool isNum(int = DEFAULT, int = DEFAULT, int = DEFAULT) { return true; }

int main()
{
    int n = inputInt("Enter a number between 1 and 10: ", "That is not a number between 1 and 10.", intInRange, 1, 10);
    std::cout << factorial(n) << std::endl;
    n = inputInt("Enter a number greater than 0: ", "That is not a number greater than 0.", intGTX, 0, 0);
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

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}