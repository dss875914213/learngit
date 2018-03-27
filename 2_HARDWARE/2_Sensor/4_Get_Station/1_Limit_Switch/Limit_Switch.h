#ifndef __3_LIMIT_SWITCH_H
#define __3_LIMIT_SWITCH_H

/*------------------Head files---------------------*/
#include "sys.h"

/*-------------declaration of function-------------*/
void Limit_Switch_Init(void);

/*-------------packaging-------------*/
#define Limit_1 PAin(8)
#define Limit_2 PBin(15)
#define Limit_3 PBin(14)
#define Limit_4 PBin(13)
#define Limit_5 PBin(12)

#endif 

