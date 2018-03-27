/**--------------------------------
 @function：PWM配置
 ---------------------------------*/

#include "PWM.h"


/**--------------------------------
 @note：IO口在外面配置
 @template：PWM_Init(1440-1,1000-1,TIM1,RCC_APB2Periph_TIM1,1,1,0,0);
--------------------------------*/
void PWM_Init(u16 arr,u16 psc,TIM_TypeDef* TIMx,char ch1,char ch2,char ch3,char ch4)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	/*----------------------使能----------------------------*/
	if(TIMx==TIM1)//TIM1和TIM8是APB2 TIM2-TIM7是APB1 
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
	/*--------------------------------TIM初始化--------------------------------*/
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

  /*--------------------------------通道初始化--------------------------------*/
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //输出极性:TIM输出比较极性高
	
	/*---------------------------------通道选择--------------------------------*/
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
	
	TIM_CtrlPWMOutputs(TIMx,ENABLE);	//MOE 主输出使能	
	
	/*---------------------------------通道预装载--------------------------------*/
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
	
	TIM_ARRPreloadConfig(TIMx, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(TIMx, ENABLE);  //使能TIM3
}


