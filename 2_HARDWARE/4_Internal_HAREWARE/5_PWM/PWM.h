#ifndef __PWM_H
#define __PWM_H

/*-------------Head files------------*/
#include "sys.h"

/*-------declaration of function-----*/
void PWM_Init(u16 arr,u16 psc,TIM_TypeDef* TIMx,char ch1,char ch2,char ch3,char ch4);

/*-------------packaging-------------*/


#endif 

