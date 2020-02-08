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
    
    public:
    Customer();
    
    float getArrivalTime();
    float getStartOfServiceTime();
    float getDepartureTime();

    void setArrivalTime(float arrivalTime);
    void setStartOfServiceTime(float startOfServiceTime);
    void setDepartureTime(float departureTime);
    //Customer* nextCust();
};
#endif
