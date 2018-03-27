/**--------------------------------
 @function£ºcontrol relay(¼ÌµçÆ÷£©
 @source£º	IO:PA5
---------------------------------*/

#include "Relay.h"
#include "IO.h"

void Relay_Init(void)
{
	IO_Output_Init(GPIOA,GPIO_Pin_5,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
}

