#include "PID.h"

using namespace std;
#include <iostream>
#include <cmath>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init() {
    Kp = -0.1;    //-0.034;
    Ki = -0.0001;
    Kd = -1.0 ;   //1.4 * pow(Kp, 2.0);  
    cte_int = 0.0;
    cte_old = 0.0;
}

double PID::CalculateSteering(double cte, double speed) {
    
    // initialize variables
    double steering, D_cte; 
    
    cout << "cte_old=" << cte_old << "; cte_int=" << cte_int << "; Kd=" << Kd << endl;
    
    // calculate integral and differential cte terms
    cte_int = cte_int + cte;
    D_cte = cte - cte_old;
    cte_old = cte;
    
    // Calculate steering angle
    // Use speed to modify Kp gain, except when speed is below tolerance
    if (speed < 1.0E-5){
        steering = Kp*cte + Ki*cte_int + Kd*D_cte;
    } else {
        steering = Kp*cte + Ki*cte_int + Kd*D_cte;
        //steering = Kp/speed*cte + Ki*cte_int + Kd*D_cte;
    }
    
    //cout << "Gains (KpKiKd): " << Kp << Ki << Kd << endl;
    
    // return the steering angle
    return steering;
}

double PID::CalculateThrottle(double cte, double speed) { 
    
    //init variables
    double throttle;
    double gain = 0.5;
    double desired_speed = 25.0;
    
    // Put in speed controller
    throttle = gain * (desired_speed - speed); // - (abs(cte)/3.0);
    
    if (throttle > 1.0){
        throttle = 1.0;
    }
    if (throttle < -1.0){
        throttle = -1.0;
    }
    
    // return desired throttle
    return throttle;
}

