/**--------------------------------
 @function：控制直流电机运动
--------------------------------*/

#include "DC_Motor_PID.h"

/*--------------------------------
功能：使用PD调节使小车平衡
输入：float Angle,float Gyro
输出：Balance（PWM）
调用的函数：无
--------------------------------*/
int balance(float Angle,float Gyro)
{  
   static float Bias;
	 float kp=150,kd=0.8; //140 0.7
	 int Balance;
	 Bias=Angle-0;       //===求出平衡的角度中值 和机械相关
	 Balance=(int)(kp*Bias+(Gyro)*kd);   //===计算平衡控制的电机PWM  PD控制   kp是P系数 kd是D系数 
	 return Balance;
}

/*--------------------------------
功能：使用PI调节使小车匀速
输入：int encoder_left,int encoder_right
输出：Velocity（PWM）
调用的函数：无
--------------------------------*/
int velocity(int encoder_left,int encoder_right)
{  
//		static float Velocity,Encoder_Least,Encoder,Movement;
//		static float Encoder_Integral;//Target_Velocity
//		float kp=100,ki=kp/200;

//	 //=============速度PI控制器=======================//	
//		Encoder_Least =(Encoder_Left+Encoder_Right)-0;                    //===获取最新速度偏差==测量速度（左右编码器之和）-目标速度（此处为零） 
//		Encoder *= 0.7;		                                                //===一阶低通滤波器       
//		Encoder += Encoder_Least*0.3;	                                    //===一阶低通滤波器    
//		Encoder_Integral +=Encoder;                                       //===积分出位移 积分时间：10ms
//		Encoder_Integral=Encoder_Integral-Movement;                       //===接收遥控器数据，控制前进后退
//		if(Encoder_Integral>10000)  Encoder_Integral=10000;               //===积分限幅
//		if(Encoder_Integral<-10000)	Encoder_Integral=-10000;              //===积分限幅	
//		Velocity=Encoder*kp+Encoder_Integral*ki;                          //===速度控制	
//		if(Angle_Balance<-40||Angle_Balance>40){													//人为让速度突变，积分值也需要突变（速度为零时与比例和积分为零对应）（其实应该在停下来的时候才变零（如果是反向制动））
//			Encoder_Integral=0;
//		}
//    return Velocity;
	return 0;
}

