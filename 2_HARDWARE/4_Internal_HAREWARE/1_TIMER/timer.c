/**--------------------------------
 @function����ʱ������
 @source��	TIM3
 ---------------------------------*/
 
#include "timer.h"

/**-----------------------------------------------------------------
 @note:��Ҫ����ʱ������Ҫ��
 TIMx RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); TIM3_IRQn
-------------------------------------------------------------------*/
void Timer_Init(u16 arr,u16 psc,TIM_TypeDef* TIMx)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	uint8_t TIMx_IRQn;
	
	if(TIMx==TIM1)//TIM1��TIM8��APB2 TIM2-TIM7��APB1 
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		//TIMx_IRQn=TIM1_IRQn;
	}
	else if(TIMx==TIM2)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
		TIMx_IRQn=TIM2_IRQn;
	}
	else if(TIMx==TIM3)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		TIMx_IRQn=TIM3_IRQn;
	}
	else if(TIMx==TIM4)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
		TIMx_IRQn=TIM4_IRQn;
	}
	else if(TIMx==TIM5)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
		//TIMx_IRQn=TIM5_IRQn;
	}
	else if(TIMx==TIM6)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
		//TIMx_IRQn=TIM6_IRQn;
	}
	else if(TIMx==TIM7)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
		//TIMx_IRQn=TIM7_IRQn;
	}
	else if(TIMx==TIM8)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
		//TIMx_IRQn=TIM8_IRQn;
	}

	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������5000Ϊ500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(  //ʹ�ܻ���ʧ��ָ����TIM�ж�
		TIMx, //TIMx
		TIM_IT_Update ,
		ENABLE  //ʹ��
		);
	NVIC_InitStructure.NVIC_IRQChannel = TIMx_IRQn;  //TIMx�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

	TIM_Cmd(TIMx, ENABLE);  //ʹ��TIMx����
}













