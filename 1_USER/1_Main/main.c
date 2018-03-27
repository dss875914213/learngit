/**------------------------------------------
 @function：接收遥控器传输的数据，实现前进，后退，左转，右转，停止，加减速，开关灯
 @start_time：2018/3/23
 @end_time：2018/3/26
------------------------------------------*/

#include "Init.h"
#include "once.h"
#include "while.h"
#include "Canshu.h"

/*-----Global variables(Write down which files use it)---*/
//Interrupt.c
//MPU6050.c
int DC_Motor_PWM=250;//String_Processing.c
u16 USART3_RX_STA;//while.c Interrupt.c
u8 USART3_RX_BUF[USART3_REC_LEN];//while.c Interrupt.c
/*-------------------------------------------------------*/

int main(void)
{
	Init_All();
	
	#if Debug==1
		Once_Debug_Function();
	#elif Release==1
		Once_Realse_Function();
	#endif
	
	/*--------- interrupt(name、function	、Preemption of priority、Sub-priority) ------------
		1.串口中断  USART3_IRQHandler	  3		3
		-----------------------------------------------------------------*/
	while(1)
	{	
		#if Debug==1
			While_Debug_Function();			
		#elif Release==1
			While_Release_Functon();
		#endif	
	}
}

