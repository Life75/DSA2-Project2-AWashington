
#include "Customer.hpp"



Customer::Customer()
{
    arrivalTime  = -1;
    startOfServiceTime = -1;
    departureTime =-1;
}
Customer::Customer(Customer* next)
{
    arrivalTime  =0;
    startOfServiceTime = 0;
    departureTime =0;
    this->next = next;
}

double Customer::getArrivalTime() 
{return arrivalTime;}


double Customer::getStartOfServiceTime() 
{return startOfServiceTime;}

double Customer::getDepartureTime() 
{return departureTime;}
    
void Customer::setArrivalTime(float arrivalTime)
{this->arrivalTime = arrivalTime;}

void Customer::setStartOfServiceTime(float startOfServiceTime) 
{this->startOfServiceTime = startOfServiceTime;}
    
void Customer::setDepartureTime(float departureTime) {this->departureTime = departureTime;} 

Customer* Customer::nextCust()
{
    return next;
}

double Customer::getTime()
{
    if(departureTime != -1)
    {
        return departureTime; 
    }
    else return arrivalTime;
}
    