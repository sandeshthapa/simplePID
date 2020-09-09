#include <iostream>

using namespace std; 

class PID
{
private:
    /* data */
public:
    PID(/* args */);
    ~PID();

    double Kp; 
    double Kd; 
    double Ki; 

    double computeForce(double & state, double & desired ); 
};

PID::PID(/* args */)
{
    Kd  = 0.01; 
    Kp = 1; 
    Ki =0.0; 
}

PID::~PID()
{
}

double PID::computeForce(double & state , double & desired)
{
    double error = desired - state; 
    double prev_err = 0.0 ; 
    double sum_err = 0.0 ; 

    double computeForce_ ; 
    
    computeForce_ = Kp*error + Kd*prev_err + Ki*sum_err; 

    prev_err = error; 

    sum_err += error; 

    if (sum_err > 0.5)
    {
        sum_err = 0.0; 
    }
    
    return computeForce_; 
}

int main()
{
    PID pid; 

    pid.Ki = 0.0; 
    pid.Kp = 1.0; 
    pid.Kd = 0.01; 

    double X = 1.0; 
    double desX = 0.5; 

   double output =  pid.computeForce(X, desX); 

   std::cout << "pid out "<< output << std::endl; 

    return 0; 
}