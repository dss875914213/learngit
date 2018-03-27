/**--------------------------------
 @function£ºActuaor
 @source£º
---------------------------------*/

#include "Actuator.h"
#include "Canshu.h"

void Actuator_Init(void)
{
	Relay_Init();
	DC_Motor_Init(DC_Motor_PWM_Limit-1,36-1);
}

void Control_Actuator(void)
{
	
}











