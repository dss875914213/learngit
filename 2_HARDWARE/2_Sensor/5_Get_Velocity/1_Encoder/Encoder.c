/**----------------------------------
 @function��use encoder get velocity
 @source��  TIM2:PA0/1 TIM4:PB6/7 
-------------------------------------*/

#include "Encoder.h"
#include "Count.h"
#include "IO.h"

/**-----------------------------------
 @note:��TIM2��ʼ��Ϊ�������ӿ�ģʽ
------------------------------------*/
void Encoder_Init_TIM2(void)
{
	IO_Input_Init(GPIOA,GPIO_Pin_0|GPIO_Pin_1,GPIO_Mode_IN_FLOATING);
	Count_Init(TIM2);
}
/**-----------------------------------
 @note����TIM4��ʼ��Ϊ�������ӿ�ģʽ
---------------------------------*/
void Encoder_Init_TIM4(void)
{
	IO_Input_Init(GPIOB,GPIO_Pin_6|GPIO_Pin_7,GPIO_Mode_IN_FLOATING);
	Count_Init(TIM4);
}

/**----------------------------------
 @function����λʱ���ȡ����������
 @input��		��ʱ��
 @output��	�ٶ�ֵ
---------------------------------*/
int Read_Encoder(u8 TIMX)
{
   int Encoder_TIM;    
   switch(TIMX)
	 {
	   case 2:  Encoder_TIM= (short)TIM2 -> CNT;  TIM2 -> CNT=0;break;
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;	
		 case 4:  Encoder_TIM= (short)TIM4 -> CNT;  TIM4 -> CNT=0;break;	
		 default:  Encoder_TIM=0;
	 }
		return Encoder_TIM;
}














