/**--------------------------------
 @function��control step motor
 @source��	TIM:A0-A3  IO:A4-A7
---------------------------------*/

#include "Step_Motor.h"
#include "delay.h"
#include "Limit_Switch.h"
#include "Servo.h"
#include "Air_Pump.h"
#include "PWM.h"
#include "IO.h"

/**----------------------------------------
 @function����ʼ�����������PWM�Ϳ��Ʒ����IO
 С�Ĳ������160�ȽϺ�  ��Ĳ������500�Ϻ�   900  
 72000/100/3600=200hz
-------------------------------------------*/
void Step_Motor_Init(void)
{
	/*---------------PWM-----------*/
	IO_Output_Init(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3,GPIO_Mode_AF_PP,GPIO_Speed_50MHz);
	PWM_Init(100/2-1,3600-1,TIM2,1,1,1,1);
	/*---------------����IO��----------*/
	IO_Output_Init(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
}

/*--------------------------------XY������˶�--------------------------------*/

/**--------------------------------
 @function������XY������˶� 
Dir ��ѡ�� Move_To_Left 	��Move_To_Right ��Move_To_Forward��Move_To_Behind 
--------------------------------*/
void Control_XY_Move(char Dir)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	
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

/*------------------------------��е�۵������ƶ�------------------------------*/

/**--------------------------------
 @function�����ƻ�е�۵������˶�
Dir ��ѡ��  Mechanical_Arm_Up ��Mechanical_Arm_Down
--------------------------------*/
void Control_Mechanical_Arm_Move(char Dir)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  
	
	TIM_SetCompare3(TIM2,10);
	Step_Motor_Dir_1=Dir;
}




/*--------------------------------�����ܵ������ƶ�--------------------------------*/

/**--------------------------------
 @function���������ܵ������˶�
Dir ��ѡ�� Pipe_Up �� Pipe_Down
--------------------------------*/
void Control_Pipe_Move(char Dir)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  
	
	TIM_SetCompare1(TIM2,10);
	Step_Motor_Dir_2=Dir;
}


/**--------------------------------
 @function���������ֹͣ
--------------------------------*/

void Step_Motor_Stop(void)
{
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Disable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
}

/**--------------------------------
 @function���ص�ԭ��
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
	//��е�۴�
	Servo_Release();
	
}

/**--------------------------------
 @function�����κε�ȥ�κε㡣�����ؽ���������
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
 @function�����ƻ�е�۵�z��λ�� 
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
	//��ѹ
	Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
	delay_ms_long(8500/2);
	Step_Motor_Stop();
	
		Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
	delay_ms_long(2000);
	Step_Motor_Stop();
	
	Control_XY_Move(Move_To_Left);
	delay_ms(1000);
	Step_Motor_Stop();
	
	//�ص����ϴ�
	Control_Mechanical_Arm_Move(Mechanical_Arm_Up);
	while(Limit_3!=0)
	{
		;
	}
	Step_Motor_Stop();
}

void Place_Pot(void)
{
	//��ѹ
	Control_Mechanical_Arm_Move(Mechanical_Arm_Down);
	delay_ms_long(9500/2);
	Step_Motor_Stop();
	
	//����
	Air_Pump=Air_Pump_On;
	delay_ms_long(7000);
	Air_Pump=Air_Pump_Off;
	
	//�ص����ϴ�
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


