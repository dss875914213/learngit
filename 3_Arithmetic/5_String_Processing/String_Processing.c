/**-------------------------
 @function��handle string
--------------------------*/

#include "String_Processing.h"
#include "string.h"
#include "1_LED.h"
#include "Relay.h"
#include "3_oled.h"
#include "DC_Motor.h"

extern int DC_Motor_PWM;

/**--------------------------------------------
 @function��handle data obtained via Bluetooth 
---------------------------------------------*/
void String_Match(u16 *status,u8 *buf)
{
	char Aid_Key_String[4][10]={"Acc","Dec","Stp","Lgt"};
	char Dir_Key_String[4][10]={"Forward","Backward","Left","Right"};
	buf[(*status)&0X3FFF]='\0'; //���һ���ֽں���ӽ�����
	OLED_ShowString_Clear_Hang(0,2,(char *)buf,12);
	if(strcmp((const char*)buf,Aid_Key_String[0])==0)
	{
		//����
		DC_Motor_PWM+=10;
		Set_Pwm(DC_Motor_PWM,DC_Motor_PWM);
	}
	else if(strcmp((const char*)buf,Aid_Key_String[1])==0)
	{
		//����
		DC_Motor_PWM-=10;
		Set_Pwm(DC_Motor_PWM,DC_Motor_PWM);
	}
	else if(strcmp((const char*)buf,Aid_Key_String[2])==0)
	{
		//ֹͣ
		Left_Stop;
		Right_Stop;
	}
	else if(strcmp((const char*)buf,Aid_Key_String[3])==0)
	{
		//���ص�
		Relay=!Relay;
	}
	else if(strcmp((const char*)buf,Dir_Key_String[0])==0)
	{
		//ǰ��
		Left_Qian;
		Right_Qian;
	}
	else if(strcmp((const char*)buf,Dir_Key_String[1])==0)
	{
		//����	
		Left_Hou;
		Right_Hou;	
	}
	else if(strcmp((const char*)buf,Dir_Key_String[2])==0)
	{
		//��ת
		Left_Hou;
		Right_Qian;
	}
	else if(strcmp((const char*)buf,Dir_Key_String[3])==0)
	{
		//��ת
		Left_Qian;
		Right_Hou;
	}
	*status=0;//״̬λ��0
}








