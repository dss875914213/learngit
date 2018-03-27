#ifndef __5_LABVIEW_H
#define __5_LABVIEW_H

/*------------------Head files---------------------*/
#include "sys.h"

/*-------------declaration of function-------------*/
unsigned short CRC_CHECK(unsigned char *Buf, unsigned char CRC_CNT);
void OCS_displayData(float CH1,float CH2,float CH3,float CH4);
//void OutPut_Data(void);

#endif


