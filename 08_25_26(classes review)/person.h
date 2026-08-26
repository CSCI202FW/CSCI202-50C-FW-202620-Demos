#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person
{
public:
    Person(std::string name, int age);
    std::string getName();
    void setName(std::string name);
    int getAge();
    void setAge(int age);
    void greet();

private:
    std::string name;
    int age;
};

#endif