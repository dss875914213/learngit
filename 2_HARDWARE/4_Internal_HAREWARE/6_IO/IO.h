#ifndef __IO_H
#define __IO_H

/*-------------Head files-------------*/
#include "sys.h"

/*-------------declaration of function-------------*/
void IO_Output_Init(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode,GPIOSpeed_TypeDef GPIO_Speed);
void IO_Input_Init(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode);
/*-------------packaging-------------*/


#endif 

