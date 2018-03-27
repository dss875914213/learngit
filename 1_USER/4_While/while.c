/**--------------------------------------------------------
 @function£º1.work all the time (and) 2.insensitive to time
---------------------------------------------------------*/

#include "User.h"
#include "while.h"
#include "delay.h"
#include "stdio.h"
#include "Canshu.h"
#include "String_Processing.h"

extern u16 USART3_RX_STA;
extern u8 USART3_RX_BUF[USART3_REC_LEN];

void While_Debug_Function(void)
{
	int Vol=0;
	Vol=Get_Voltage();
	if(Vol/100<9&&Vol/100>5)
	{
		OLED_ShowString(0,0,"!!V is too low",16);
		OLED_ShowString(0,2,"!!V is too low",16);
		OLED_ShowString(0,4,"!!V is too low",16);
		OLED_ShowString(0,6,"!!V is too low",16);
		OLED_Clear();
	}
	else
	{
		OLED_ShowNum_Float_12Size(0,0,Vol/100.0,2,2);
	}	
	if(USART3_RX_STA&0x8000)
	{
		String_Match(&USART3_RX_STA,USART3_RX_BUF);	
	}
}


void While_Release_Functon(void)
{
	int Vol=0;
	Vol=Get_Voltage();
	if(Vol/100<9&&Vol/100>5)
	{
		OLED_ShowString(0,0,"!!V is too low",16);
		OLED_ShowString(0,2,"!!V is too low",16);
		OLED_ShowString(0,4,"!!V is too low",16);
		OLED_ShowString(0,6,"!!V is too low",16);
		OLED_Clear();
	}
	else
	{
		OLED_ShowNum_Float_12Size(0,0,Vol/100.0,2,2);
	}	
	if(USART3_RX_STA&0x8000)
	{
		String_Match(&USART3_RX_STA,USART3_RX_BUF);	
	}
	if(Button_1==Pressing_Button)
	{
		Relay=!Relay;
	}
}







