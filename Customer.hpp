#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

#include <iostream>
#include <sstream>
/*
Customer class in charge of making the actual customers, this object serves to contain the customer's arrival time, start of service time
and departure time. The function getTime simply gets the current time and finds if its either a departure event or an arrival event
*/
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
