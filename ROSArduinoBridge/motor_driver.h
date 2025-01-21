/* **************************************************************
   Motor driver function definitions - by James Nugen
   ************************************************************ */

#ifdef L298_MOTOR_DRIVER
  #define RIGHT_MOTOR_BACKWARD 5
  #define LEFT_MOTOR_BACKWARD  6
  #define RIGHT_MOTOR_FORWARD  9
  #define LEFT_MOTOR_FORWARD   10
  #define RIGHT_MOTOR_ENABLE 12
  #define LEFT_MOTOR_ENABLE 130
#elif defined(TB6612FNG_MOTOR_DRIVER)
  // Right motor: Motor A
  #define RIGHT_MOTOR_BACKWARD 17
  #define RIGHT_MOTOR_FORWARD  21
  #define RIGHT_PWM_CONTROL    25
  // Left motor: Motor B
  #define LEFT_MOTOR_BACKWARD  23
  #define LEFT_MOTOR_FORWARD   22
  #define LEFT_PWM_CONTROL     26
  // PWM Settings
  #define PWM_FREQUENCY        5000
  #define PWM_RESOLUTION       8
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);