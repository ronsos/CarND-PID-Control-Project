#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init();

  /*
  * Find the steering angle given cross track error.
  */
  double CalculateSteering(double cte, double speed);

  /*
  * Calculate the total PID error. NOT USED
  */
  double CalculateThrottle(double speed);
};

#endif /* PID_H */
