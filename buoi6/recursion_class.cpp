#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class ClassA
{
private:
    int data;
    // ClassA *array[10]; // Array of ClassA objects
    vector<ClassA> listA;

public:
    // Constructor
    ClassA(int d) : data(d) {}

    // Example method
    void printData()
    {
        std::cout << "Data: " << data << std::endl;
    }
};