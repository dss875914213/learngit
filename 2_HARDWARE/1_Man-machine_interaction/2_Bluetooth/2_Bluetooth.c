/**--------------------------------
 @function：send/receive data
 @source：  USART3:PB10/11
-----------------------------------*/

#include "1_LED.h"
#include "myusart.h"
#include "IO.h"
#include "Canshu.h" 
 
int fputc(int ch, FILE *f)
{      
	while((USART_fputs->SR&0X40)==0);//循环发送,直到发送完毕   
    USART_fputs->DR = (u8) ch;      
	return ch;
}
/**--------------------------------
 @input： 波特率（b/s）
-----------------------------------*/
void Bluetooth_init(u32 bound)
{
	IO_Output_Init(GPIOB,GPIO_Pin_10,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);//TX
	IO_Input_Init(GPIOB,GPIO_Pin_11,GPIO_Mode_IN_FLOATING);//RX
	usart_Init(USART3,bound);
}


	






















