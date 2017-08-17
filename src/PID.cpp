#include "PID.h"

using namespace std;
#include <iostream>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init() {
    double cte_int, cte_old;
    Kp = -0.1;
    Ki = 0.0; //0.0001;
    Kd = -0.01; //-0.001;
    cte_int = 0.0;
    cte_old = 0.0;
}

double PID::CalculateSteering(double cte, double speed) {
    
    // initialize variables
    double steering, cte_int, D_cte, cte_old; 
    
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

double PID::CalculateThrottle(double speed) { 
    
    //init variables
    double throttle;
    double gain = 0.1;
    double desired_speed = 10.0;
    
    // Put in speed controller
    throttle = gain * (desired_speed - speed);
    
    // return desired throttle
    return throttle;
}

