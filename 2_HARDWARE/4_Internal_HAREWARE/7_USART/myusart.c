/**--------------------------------
 @function��USART����
 ---------------------------------*/
#include "myusart.h"

/**-----------------------------------
 @template:usart_Init(USART1,bound);
-------------------------------------*/
void usart_Init(USART_TypeDef* USARTx,u32 bound)
{
	//GPIO�˿�����
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
		
		USART_DeInit(USARTx);  //��λ����

    //Usart NVIC ����
    NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//��ռ���ȼ�3
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
		NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
	  //USART ��ʼ������
		USART_InitStructure.USART_BaudRate = bound;//һ������Ϊ9600;
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
		USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
		USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

    USART_Init(USARTx, &USART_InitStructure); //��ʼ������
    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);//�����ж�
    USART_Cmd(USARTx, ENABLE);                    //ʹ�ܴ��� 
}

