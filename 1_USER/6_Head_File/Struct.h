#ifndef __STRUCT_H
#define __STRUCT_H

/*---------坐标位置 单位cm---------*/
typedef struct 
{
	float x;
	float y;
	float z;
}S_Coordinate;

/*--------电机控制---------*/
typedef struct
{
	int PWM;
	int Dir;
}S_Motor_Control;

#endif 

