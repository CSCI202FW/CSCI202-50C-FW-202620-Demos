#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::regex dates{R"(\d{4}\/(?:0?[1-9]|1[0-2])\/(?:[12][1-9]|3[01]|0?[1-9]))"};
    std::regex thirty{R"(\d{4}\/(?:0?[469]|11)\/(?:[12][1-9]|30|0?[1-9]))"};
    std::regex feb{R"(\d{4}\/(?:0?2)\/(?:[12][1-9]|0?[1-9]))"};
    std::regex thirtyone{R"(\d{4}\/(?:0?[13578]|1[02])\/(?:[12][1-9]|3[01]|0?[1-9]))"};

    while (true)
    {
        std::cout << "Enter a date (year/month/day) (q=quit): ";
        std::string str;
        if (!getline(std::cin, str) || str == "q")
        {
            break;
        }
        if (std::regex_match(str, dates))
        {
            if (std::regex_match(str, feb) || std::regex_match(str, thirty) || std::regex_match(str, thirtyone))
                std::cout << "  Valid date." << std::endl;
            else
            {
                std::cout << "  Invalid Date!" << std::endl;
            }
        }
        else
        {
            std::cout << "  Invalid Date!" << std::endl;
        }
    }

    return 0;
}