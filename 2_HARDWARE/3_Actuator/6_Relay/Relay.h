#ifndef __RELAY_H
#define __RELAY_H

/*---------system head file---------*/
#include "sys.h"

/*-------------declaration of function-------------*/
void Relay_Init(void);

/*-------------packaging-------------*/
#define Relay  PAout(5)

#define Closure_Relay  1  //�պ�
#define Cut_Relay 		 0	//�Ͽ�

#endif 
