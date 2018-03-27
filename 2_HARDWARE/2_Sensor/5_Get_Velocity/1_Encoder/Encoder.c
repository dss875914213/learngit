/**----------------------------------
 @function：use encoder get velocity
 @source：  TIM2:PA0/1 TIM4:PB6/7 
-------------------------------------*/

#include "Encoder.h"
#include "Count.h"
#include "IO.h"

/**-----------------------------------
 @note:把TIM2初始化为编码器接口模式
------------------------------------*/
void Encoder_Init_TIM2(void)
{
	IO_Input_Init(GPIOA,GPIO_Pin_0|GPIO_Pin_1,GPIO_Mode_IN_FLOATING);
	Count_Init(TIM2);
}
/**-----------------------------------
 @note：把TIM4初始化为编码器接口模式
---------------------------------*/
void Encoder_Init_TIM4(void)
{
	IO_Input_Init(GPIOB,GPIO_Pin_6|GPIO_Pin_7,GPIO_Mode_IN_FLOATING);
	Count_Init(TIM4);
}

/**----------------------------------
 @function：单位时间读取编码器计数
 @input：		定时器
 @output：	速度值
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














