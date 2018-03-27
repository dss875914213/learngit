/**--------------------------------
 @function：interaction
 @source：
	LED  									  PC13
	key 										PB9
	OLED 										PB5-8
	bluetooth 				     	PB10/11
------------------------------------------*/

#include "Interaction.h"

void Interaction_Init(void)
{
	LED_Init();
	Bluetooth_init(115200);
	OLED_Init();
	Button_Init();
}


/**--------------------------------
 @showdata:
	0			xx
	1			xx
	2			xx
	3			xx
	4			xx
	5			xx
	6			xx
	7			xx
-----------------------------*/
void OLED_Show(void)
{
	OLED_ShowString(0,0,(char *)"OK",12);
}


/**--------------------------------
 @function:通过按键选择
----------------------------------*/
int Click_Key(void)
{
	if(Button_1==Pressing_Button)
	{
		delay_ms(20);
		if(Button_1==Pressing_Button)
		{
			return 1;
		}
	}
	return 0;
}














