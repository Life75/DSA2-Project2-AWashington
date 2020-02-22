#include "Customer.hpp"
#include "Heap.hpp"
#include "Statistics.hpp"

#include<sstream>
#include<ctime>
#include <queue>
#include <cstdlib>
#include <cmath>

double getNextRandomInterval(double avg);


int main() 
{
    std::queue < Customer * > holder;
    std::queue < Customer * > fifo;
    Customer * newNode = new Customer();
    Heap heap;
    
    
    int sizeArray = 1000;
    double serviceChannel = 4;
    double mu = 2;
    double lambda =0;

    std::cout << "Please enter lambda: ";
    std::cin >> lambda;

    std::cout << "Please enter mu: ";
    std::cin >> mu;

    std::cout << "Please enter amount of service channels: ";
    std::cin >> serviceChannel;

    std::cout << "Please enter amount of customers: ";
    std::cin >> sizeArray;

    double time = 0;
    Customer * customers[sizeArray];

    for (int i = 0; i < sizeArray; i++) {
        time += getNextRandomInterval(mu);
        customers[i] = new Customer();
        customers[i]->setArrivalTime(time);
        holder.push(customers[i]);
    }

    for (int i = 0; i < sizeArray; i++) {
        customers[i] = nullptr;
    }


    //testing
    int size = 200;
    double currentTime = 0;
    double Po =0;
    double Rho =0;
    double totalServiceTime=0;
    int j = 0;
    while (!holder.empty()) {
        for (int i = 0; i < size; i++) {
            customers[i] = holder.front();
            holder.pop();
        }
        int size = 200;
        j++;
          Po += customers[0]->getArrivalTime() - currentTime; 
        
        while (size > 0) {
            
            if (serviceChannel > 0) {
               
                if (fifo.empty()) {
                    newNode = heap.pop(customers, size);
                } else {
                    newNode = fifo.front();
                    fifo.pop();
                }
                Rho += newNode->getTime() - currentTime; 
                if (newNode->getDepartureTime() == -1) {
                    currentTime = newNode->getTime();
                    newNode->setStartOfServiceTime(currentTime);
                    double randomNum = getNextRandomInterval(mu);
                    totalServiceTime += randomNum;
                    newNode->setDepartureTime(newNode->getStartOfServiceTime() + randomNum);
                    heap.insertNode(customers, size, newNode);
                    heap.buildHeap(customers, size);
                   // std::cout << newNode->getDepartureTime() << "\n";
                    --serviceChannel;
                } 
                else {
                    //heap.pop(customers, size);
                    ++serviceChannel;
                }

            } 
            else {
                newNode = heap.pop(customers, size);
                //currentTime = newNode->getTime();
                if (newNode->getDepartureTime() == -1) {
                    fifo.push(newNode);
                } 
                else {
                    ++serviceChannel;
                }
            }

        }
    }

//calculate stats
Rho = Rho/totalServiceTime;
std::cout << "Analytical Model: \n";
double sizeOfArray = sizeArray;
Statistics stats(sizeOfArray, lambda, mu, serviceChannel);
std::cout << "Po = " << stats.Po() << std::endl;
std::cout << "L = " << stats.L() << std::endl;
std::cout << "W = " << stats.W() << std::endl;
std::cout << "Lq = " << stats.Lq() << std::endl;
std::cout << "Wq = " << stats.Wq() << std::endl;
std::cout << "\n";
std::cout << "Simulation Results: \n";
stats.setPo(Po);
std::cout << "Po = " << Po << std::endl;
std::cout << "W = " << stats.W() << std::endl;
std::cout << "Wq = " << stats.Wq() << std::endl;
std::cout << "Rho = " << Rho << std::endl;



}

double getNextRandomInterval(double avg)
{
    srand((unsigned int) time(0));
    double a = 1.0;
    double randomNum = (double(rand())/double((RAND_MAX)) * a);
    double intervalTime = -1 * (1.0/avg) * std::log(randomNum);
    return intervalTime;
}