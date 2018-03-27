/**--------------------------------
 @function��PWM����
 ---------------------------------*/

#include "PWM.h"


/**--------------------------------
 @note��IO������������
 @template��PWM_Init(1440-1,1000-1,TIM1,RCC_APB2Periph_TIM1,1,1,0,0);
--------------------------------*/
void PWM_Init(u16 arr,u16 psc,TIM_TypeDef* TIMx,char ch1,char ch2,char ch3,char ch4)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	/*----------------------ʹ��----------------------------*/
	if(TIMx==TIM1)//TIM1��TIM8��APB2 TIM2-TIM7��APB1 
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	}
	else if(TIMx==TIM2)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	}
	else if(TIMx==TIM3)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	}
	else if(TIMx==TIM4)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	}
	else if(TIMx==TIM5)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	}
	else if(TIMx==TIM6)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
	}
	else if(TIMx==TIM7)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);
	}
	else if(TIMx==TIM8)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);
	}
	/*--------------------------------TIM��ʼ��--------------------------------*/
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

  /*--------------------------------ͨ����ʼ��--------------------------------*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ը�
	
	/*---------------------------------ͨ��ѡ��--------------------------------*/
	if(ch1==1)
	{
		TIM_OC1Init(TIMx, &TIM_OCInitStructure);
	}
	if(ch2==1)
	{
		TIM_OC2Init(TIMx, &TIM_OCInitStructure);
	}
	if(ch3==1)
	{
		TIM_OC3Init(TIMx, &TIM_OCInitStructure);
	}
	if(ch4==1)
	{
		TIM_OC4Init(TIMx, &TIM_OCInitStructure);
	}
	
	TIM_CtrlPWMOutputs(TIMx,ENABLE);	//MOE �����ʹ��	
	
	/*---------------------------------ͨ��Ԥװ��--------------------------------*/
	if(ch1==1)
	{
		TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);
	}
	if(ch2==1)
	{
		TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
	}
	if(ch3==1)
	{
		TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);
	}
	if(ch4==1)
	{
		TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);
	}
	
	TIM_ARRPreloadConfig(TIMx, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(TIMx, ENABLE);  //ʹ��TIM3
}


