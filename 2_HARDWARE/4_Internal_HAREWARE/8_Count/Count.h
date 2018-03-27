#ifndef __COUNT_H
#define __COUNT_H 

/*------------------Head files---------------------*/
#include "sys.h"

/*-------------declaration of function-------------*/
void Count_Init(TIM_TypeDef* TIMx);
	
/*-------------------packaging---------------------*/
#define ENCODER_TIM_PERIOD (u16)(65535)

#endif 

