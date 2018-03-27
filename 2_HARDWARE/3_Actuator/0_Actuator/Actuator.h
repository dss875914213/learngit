#ifndef __Actuator_H
#define __Actuator_H

/*-------------Head files-------------*/
#include "sys.h"

/*---------Actuator head files---------*/
#include "Relay.h"
#include "DC_Motor.h"

/*---------declaration of function---------*/
void Actuator_Init(void);
void Control_Actuator(void);

#endif 
