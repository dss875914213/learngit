/**-----------------------------------------------------------
 @function：1.don't know when happend (or) 2.sensitive to time
------------------------------------------------------------*/

#include "User.h"
#include "Interrupt.h"
#include "Canshu.h"
#include "String_Processing.h"
#include "3_oled.h"

/**--------------------------------
 @function：receive data+handle data
 @note：发送的数据要带回车\r\n
---------------------------------*/
extern u16 USART3_RX_STA;
extern u8 USART3_RX_BUF[USART3_REC_LEN];
void USART3_IRQHandler(void)//串口3中断服务程序
{
	u8 Res;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
		Res =USART_ReceiveData(USART3);//(USART3->DR);	//读取接收到的数据
		
		if((USART3_RX_STA&0x8000)==0)//接收未完成
			{
			if(USART3_RX_STA&0x4000)//接收到了0x0d
				{
					if(Res!=0x0a)USART3_RX_STA=0;//接收错误,重新开始
					else 
					{
						USART3_RX_STA|=0x8000;	//接收完成了
					}
				}
			else //还没收到0X0D
				{	
					if(Res==0x0d)USART3_RX_STA|=0x4000;
					else
					{
						USART3_RX_BUF[USART3_RX_STA&0X3FFF]=Res ;
						USART3_RX_STA++;
						if(USART3_RX_STA>(USART3_REC_LEN-1))USART3_RX_STA=0;//接收数据错误,重新开始接收	  
					}		 
				}
			}   		 
   } 
} 

