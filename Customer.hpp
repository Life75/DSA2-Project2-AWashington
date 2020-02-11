#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

#include <iostream>
#include <sstream>
//banner
class Customer 
{
    private:
    float arrivalTime;
    float startOfServiceTime;
    float departureTime;
    Customer* next;
    
    public:
    Customer();
    Customer(Customer* next);
    double getArrivalTime();
    double getStartOfServiceTime();
    double getDepartureTime();
    double getTime();

    void setArrivalTime(float arrivalTime);
    void setStartOfServiceTime(float startOfServiceTime);
    void setDepartureTime(float departureTime);
    Customer* nextCust();
    
};
#endif
