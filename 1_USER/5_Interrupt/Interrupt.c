/**-----------------------------------------------------------
 @function��1.don't know when happend (or) 2.sensitive to time
------------------------------------------------------------*/

#include "User.h"
#include "Interrupt.h"
#include "Canshu.h"
#include "String_Processing.h"
#include "3_oled.h"

/**--------------------------------
 @function��receive data+handle data
 @note�����͵�����Ҫ���س�\r\n
---------------------------------*/
extern u16 USART3_RX_STA;
extern u8 USART3_RX_BUF[USART3_REC_LEN];
void USART3_IRQHandler(void)//����3�жϷ������
{
	u8 Res;
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
		Res =USART_ReceiveData(USART3);//(USART3->DR);	//��ȡ���յ�������
		
		if((USART3_RX_STA&0x8000)==0)//����δ���
			{
			if(USART3_RX_STA&0x4000)//���յ���0x0d
				{
					if(Res!=0x0a)USART3_RX_STA=0;//���մ���,���¿�ʼ
					else 
					{
						USART3_RX_STA|=0x8000;	//���������
					}
				}
			else //��û�յ�0X0D
				{	
					if(Res==0x0d)USART3_RX_STA|=0x4000;
					else
					{
						USART3_RX_BUF[USART3_RX_STA&0X3FFF]=Res ;
						USART3_RX_STA++;
						if(USART3_RX_STA>(USART3_REC_LEN-1))USART3_RX_STA=0;//�������ݴ���,���¿�ʼ����	  
					}		 
				}
			}   		 
   } 
} 

