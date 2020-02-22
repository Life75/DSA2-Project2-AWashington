#define CATCH_CONFIG_MAIN

#include<sstream>
#include<ctime>
#include <queue>
#include <cstdlib>
#include "catch/catch.hpp"
#include "../Customer.hpp"
#include "../Heap.hpp"
#include "../Statistics.hpp"

class MyClass
{
  public:
  //average is mu
  double getNextRandomInterval(double avg)
  {
    
    srand((unsigned int) time(0));
    double a = 1.0;
    double randomNum = (double(rand())/double((RAND_MAX)) * a);
    //std::cout << randomNum << "\n";
   // std::cout << randomNum << "\n";
    double intervalTime = -1 * (1.0/avg) * log(randomNum);
    return intervalTime;
    
  }
};

TEST_CASE("class Customer")
{
  Customer customer1;
  Customer customer2;
  MyClass test;

  
  //testing generating averages 
  /*
  double time = 0;
  Customer* customerArr[50];
  for(int i =0; i < 50; i++)
  {
    double avg = 0;
    avg = time / i;
    if(i == 0)
    {
      avg = 1;
    }
    //std::cout << avg << " " << time << "\n";
    customerArr[i] = new Customer();
    double randomNum = test.getNextRandomInterval(avg);
   // std::cout << time << "\n";
    time += randomNum;
    customerArr[i]->setArrivalTime(time);

  }
*/

 // delete[] customerArr;

  double testVal1 = test.getNextRandomInterval(1);
  double testVal2 = test.getNextRandomInterval(1);
  REQUIRE(testVal1 == testVal2);

  customer1.setArrivalTime(testVal1);
  customer2.setArrivalTime(testVal2);
  REQUIRE(customer1.getTime() == customer2.getTime());
 // test.getNextRandomInterval(3);


  //customer.setArrvialTime
}

TEST_CASE("class Heap")
{
  //testing how std::queue works 
  std::queue <Customer*> tester;
  std::queue <Customer*> fifo;
  MyClass timeInterval;
  Heap heap;
  Customer* cust1 = new Customer();
  cust1->setArrivalTime(1);
  Customer* cust2 = new Customer();
  cust2->setArrivalTime(2);

  tester.push(cust1);
  tester.push(cust2);
  cust2 = tester.front(); 
  REQUIRE(1 == cust2->getArrivalTime());

  //
  //Creating Heap Test
  //use a pass by reference array to keep the array up to date
  int serviceChannel = 4;
  int size = 5;
  double mu = 2;
  double time = 0;
  Customer* customers[5];
  for(int i = 0; i < size; i++)
  {
    time += timeInterval.getNextRandomInterval(mu);
    customers[i] = new Customer();
    customers[i]->setArrivalTime(time);
  }

  heap.buildHeap(customers, size);
  //heap.printHeap(customers, size);
  //std::cout << "\n";
  //should be in the front of the heap
  Customer* newNode = new Customer();
  newNode->setArrivalTime(0);
  heap.insertNode(customers, size, newNode);
  heap.buildHeap(customers, size);
//  heap.printHeap(customers, size);
//  std::cout << "\n";

  newNode = heap.pop(customers, size);
  //heap.printHeap(customers,size);
  REQUIRE(0 == newNode->getArrivalTime());
/*
  newNode->setArrivalTime(30);
  heap.insertNode(customers, size, newNode);
  heap.buildHeap(customers, size);
  newNode = heap.pop(customers, size);
  REQUIRE(newNode->getTime() != 30);
  std::cout << "\n";*/
//  heap.printHeap(customers, size);

  //heap works, now to test the actual program logic 
//heap.printHeap(customers, size);

//make a build heap before etc 
// You'll make a dedicated queue for the beginning and push them in the heap array
std::cout << "\n";
int i =0;
double currentTime =0;
while(size > 0)
{
  


  if(serviceChannel > 0)
  {
    if(fifo.empty())
    {
      newNode = heap.pop(customers, size);
    }
    else 
    {
      newNode = fifo.front();
      fifo.pop();
    }
    
    if(newNode->getDepartureTime() == -1)
    {
      currentTime = newNode->getTime();
      newNode->setStartOfServiceTime(currentTime);
      newNode->setDepartureTime(newNode->getStartOfServiceTime() + timeInterval.getNextRandomInterval(mu));
      heap.insertNode(customers, size, newNode);
      heap.buildHeap(customers, size);
      //std::cout << newNode->getDepartureTime() << "\n";
      --serviceChannel; 
    }
    else 
    {
      //heap.pop(customers, size);
      ++serviceChannel;
    }
    
  }

  else
  {
    newNode = heap.pop(customers, size);
    //currentTime = newNode->getTime();
    if(newNode->getDepartureTime() == -1)
    {
      fifo.push(newNode);
    }
    else 
    {
      ++serviceChannel;
    }
  }
  
}











/*
   for(int i=0; i < size; i++)
  {
    if(customers[i]->getDepartureTime() == -1)
    {
        std::cout << "This is an arrival: ";
    }
    std::cout << customers[i]->getTime() << " \n";
  }
*/
}

TEST_CASE("class Statisitics")
{
  //1
  Statistics stats(1.0, 2.0 , 3.0, 2.0);
  REQUIRE(6 == stats.factorial(3.0));
  float Po = stats.Po();
  REQUIRE(Po == 0.5);

  //2
  double L = stats.L();
  REQUIRE(L == .75);

  //3
  double W = stats.W();
  REQUIRE(W == .375);

  //4
  double Lq = stats.Lq();
  REQUIRE(Lq == .083);

  //5
  double Wq = stats.Wq();
  REQUIRE(Wq == 0.0417);

  double Rho = stats.Rho();
  REQUIRE(Rho == .33);


  //calculate the different statisitcs for the project with the data
  /*
    functions for:
    1. Percent idle time Po, the percentage of time that no one is in the system:

    2. The average num of people in the system, the number in line plus the number being served

    3. The average time a customer spends in the system ( the time the customer spent in line plus the time spent getting the service)

    4. The average numbers of customers in the queue:

    5. The average time a customer spends waiting in the queue:

    6. The utilization factor for the system

    must compute these six values from the Analytic Model

    lambda =2;
    mu =3;
    M =2;

    Po =0.5
    L =.75
    W= 0.375
    Lq = .083
    Wq = .0417
  */
}

TEST_CASE("class Main")
{
  // Where you'll test out the functions with the logic that can be applied in main and just simply copy and paste the code 
  std::queue <Customer*> holder;
  std::queue <Customer*> fifo;
  Customer* newNode = new Customer();
  Heap heap;

  MyClass timeInterval;
  int sizeArray = 1000;
  int serviceChannel = 4;
  double mu = 2;
  double time = 0;
  Customer* customers[sizeArray];
 
  for(int i = 0; i < sizeArray; i++)
  {
    time += timeInterval.getNextRandomInterval(mu);
    customers[i] = new Customer();
    customers[i]->setArrivalTime(time);
    holder.push(customers[i]);
  }

  for(int i=0; i < sizeArray; i++)
  {
    customers[i] = nullptr;
  }


//testing
int size = 200;  
double idleTime =0; 
double currentTime =0;
int j = 0;
while(!holder.empty())
{
  for(int i=0; i < size; i++)
  {
    customers[i] = holder.front();
    holder.pop();
  }
  int size = 200;
  j++;
  idleTime += customers[0]->getArrivalTime() - currentTime; 
  //std::cout << idleTime << " " << currentTime << "\n"; 
  while(size > 0)
{
  
  if(serviceChannel > 0)
  {
    if(fifo.empty())
    {
      newNode = heap.pop(customers, size);
    }
    else 
    {
      newNode = fifo.front();
      fifo.pop();
    }
    
    if(newNode->getDepartureTime() == -1)
    {
      currentTime = newNode->getTime();
      newNode->setStartOfServiceTime(currentTime);
      newNode->setDepartureTime(newNode->getStartOfServiceTime() + timeInterval.getNextRandomInterval(mu));
      heap.insertNode(customers, size, newNode);
      heap.buildHeap(customers, size);
      //std::cout << newNode->getDepartureTime() << "\n";
      --serviceChannel; 
    }
    else 
    {
      //heap.pop(customers, size);
      ++serviceChannel;
    }
    
  }

  else
  {
    newNode = heap.pop(customers, size);
    //currentTime = newNode->getTime();
    if(newNode->getDepartureTime() == -1)
    {
      fifo.push(newNode);
    }
    else 
    {
      ++serviceChannel;
    }
  }
  
}
}
//std::cout << j << "\n";


  
  
}