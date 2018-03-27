/**--------------------------------
 @function£ºinit all modules
---------------------------------*/

#include "User.h"
#include "Init.h"

void Init_All(void)
{
	NVIC_Configuration();		 //interrupt
	JTAG_Set(SWD_ENABLE);			//SWD Interface debugging
	delay_init();				
	Actuator_Init();	
	Internal_Hardware_Init(); 
	Interaction_Init();		
	Sensor_Init();						
}




















