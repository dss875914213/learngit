/**--------------------------------
 @function：USART配置
 ---------------------------------*/
#include "myusart.h"

/**-----------------------------------
 @template:usart_Init(USART1,bound);
-------------------------------------*/
void usart_Init(USART_TypeDef* USARTx,u32 bound)
{
	//GPIO端口设置
		USART_InitTypeDef USART_InitStructure;
		NVIC_InitTypeDef NVIC_InitStructure;
	  uint8_t USARTx_IRQn;
		if(USARTx==USART1)
		{
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
			USARTx_IRQn=USART1_IRQn;
		}
		else if(USARTx==USART2)
		{
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
			USARTx_IRQn=USART2_IRQn;
		}
		else if(USARTx==USART3)
		{
			RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
			USARTx_IRQn=USART3_IRQn;
		}
		
		USART_DeInit(USARTx);  //复位串口

    //Usart NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
		NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
  
	  //USART 初始化设置
		USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
		USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
		USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

    USART_Init(USARTx, &USART_InitStructure); //初始化串口
    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);//开启中断
    USART_Cmd(USARTx, ENABLE);                    //使能串口 
}

