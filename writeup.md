
Controller
A PID controller was implemented for the steering. 

steering = Kp*cte + Ki*cte_int + Kd*D_cte;

A simple proportional only P-controller was used for adjusting throttle to achieve the desired speed. 

throttle = gain * (desired_speed - speed);


Gain Tuning
First, set the Kp gain such that there are small oscillations with a small overshoot on the straightaway. Then, add a Kd gain to smooth out the overshoot. The integral term is including as needed, when windup error is observed. 

For the speed controller, a proportional gain of 0.1 was used. 

Cases that successfully navigated the course:
Kp = -0.1; Ki = 0.0; Kd = -0.01; gain = 0.1; desired_speed = 10.0;
-0.1, 0.0, -0.01, 0.1, 20.0
