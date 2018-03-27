/**--------------------------------
 @function£ºclick button
 @source£º	IO:PB9
-----------------------------------*/

#include "4_Button.h"
#include "IO.h"

/**--------------------------------
 @function£º°´¼ü³õÊ¼»¯
----------------------------------*/
void Button_Init(void)
{
	IO_Input_Init(GPIOB,GPIO_Pin_9,GPIO_Mode_IPU);
}



