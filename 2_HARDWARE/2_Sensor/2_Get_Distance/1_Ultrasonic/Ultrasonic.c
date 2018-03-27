/**--------------------------------------
 @function£ºuse ultrasonic get distance
 @source£º  USART2:PA2/3
----------------------------------------*/

#include "Ultrasonic.h"
#include "myusart.h"
#include "IO.h"

extern u8 high,low;

/**--------------------------------
@note:through usart get data
--------------------------------*/
void Ultrasonic_Init(u32 bound)
{
	IO_Output_Init(GPIOA,GPIO_Pin_2,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//TX
	IO_Input_Init(GPIOA,GPIO_Pin_3,GPIO_Mode_IN_FLOATING);//RX
	usart_Init(USART2,bound);
}

void Get_Distance(void)
{
	if(256*high+low<5000)
	{
		//Distance =256*high1+low1;//mm
	}
} 

