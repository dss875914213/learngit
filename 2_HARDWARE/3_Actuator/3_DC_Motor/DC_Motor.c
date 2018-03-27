/**----------------------------------------
 @function：control DC motor
 @source：TIM2:PA1/2  IO:PA0、PC13/14/15    
------------------------------------------*/
#include "DC_Motor.h"
#include "delay.h"
#include "math.h"
#include "PWM.h"
#include "IO.h"
#include "Canshu.h"

/**--------------------------------
 @input:arr 重装载数 psc 分频数
 @template:Motor_Init(DC_Motor_Limit-1,36-1);
--------------------------------*/
TIM_TypeDef* DC_Motor_TIMx=TIM2;
void DC_Motor_Init(u16 arr,u16 psc)
{
	/*---------------PWM-----------*/
	IO_Output_Init(GPIOA,GPIO_Pin_1|GPIO_Pin_2,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);
	PWM_Init(arr,psc,DC_Motor_TIMx,0,1,1,0);//360M/1k/36=10k
	/*---------------方向IO口----------*/
	IO_Output_Init(GPIOA,GPIO_Pin_0,GPIO_Mode_Out_PP,GPIO_Speed_2MHz);
	IO_Output_Init(GPIOC,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15,GPIO_Mode_Out_PP,GPIO_Speed_2MHz);
}

void Control_Dir(void)
{
	Left_Qian;
	Right_Qian;
}

void Control_Speed(void)
{
	Left_PWM(7000);
	Right_PWM(7000);
}

void Xianfu_Pwm(int *Motor1,int *Motor2)
{	
    if(*Motor1<0) 							 		 *Motor1=0;	
		if(*Motor1>DC_Motor_PWM_Limit)   *Motor1=DC_Motor_PWM_Limit;	
	  if(*Motor2<0) 							 		 *Motor2=0;	
		if(*Motor2>DC_Motor_PWM_Limit)   *Motor2=DC_Motor_PWM_Limit;		
	
}
void Set_Pwm(int moto1,int moto2)
{
	Xianfu_Pwm(&moto1,&moto2);
	Left_PWM(moto1);
	Right_PWM(moto2);
}


