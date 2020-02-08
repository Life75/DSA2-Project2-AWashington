
#include "Customer.hpp"

Customer::Customer()
{
    arrivalTime  =0;
    startOfServiceTime = 0;
    departureTime =0;
}

float Customer::getArrivalTime() 
{return arrivalTime;}


float Customer::getStartOfServiceTime() 
{return startOfServiceTime;}

float Customer::getDepartureTime() 
{return departureTime;}
    
void Customer::setArrivalTime(float arrivalTime)
{this->arrivalTime = arrivalTime;}

void Customer::setStartOfServiceTime(float startOfServiceTime) 
{this->startOfServiceTime = startOfServiceTime;}
    
void Customer::setDepartureTime(float departureTime) {this->departureTime = departureTime;} 