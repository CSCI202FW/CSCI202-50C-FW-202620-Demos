/* Program name: Module 1 Part A Lecture/Lab Activity
 * Author: Angela Venable
 * Date last updated: 8/25/2026
 * Purpose: introduce submitting to classroom 50
 */
#include <iostream>
#include <string>

int main()
{
    std::string welcome;

    std::cout << "Complete the phrase Welcome To ";
    // using getline so that we can get more than one word of input
    std::getline(std::cin >> std::ws, welcome);
    // output required by the autograde tests
    std::cout << "Welcome to " << welcome << "!" << std::endl;
    std::cout << "My name is Angela Venable" << std::endl;
    return 0;
}