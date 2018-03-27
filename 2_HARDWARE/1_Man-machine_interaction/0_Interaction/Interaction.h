#ifndef __INTERACTION_H
#define __INTERACTION_H

/*-------------Head files-------------*/
#include "sys.h"

/*---------interaction head files---------*/
#include "1_LED.h"
#include "2_Bluetooth.h"
#include "3_oled.h"
#include "4_Button.h"

/*-------------declacration of funtion-------------*/
void Interaction_Init(void);
void OLED_Show(void);
int Click_Key(void);




#endif 






