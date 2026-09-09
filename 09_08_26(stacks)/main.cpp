#include <iostream>
#include <string>
#include <regex>
#include <cmath>
#include <map>
#include <limits>
#include "arrayStack.h"
#include "linkedStack.h"
// m03-a come up with 5 binary numbers
// 5 hex numbers at least 4 digits

std::string inputBinaryNumber();
int convertBinaryToDecimal(StackADT<int> &);
void convertDecimalToBinary(StackADT<int> &, int);
std::string inputHexadecimalNumber();
int convertHexToDecimal(StackADT<int> &);
void resetStream();
const std::map<char, int> hexDigit = {{'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}};
const std::regex space(R"(\s+)");

int main()
{
    ArrayStack<int> aStack;
    LinkedStack<int> lStack;
    char numberType = ' ';
    while (numberType != 'Q')
    {
        aStack.initializeStack();
        lStack.initializeStack();
        std::cout << "Do you want to convert a (H)ex number or a (B)inary number to decimal, or (D)ecimal to binary, enter q to quit? ";
        std::cin >> numberType;
        std::cout << std::endl;
        numberType = toupper(numberType);
        if (numberType == 'Q')
        {
            continue;
        }
        while (numberType != 'H' && numberType != 'B' && numberType != 'D')
        {
            std::cout << "Please enter H or B or D." << std::endl;
            std::cout << "Do you want to convert a (H)ex number or a (B)inary number to decimal, or (D)ecimal to binary, enter q to quit? ";
            std::cin >> numberType;
            std::cout << std::endl;
            numberType = toupper(numberType);
        }
        if (numberType == 'B')
        {
            std::string binNumber = inputBinaryNumber();
            for (int i = 0; i < binNumber.size(); i++)
            {
                aStack.push(binNumber[i] - '0');
            }
            std::cout << binNumber << " converted to decimal is " << convertBinaryToDecimal(aStack) << std::endl;
        }
    }
}

std::string inputBinaryNumber()
{
    std::regex binNum(R"([^10])");
    std::string binaryNumber;
    std::cout << "Enter a number in binary: ";
    std::getline(std::cin >> std::ws, binaryNumber);
    binaryNumber = std::regex_replace(binaryNumber, space, "");
    while (std::regex_search(binaryNumber, binNum))
    {
        std::cout << "Please enter only 1s and 0s." << std::endl;
        std::cout << "Enter a number in binary: ";
        std::getline(std::cin >> std::ws, binaryNumber);
        binaryNumber = std::regex_replace(binaryNumber, space, "");
    }
    return binaryNumber;
}

int convertBinaryToDecimal(StackADT<int> &)
{
    return 0;
}
