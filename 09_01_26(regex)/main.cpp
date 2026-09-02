#include <iostream>
#include <string>
#include <regex>
#include <format>
#include "date.h"

int main()
{
    std::string input;
    std::regex dateRegex(R"((\d{4})(\/|-)(0?[1-9]|1[0-2])\2([12][1-9]|3[01]|0?[1-9])\b)");
    std::regex q(R"(^q)");
    std::string invalid = "Invalid date!";
    while (input != "q")
    {
        std::cout << "Enter a date (year/month/day) (q=quit): ";
        if (!getline(std::cin, input))
        {
            input = "q";
            continue;
        }
        if (std::regex_search(input, q))
        {
            input = "q";
            continue;
        }
        std::smatch dateParts;
        if (std::regex_search(input, dateParts, dateRegex))
        {
            try
            {
                date myDate(stoi(dateParts[3]), stoi(dateParts[4]), stoi(dateParts[1]));
                std::cout << std::format("Valid Date: Year={}, month={}, day={}", myDate.getYear(), myDate.getMonth(), myDate.getDay()) << std::endl;
            }
            catch (...)
            {
                std::cout << invalid << std::endl;
            }
        }
        else
        {
            std::cout << invalid << std::endl;
        }
    }
    return 0;
}