#ifndef HEAP_HPP_
#define HEAP_HPP_

#include <iostream>
#include <sstream>
#include "Customer.hpp"

class Heap
{
    private:

    public:
    void buildHeap(Customer* priorityQ[], int size);
    void heapify(Customer* priorityQ[], int size, int i);
    void printHeap(Customer* priorityQ[], int size);
    Customer* pop(Customer* priorityQ[], int& size); //will pop and delete the root and build the heap again 
    void insertNode(Customer* priorityQ[], int& size, Customer* newNode);
};
#endif