#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_set>
#include <string>
#include <cmath>
#include <vector>
#include <functional>
#include <random>
#include "person.h"

const int HT_SIZE = 10007;
void setup();
int hash(int key);
int hashing_midsquare(long key, int size);

int main()
{
    setup();
    std::ifstream in("exp.txt");
    int ht[HT_SIZE] = {0};
    int collisions = 0;
    int count = 0;
    while (!in.eof())
    {
        int num;
        in >> num;
        int hashValue = hash(num);
        if (ht[hashValue] == 0)
        {
            ht[hashValue] = num;
            std::cout << num << " inserted at " << hashValue << std::endl;
            count++;
        }
        else
        {
            std::cout << num << " collided with " << ht[hashValue] << std::endl;
            collisions++;
        }
    }
    std::cout << "There were " << collisions << " collisions." << std::endl;
    std::cout << "There were " << count << " items inserted." << std::endl;

    Person **people = new Person *[13];
    Person james("james", 28);
    Person semaj("semaj", 28);
    int jamesHash = james.hash();
    int semajHash = semaj.hash();
    jamesHash = jamesHash % 13;
    semajHash = semajHash % 13;
    people[jamesHash] = &james;
    std::cout << *people[jamesHash] << std::endl;
    people[semajHash] = &semaj;
    std::cout << *people[semajHash] << std::endl;
    std::cout << *people[jamesHash] << std::endl;
    return 0;
}

void setup()
{
    std::ofstream out("exp.txt");
    std::unordered_set<int> randomData;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 1000);
    std::uniform_int_distribution<int> distribution2(1, 9);
    std::uniform_int_distribution<int> distribution3(100000, 999999);
    while (randomData.size() < 5000)
    {
        int num = 0;
        num = distribution2(generator) * 100000 + distribution(generator);
        // num = distribution3(generator);
        randomData.insert(num);
    }
    bool begin = true;
    for (int i : randomData)
    {
        if (begin)
        {
            out << i;
            begin = false;
        }
        else
        {
            out << std::endl
                << i;
        }
    }
    out.close();
}

int hash(int key)
{
    return key % HT_SIZE;
}
