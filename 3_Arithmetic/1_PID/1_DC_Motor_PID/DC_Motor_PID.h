#ifndef __DC_MOTOR_PID_H
#define __DC_MOTOR_PID_H

/*------------------Head files---------------------*/
#include "sys.h"

/*-------------declaration of function-------------*/
int balance(float Angle,float Gyro);
int velocity(int encoder_left,int encoder_right);



#endif 

