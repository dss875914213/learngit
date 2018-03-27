/**--------------------------------
 @function£ºonly use once
---------------------------------*/

#include "User.h"
#include "once.h"
#include "stdio.h"
#include "1_LED.h"
#include "3_oled.h"
#include "4_Button.h"
#include "Canshu.h"

void Once_Debug_Function(void)
{
	LED=Open_LED;
	//printf("OK\r\n");
	OLED_ShowString(0,7,"OK",12);
	if(Button_1==Pressing_Button)
	{
		OLED_ShowString(0,1,"Button_OK",12);
	}
	Relay=Cut_Relay;
	//Left_Hou
	//Right_Hou
	//Left_PWM(DC_Motor_PWM_Limit/4);
	//Right_PWM(DC_Motor_PWM_Limit/4);
}


void Once_Realse_Function(void)
{
	;
}



