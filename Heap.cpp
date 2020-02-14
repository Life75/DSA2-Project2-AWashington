
#include "Heap.hpp"

void Heap::buildHeap(Customer* priorityQ[], int size)
{
    int start = (size/2) - 1;
    for(int i= start; i >=0; i--)
    heapify(priorityQ, size, i);
}

void Heap::heapify(Customer* priorityQ[], int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && priorityQ[left]->getTime() < priorityQ[smallest]->getTime())
    smallest = left;

    if(right < size && priorityQ[right]->getTime() < priorityQ[smallest]->getTime())
    smallest = right;

    if(smallest != i)
    {
        std::swap(priorityQ[i], priorityQ[smallest]);

        heapify(priorityQ, size, smallest);
    }
}

void Heap::printHeap(Customer* priorityQ[], int size)
{
    // std::cout << "Array: ";
  for(int i=0; i < size; i++)
  {
    if(priorityQ[i]->getDepartureTime() == -1)
    {
        std::cout << "This is an arrival: ";
    }
    std::cout << priorityQ[i]->getTime() << " \n";
  }
}

Customer* Heap::pop(Customer* priorityQ[], int& size)
{
    Customer* front = new Customer();
    front = priorityQ[0];
    Customer* lastElement = priorityQ[size-1];
    priorityQ[0] = lastElement;

    size = size-1;

    heapify(priorityQ, size, 0);
    return front;
}   

void Heap::insertNode(Customer* priorityQ[], int& size, Customer* newNode)
{
    size = size + 1;
    priorityQ[size-1] = newNode;

    heapify(priorityQ, size, size-1);
}