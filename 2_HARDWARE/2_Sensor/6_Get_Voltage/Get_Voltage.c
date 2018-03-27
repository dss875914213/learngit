/**--------------------------------
 @function：use ADC get xxx voltage
 @source：  ADC:PA4
----------------------------------*/

#include "Get_Voltage.h"
#include "ADC.h"

void Get_Voltage_Init(void)
{
	Adc_Init();
}

/**----------
 @unit：mv
-------------*/
int Get_Voltage(void)
{
	#define Battery_Ch 4  //通道
	int Volt;//电池电压
	Volt=Get_Adc(Battery_Ch)*3.3*11.5*100/1.5/4096;	//电阻分压，具体根据原理图简单分析可以得到	
	return Volt;
}
