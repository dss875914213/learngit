#ifndef __DC_MOTOR_H
#define __DC_MOTOR_H

/*-------------Head files-------------*/
#include "sys.h"

/*-------------declaration of function-------------*/

void DC_Motor_Init(u16 arr,u16 psc);
void Control_Dir(void);
void Control_Speed(void);
void Xianfu_Pwm(int *Motor1,int *Motor2);
void Set_Pwm(int moto1,int moto2);		
	
extern TIM_TypeDef* DC_Motor_TIMx;
/*-------------packaging-------------*/
#define IN1   PAout(0)
#define IN2   PCout(14)
#define IN3   PCout(13)
#define IN4   PCout(15)

#define Left_Qian   IN4=0,IN3=1
#define Left_Hou    IN4=1,IN3=0
#define Left_Stop   IN4=0,IN3=0
#define Right_Qian  IN1=0,IN2=1
#define Right_Hou   IN1=1,IN2=0
#define Right_Stop  IN1=0,IN2=0
#define Stop {Left_Stop Right_Stop}

#define Left_PWM(pwm)  TIM_SetCompare2(DC_Motor_TIMx,pwm)
#define Right_PWM(pwm) TIM_SetCompare3(DC_Motor_TIMx,pwm)

#endif 
