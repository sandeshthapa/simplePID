#include <iostream>

using namespace std; 

class PID
{
private:
    double Kp; 
    double Kd; 
    double Ki;
    double state;
    
public:
    PID(/* args */);
    ~PID();

    double computeForce(double & state, double & desired ); 
    void setGains(double Kp_, double Kd_, double Ki_); 
    void setState(double x_); 
};

PID::PID()
{
    Kd  = 0.0; 
    Kp = 0.0; 
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

void PID::setGains(double Kp_, double Kd_, double Ki_)
{
    Kp = Kp_; 
    Kd = Kd_; 
    Ki = Ki_; 
}

void PID::setState(double x_)
{
    state = x_; 

}

int main()
{
    PID pid; 

    double Ki_g = 0.0; 
    double Kp_g = 1.0; 
    double Kd_g = 0.01; 

    pid.setGains(Kp_g, Kd_g, Ki_g); 

    double X = 1.0; 
    pid.setState(X); 

    double desX = 0.5; 

   double output =  pid.computeForce(X, desX); 

   std::cout << "pid out "<< output << std::endl; 

    return 0; 
}