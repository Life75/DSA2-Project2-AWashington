#define CATCH_CONFIG_MAIN

#include<sstream>
#include<ctime>
#include <queue>

#include "catch/catch.hpp"
#include "../Customer.hpp"
#include "../Heap.hpp"

class MyClass
{
  public:
  double getNextRandomInterval(double avg)
  {
    
    srand((unsigned int) time(0));
    double a = 1.0;
    double randomNum = (double(rand())/double((RAND_MAX)) * a);

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
    std::cout << time << "\n";
    time += randomNum;
    customerArr[i]->setArrivalTime(time);

  }


 // delete[] customerArr;

  double testVal1 = test.getNextRandomInterval(2);
  double testVal2 = test.getNextRandomInterval(3);
  REQUIRE(testVal1 != testVal2);

  customer1.setArrivalTime(testVal1);
  customer2.setArrivalTime(testVal2);
  REQUIRE(customer1.getTime() != customer2.getTime());
 // test.getNextRandomInterval(3);


  //customer.setArrvialTime
}

TEST_CASE("class Heap")
{
  //testing how std::queue works 
  std::queue <Customer*> test; 
  Customer* cust1;
  Customer* cust2;
  test.push(cust1);
  test.push(cust2);
  //use a pass by reference array to keep the array up to date 
}

TEST_CASE("class Statisitics")
{
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


