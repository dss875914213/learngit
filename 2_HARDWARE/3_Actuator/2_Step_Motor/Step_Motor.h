#ifndef __STEP_MOTOR_H
#define __STEP_MOTOR_H

/*-------------Head files-------------*/
#include "sys.h"
#include "struct.h"

/*-------------declaration of function-------------*/
void Step_Motor_Init(void);
void Control_XY_Move(char Dir);
void Control_Mechanical_Arm_Move(char Dir);
void Control_Pipe_Move(char Dir);
void Step_Motor_Stop(void);

void Go_To_Origin(void);
Coordinate From_Where_To_Where(Coordinate Start,Coordinate End);
char Control_Mechanical_Arm_Location(char now_place,char go_place);
void Control_Pipe_Location(char Dir);

void Get_Pot(void);
void Place_Pot(void);
void Recycle_Pot(void);

/*-------------packaging-------------*/
#define Step_Motor_Dir_1  PAout(4)
#define Step_Motor_Dir_2	PAout(5)
#define Step_Motor_Dir_3	PAout(6)
#define Step_Motor_Dir_4	PAout(7)

#define Mechanical_Arm_Up  		1
#define Mechanical_Arm_Down   0

#define Move_To_Left 		0
#define Move_To_Right 	1
#define Move_To_Forward 2
#define Move_To_Behind 	3

#define Pipe_Up		1
#define Pipe_Down 0

#define Mechanical_Arm_Top		0
#define Mechanical_Arm_Mid		1
#define Mechanical_Arm_Bottom	2




#endif 

