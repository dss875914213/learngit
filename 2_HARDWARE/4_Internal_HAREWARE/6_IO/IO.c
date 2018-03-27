/**--------------------------------
 @function：IO配置
 ---------------------------------*/
 
#include "IO.h"

/**-------------------------------------------------------------------------------------------------------
 @template：IO_Output_Init(GPIOB,GPIO_Pin_0|GPIO_Pin_1,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);
 GPIO_Mode_Out_OD 开漏输出 GPIO_Mode_Out_PP 推挽输出 GPIO_Mode_AF_OD 复用开漏输出 GPIO_Mode_AF_PP 复用推挽输出
---------------------------------------------------------------------------------------------------------*/
void IO_Output_Init(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode,GPIOSpeed_TypeDef GPIO_Speed)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	uint32_t RCC_APB2Periph;
	if(GPIOx==GPIOA)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOA;
	}
	else if(GPIOx==GPIOB)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOB;
	}
	else if(GPIOx==GPIOC)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOC;
	}
	else if(GPIOx==GPIOD)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOD;
	}
	else if(GPIOx==GPIOE)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOE;
	}
	else if(GPIOx==GPIOF)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOF;
	}
	else if(GPIOx==GPIOG)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOG;
	}
	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);  //使能GPIO外设时钟使能
	                                                                     	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;//GPIO_Pin_0-15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;//GPIO_Mode_Out_OD、GPIO_Mode_Out_PP、GPIO_Mode_AF_OD、GPIO_Mode_AF_PP
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed;//GPIO_Speed_2MHz、GPIO_Speed_10MHz、GPIO_Speed_50MHz
	
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}


/**-------------------------------------------------------------------------------------------------------
 @template：IO_Input_Init(GPIOB,GPIO_Pin_0|GPIO_Pin_1,GPIO_Mode_IN_FLOATING);
 GPIO_Mode_AIN 模拟 GPIO_Mode_IN_FLOATING 浮空 GPIO_Mode_IPD 下拉 GPIO_Mode_IPU 上拉
---------------------------------------------------------------------------------------------------------*/
void IO_Input_Init(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	uint32_t RCC_APB2Periph;
	if(GPIOx==GPIOA)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOA;
	}
	else if(GPIOx==GPIOB)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOB;
	}
	else if(GPIOx==GPIOC)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOC;
	}
	else if(GPIOx==GPIOD)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOD;
	}
	else if(GPIOx==GPIOE)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOE;
	}
	else if(GPIOx==GPIOF)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOF;
	}
	else if(GPIOx==GPIOG)
	{
		RCC_APB2Periph=RCC_APB2Periph_GPIOG;
	}
	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);  //使能GPIO外设时钟使能
	                                                                     	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;//GPIO_Pin_0-15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;//GPIO_Mode_AIN、GPIO_Mode_IN_FLOATING、GPIO_Mode_IPD、GPIO_Mode_IPU

	GPIO_Init(GPIOx, &GPIO_InitStructure);
}


