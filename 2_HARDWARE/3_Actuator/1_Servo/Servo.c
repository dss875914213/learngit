/**--------------------------------
 @function��contorl servo(�����
 @source��  TIM3��B0/1
---------------------------------*/

#include "Servo.h"
#include "PWM.h"
#include "IO.h"

/**--------------------------------
 @note��50hz
--------------------------------*/
void Servo_Init(void)// 36000/720/1000 =50hz
{
	IO_Output_Init(GPIOB,GPIO_Pin_0|GPIO_Pin_1,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);
	PWM_Init(720-1,1000-1,TIM3,0,0,1,1);
}

/**--------------------------------
 @function��catch air pump
--------------------------------*/
void Servo_Catch(void)
{
  TIM_SetCompare4(TIM3,95);//75
}

/**--------------------------------
 @function��release air pump
--------------------------------*/
void Servo_Release(void)
{
  TIM_SetCompare4(TIM3,45);
}


	

















