#include <iostream>

using namespace std; 

class PID
{
private:
    double Kp; 
    double Kd; 
    double Ki;
    double state;
    double desX; 
    
public:

    // Constructor 
    PID();
    ~PID();

    double computeForce( ); 
    void setGains(double Kp_, double Kd_, double Ki_); 
    void setState(double x_); 
    void setdesX(double desx_); 

};