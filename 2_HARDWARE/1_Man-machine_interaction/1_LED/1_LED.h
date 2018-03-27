#ifndef __1_LED_H
#define __1_LED_H

/*------------------Head files---------------------*/
#include "sys.h"

/*-------------declaration of funtion-------------*/
void LED_Init(void);

/*-------------packaging-------------*/
#define LED  PCout(13)

#define Open_LED  0
#define Close_LED 1

#endif 

