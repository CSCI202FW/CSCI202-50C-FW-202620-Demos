#include "map.h"
#include "donut.h"
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <fstream>

void insertDonutForHobbit(std::string name, Map<std::string, Donut *> &hobbitDonuts);
void printHobbitsWithDonuts(Map<int, std::string> hobbits, Map<std::string, Donut *> hobbitDonuts);
// M06 part A lab
//  write a new main to test the map. use any key value pair you like(that hasn't already been used).
//  make sure you insert, change, and delete items.
int main()
{
    Map<int, std::string> hobbits;
    Map<std::string, Donut *> hobbitDonuts;

    std::ifstream name("names.txt");
    for (int i = 1; !name.eof(); i++)
    {
        std::string in;
        std::getline(name >> std::ws, in);
        hobbits.insert(i, in);
        insertDonutForHobbit(in, hobbitDonuts);
    }
    printHobbitsWithDonuts(hobbits, hobbitDonuts);
    std::cout << std::endl
              << std::endl;
    std::cout << hobbits[1] << std::endl;
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl;
    hobbits[1] = "Tasha Oakbottom";
    insertDonutForHobbit(hobbits[1], hobbitDonuts);
    std::cout << hobbits.at(1) << std::endl;
    hobbits[15] = "Brianna Button";
    // insertDonutForHobbit(hobbits[15], hobbitDonuts);
    hobbits[13] = "Arnoul Goodbody";
    insertDonutForHobbit(hobbits[13], hobbitDonuts);
    std::cout << std::setw(40) << std::setfill('-') << "-" << std::endl;
    printHobbitsWithDonuts(hobbits, hobbitDonuts);
    std::cout << std::endl
              << std::endl;
    std::cout << "\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\nBegin Delete test:\n\n";
    std::cout << "Notes about the delete debugger:\nType -1 to exit\nType -2 to print map\n";
    while (true)
    {
        std::cout << "\n  *** \n";
        int ind;
        std::cout << "Enter index of node to be deleted: ";
        std::cin >> ind;
        if (ind == -1)
        {
            for (auto it = hobbitDonuts.begin(); it != hobbitDonuts.end(); ++it)
            {
                std::cout << it->getKey() << " --- " << *it->getValue() << std::endl;
                delete it->getValue();
            }
            break;
        }
        if (ind == -2)
        {
            std::cout << hobbits.preorder() << std::endl;
            for (auto it = hobbits.begin(); it != hobbits.end(); ++it)
            {
                Pair<int, std::string> p = *it;

                std::cout << p.getValue() << " --- ";
                try
                {
                    std::cout << *hobbitDonuts.at(p.getValue()) << std::endl;
                }
                catch (std::out_of_range e)
                {
                    std::cout << std::endl;
                }
            }
        }
        else
        {
            try
            {

                std::cout << "Deleting " << hobbits.at(ind) << "\n";
                std::string n = hobbits.deleteItem(ind);
                Donut *d = hobbitDonuts.deleteItem(n);
                std::cout << *d << " ";
                std::cout << n
                          << std::endl;
                delete d;
            }
            catch (const std::out_of_range &e)
            {
                std::cout << e.what() << '\n';
            }
        }
    }

    return 0;
}

void insertDonutForHobbit(std::string name, Map<std::string, Donut *> &hobbitDonuts)
{
    static std::random_device rd;
    static std::uniform_int_distribution<int> icingDist(0, static_cast<int>(icingType::NOICE));
    static std::uniform_int_distribution<int> toppingDist(0, static_cast<int>(Donut::toppingType::NOTOP));
    static std::uniform_int_distribution<int> drizzleDist(0, static_cast<int>(drizzleType::NODRIZZLE));
    static std::default_random_engine generator(rd());
    Donut *d = new Donut(Donut::iceToStr.at(static_cast<icingType>(icingDist(generator))), Donut::topToStr.at(static_cast<Donut::toppingType>(toppingDist(generator))), Donut::drizzleToStr.at(static_cast<drizzleType>(drizzleDist(generator))));
    Pair<bool, Map<std::string, Donut *>::Iterator> p = hobbitDonuts.insert(name, d);
    if (!p.getKey())
    {
        delete d;
    }
}

void printHobbitsWithDonuts(Map<int, std::string> hobbits, Map<std::string, Donut *> hobbitDonuts)
{
    for (auto it = hobbits.begin(); it != hobbits.end(); ++it)
    {
        std::cout << it->getValue() << " --- ";
        try
        {
            std::cout << *hobbitDonuts.at(it->getValue());
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << std::endl;
    }
}
