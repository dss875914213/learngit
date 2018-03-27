/**--------------------------------
 @function：control step motor
 @source：	TIM:A0-A3  IO:A4-A7
---------------------------------*/

#include "Step_Motor.h"
#include "delay.h"
#include "Limit_Switch.h"
#include "Servo.h"
#include "Air_Pump.h"
#include "PWM.h"
#include "IO.h"

/**----------------------------------------
 @function：初始化步进电机的PWM和控制方向的IO
 小的步进电机160比较好  大的步进电机500较好   900  
 72000/100/3600=200hz
-------------------------------------------*/
void Step_Motor_Init(void)
{
	/*---------------PWM-----------*/
	IO_Output_Init(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);
	PWM_Init(100/2-1,3600-1,TIM2,1,1,1,1);
	/*---------------方向IO口----------*/
	IO_Output_Init(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
}

/*--------------------------------XY方向的运动--------------------------------*/

/**--------------------------------
 @function：控制XY方向的运动 
Dir 可选择 Move_To_Left 	、Move_To_Right 、Move_To_Forward、Move_To_Behind 
--------------------------------*/
void Control_XY_Move(char Dir)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);  
	
	TIM_SetCompare2(TIM2,10);
	TIM_SetCompare4(TIM2,10);
	if(Dir==Move_To_Left||Dir==Move_To_Behind)
	{
		Step_Motor_Dir_4=0;
	}
	else if(Dir==Move_To_Right||Dir==Move_To_Forward)
	{
		Step_Motor_Dir_4=1;
	}
	
	if(Dir==Move_To_Left||Dir==Move_To_Forward)
	{
		Step_Motor_Dir_3=1;
	}
	else if(Dir==Move_To_Right||Dir==Move_To_Behind)
	{
		Step_Motor_Dir_3=0;
	}
}

/*------------------------------机械臂的上下移动------------------------------*/

/**--------------------------------
 @function：控制机械臂的上下运动
Dir 可选择  Mechanical_Arm_Up 、Mechanical_Arm_Down
--------------------------------*/
void Control_Mechanical_Arm_Move(char Dir)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  
	
	TIM_SetCompare3(TIM2,10);
	Step_Motor_Dir_1=Dir;
}




/*--------------------------------抽气管的上下移动--------------------------------*/

/**--------------------------------
 @function：控制气管的上下运动
Dir 可选择 Pipe_Up 、 Pipe_Down
--------------------------------*/
void Control_Pipe_Move(char Dir)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  
	
	TIM_SetCompare1(TIM2,10);
	Step_Motor_Dir_2=Dir;
}


/**--------------------------------
 @function：步进电机停止
--------------------------------*/

void Step_Motor_Stop(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
}

/**--------------------------------
 @function：回到原点
--------------------------------*/
void Go_To_Origin(void)
{
	Control_XY_Move(Move_To_Left);
	while(Limit_2!=0)
	{
		;
	}
	Step_Motor_Stop();
	
	Control_XY_Move(Move_To_Forward);
	while(Limit_1!=0)
	{
		;
	}
	Step_Motor_Stop();
	Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
	while(Limit_3!=0)
	{
		;
	}
	Step_Motor_Stop();
	Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
	delay_ms(1000);
	Step_Motor_Stop();
	//机械臂打开
	Servo_Release();
	
}

/**--------------------------------
 @function：从任何点去任何点。并返回结束后坐标
--------------------------------*/
Coordinate From_Where_To_Where(Coordinate Start,Coordinate End)
{
	Coordinate Move;
	Move.x =End.x-Start.x;
	Move.y =End.y-Start.y;
	

	if(Move.y>0)
	{
		Control_XY_Move(Move_To_Behind);
		delay_ms_long(Move.y*500);
	}
	else if(Move.x<0)
	{
		Control_XY_Move(Move_To_Forward);
		delay_ms_long(-Move.y*500);
	}
	Step_Motor_Stop();
	
		if(Move.x>0)
	{
		Control_XY_Move(Move_To_Right);
		delay_ms_long(Move.x*500);
	}
	else if(Move.x<0)
	{
		Control_XY_Move(Move_To_Left);
		delay_ms_long(-Move.x*500);
	}
	Step_Motor_Stop();
	
	return End;
}

/**--------------------------------
 @function：控制机械臂的z轴位置 
--------------------------------*/
char Control_Mechanical_Arm_Location(char now_place,char go_place)
{
	if(now_place==Mechanical_Arm_Top)
	{
		if(go_place==Mechanical_Arm_Mid)
		{
			Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
			delay_ms_long(1000);
			Step_Motor_Stop();
		}
		if(go_place==Mechanical_Arm_Bottom)
		{
			Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
			delay_ms_long(2000);
			Step_Motor_Stop();
		}
	}
	if(now_place==Mechanical_Arm_Mid)
	{
		if(go_place==Mechanical_Arm_Bottom)
		{
			Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
			delay_ms_long(1000);
			Step_Motor_Stop();
		}
	}
	if(now_place==Mechanical_Arm_Bottom)
	{
		if(go_place==Mechanical_Arm_Mid)
		{
			Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
			delay_ms_long(1000);
			Step_Motor_Stop();
		}
	}
	return go_place;
}

void Get_Pot(void)
{
	//下压
	Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
	delay_ms_long(8500/2);
	Step_Motor_Stop();
	
		Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
	delay_ms_long(2000);
	Step_Motor_Stop();
	
	Control_XY_Move(Move_To_Left);
	delay_ms(1000);
	Step_Motor_Stop();
	
	//回到最上处
	Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
	while(Limit_3!=0)
	{
		;
	}
	Step_Motor_Stop();
}

void Place_Pot(void)
{
	//下压
	Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
	delay_ms_long(9500/2);
	Step_Motor_Stop();
	
	//抽气
	Air_Pump=Air_Pump_On;
	delay_ms_long(7000);
	Air_Pump=Air_Pump_Off;
	
	//回到最上处
	Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
	while(Limit_3!=0)
	{
		;
	}
	Step_Motor_Stop();
	
	Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
	delay_ms_long(1000);
	Step_Motor_Stop();
}

void Recycle_Pot(void)
{
//	Control_XY_Move(Move_To_Right);
//	delay_ms_long(1000);
//	Step_Motor_Stop();
	Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
	delay_ms_long(2000);
	Step_Motor_Stop();
	delay_ms_long(2000);
	Servo_Catch();
	delay_ms_long(2000);
	Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
	while(Limit_3!=0)
	{
		;
	}
	Step_Motor_Stop();
}


