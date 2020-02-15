#include "Statistics.hpp"
#include <cmath>
#include <iomanip>


Statistics::Statistics()
{
    numOfArrivals =0;
    lambda =0;
    mu =0;
    M =0;
}
Statistics::Statistics(double numOfArrivals, double lambda, double mu, double M)
{
    this->numOfArrivals = numOfArrivals;
    this->lambda = lambda;
    this->mu = mu;
    this->M = M;
}

double Statistics::factorial(double num)
{   
    double factorial= 1;
    
    for(int i=1; i <= num; ++i)
    factorial *=i;
    return factorial;
}

double Statistics::Po()
{
    double Po =0;
    double firstHalf =0;
    double secondHalf =0;
    double thirdHalf =0;

    for(int i=0; i <= M-1; i++)
    {
        firstHalf += 1/factorial(i) * std::pow((lambda/mu), i);
    }

    secondHalf =  1/factorial(M);  // * std::pow((lambda/mu) , M) );
    //std::cout << secondHalf << "\n";
    secondHalf *= std::pow((lambda/mu), M);
    thirdHalf = (M * mu) / (M * mu - lambda);
    //std::cout << firstHalf << " " << secondHalf << " " << thirdHalf;
    Po = firstHalf + (secondHalf * thirdHalf);
    Po = 1/Po;

    return Po;
}

double Statistics::L()
{
    double L =0;
    double Po = Statistics::Po();
    double firstHalf =0;
    double secondHalf =0;

    firstHalf = (lambda*mu); // std::pow((lambda/mu) , M);
    firstHalf *= std::pow((lambda/mu) , M);
    secondHalf = factorial(M-1);
    secondHalf *= std::pow((M * mu - lambda) , 2);
  
    L = (firstHalf/secondHalf);
    L *= Po; 
    L += (lambda/mu);
        //std::cout << L;

    return L;
}

double Statistics::W()
{
    double L = Statistics::L();
    double W =0;
    
    W= L/lambda;
    return W;
}

double Statistics::Lq()
{
    double Lq =0;

    double L = Statistics::L();
    std::ostringstream os;
    
    Lq = L - (lambda/mu);
    os << std::setprecision(2) << Lq;
    std::string holder = os.str();
    Lq = std::stod(holder);

    return Lq;
}

double Statistics::Wq()
{
    double W = Statistics::W();
    double Wq = W - (1/mu);
    std::ostringstream os;


    os << std::setprecision(3) << Wq;
    std::string holder = os.str();
    Wq = std::stod(holder);
    return Wq;
}

