/**-------------------------------------
 @function£ºuse limit switch get station
 @source£º	IO:A8¡¢B12-B15
----------------------------------------*/

#include "Limit_Switch.h"
#include "IO.h"

void Limit_Switch_Init(void)
{
	IO_Input_Init(GPIOA,GPIO_Pin_8,GPIO_Mode_IPU);
	IO_Input_Init(GPIOB,GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15,GPIO_Mode_IPU);
}



