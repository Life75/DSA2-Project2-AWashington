#ifndef STATISTICS_HPP_
#define STATISTICS_HPP_

#include <iostream>
#include <sstream>

class Statistics 
{
    private:
        double numOfArrivals; //number of arrivals to simulate
        double lambda; // average arrivals in a time period
        double M; //number of service channels
        double mu; //average number seerved in a time period 
        double PoNum;

    public: 
        Statistics();
        Statistics(double numOfArrivals, double lambda, double mu, double M);
        double factorial(double num);
        void setPo(double PoNum);
        double Po();
        double L();
        double W();
        double Lq();
        double Wq();
        double Rho();


};
#endif