/**--------------------------------
 @function£ºcontrol led
 @source£º  IO:PC13
-----------------------------------*/

#include "1_LED.h"
#include "IO.h"

void LED_Init(void)
{
	IO_Output_Init(GPIOC,GPIO_Pin_13,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
}


