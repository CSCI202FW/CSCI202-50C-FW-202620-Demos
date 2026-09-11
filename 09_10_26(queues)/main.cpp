#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <limits>
#include "process.h"
#include "arrayQueue.h"
#include "linkedQueue.h"
#include "unorderedLinkedList.h"
#include "priorityQueue.h"

void processFile(LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting, int &processCount);
void listProcesses(const LinkedQueue<Process> &ready, const ArrayQueue<Process> &waiting, const UnorderedLinkedList<Process> &finished);
void printMenu();
int getMenuChoice();
void resetStream();
void processChoice(int choice, LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting, UnorderedLinkedList<Process> &finished);
void runNextProcess(LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting, UnorderedLinkedList<Process> &finished);
void interrupt(LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting);

int main()
{
    UnorderedLinkedList<Process> finished;
    PriorityQueue<Process> ready;
    ArrayQueue<Process> waiting;
    int processCount = 0;
    processFile(ready, waiting, processCount);
    int choice = 0;
    while (choice != 4)
    {
        if (processCount == finished.length())
        {
            choice = 4;
            std::cout << "All processes have finished. Shutting Down." << std::endl;
        }
        else
        {
            choice = getMenuChoice();
        }
        processChoice(choice, ready, waiting, finished);
    }

    return 0;
}

void processFile(LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting, int &processCount)
{
    std::ifstream in("processes.txt");
    if (!in.is_open())
    {
        throw std::runtime_error("Unable to open process file.");
    }
    processCount = 0;
    while (!in.eof())
    {
        std::string name;
        int priority;
        int slicesNeeded;
        int IOSlice;
        std::string statusStr;
        in >> name >> priority >> slicesNeeded >> IOSlice >> statusStr;
        if (!in)
        {
            break;
        }
        std::transform(statusStr.begin(), statusStr.end(), statusStr.begin(), ::tolower);
        Process p(name, priority, slicesNeeded, IOSlice, strToStatus.at(statusStr));
        processCount++;
        if (p.getStatus() == WAITING)
        {
            waiting.enqueue(p);
        }
        else
        {
            ready.enqueue(p);
        }
    }
}

void listProcesses(const LinkedQueue<Process> &ready, const ArrayQueue<Process> &waiting, const UnorderedLinkedList<Process> &finished)
{
    LinkedQueue readyTemp(ready);
    ArrayQueue waitingTemp(waiting);
    std::ostringstream separator;
    separator << std::setfill('-');
    separator << std::endl
              << std::setw(40) << "-";
    std::cout << std::endl
              << "List of Ready Processes:";
    std::cout << separator.str() << std::endl;
    while (!readyTemp.isEmptyQueue())
    {

        std::cout << readyTemp.dequeue();
        std::cout << separator.str() << std::endl;
    }
    std::cout << std::endl
              << "List of Waiting Processes:";
    std::cout << separator.str() << std::endl;
    while (!waitingTemp.isEmptyQueue())
    {

        std::cout << waitingTemp.dequeue();
        std::cout << separator.str() << std::endl;
    }
    std::cout << "List of Finished Processes:" << std::endl;
    separator << std::endl;
    finished.print(std::cout, separator.str());
}

void printMenu()
{
    std::cout << "Please choose from the following menu: " << std::endl;
    std::cout << "1. Run Next Process" << std::endl;
    std::cout << "2. Trigger an Interrupt" << std::endl;
    std::cout << "3. List All Processes" << std::endl;
    std::cout << "4. Shut Down" << std::endl;
    std::cout << "Your Choice: ";
}

int getMenuChoice()
{
    int choice;
    std::cout << std::endl;
    printMenu();
    std::cin >> choice;
    while (!std::cin || choice < 1 || choice > 4)
    {
        if (!std::cin)
        {
            resetStream();
        }
        std::cout << "That is not a valid choice." << std::endl;
        printMenu();
        std::cin >> choice;
    }
    return choice;
}

void processChoice(int choice, LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting, UnorderedLinkedList<Process> &finished)
{
    switch (choice)
    {
    case 1:
        runNextProcess(ready, waiting, finished);
        break;
    case 2:
        interrupt(ready, waiting);
        break;
    case 4:
        std::cout << "Shutting Down:" << std::endl;
    case 3:
        listProcesses(ready, waiting, finished);
    }
}

void runNextProcess(LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting, UnorderedLinkedList<Process> &finished)
{
    try
    {
        Process p = ready.dequeue();
        std::cout << "Running Process:" << std::endl;
        std::cout << p << std::endl;
        p.run();
        if (p.getStatus() == WAITING)
        {
            waiting.enqueue(p);
        }
        else if (p.getStatus() == READY)
        {
            ready.enqueue(p);
        }
        else
        {
            finished.insert(p);
        }
    }
    catch (...)
    {
        std::cout << "There are no ready processes. Try to do an interrupt." << std::endl;
    }
}

void interrupt(LinkedQueue<Process> &ready, ArrayQueue<Process> &waiting)
{
    try
    {
        Process p = waiting.dequeue();
        p.changeStatus(READY);
        std::cout << "Moving Process to Ready:" << std::endl;
        std::cout << p << std::endl;
        ready.enqueue(p);
    }
    catch (...)
    {
        std::cout << "No Waiting Processes." << std::endl;
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "You did not enter a number." << std::endl;
}