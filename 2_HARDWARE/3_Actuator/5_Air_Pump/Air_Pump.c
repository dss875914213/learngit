/**--------------------------------
 @function£ºcontrol air pump
 @source£º	IO:A15
---------------------------------*/

#include "Air_Pump.h"
#include "IO.h"

void Air_Pump_Init(void)
{
	IO_Output_Init(GPIOB,GPIO_Pin_0|GPIO_Pin_1,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);
}

