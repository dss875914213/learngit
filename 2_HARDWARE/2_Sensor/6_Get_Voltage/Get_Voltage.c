/**--------------------------------
 @function��use ADC get xxx voltage
 @source��  ADC:PA4
----------------------------------*/

#include "Get_Voltage.h"
#include "ADC.h"

void Get_Voltage_Init(void)
{
	Adc_Init();
}

/**----------
 @unit��mv
-------------*/
int Get_Voltage(void)
{
	#define Battery_Ch 4  //ͨ��
	int Volt;//��ص�ѹ
	Volt=Get_Adc(Battery_Ch)*3.3*11.5*100/1.5/4096;	//�����ѹ���������ԭ��ͼ�򵥷������Եõ�	
	return Volt;
}
