/**--------------------------------
 @function������ֱ������˶�
--------------------------------*/

#include "DC_Motor_PID.h"

/*--------------------------------
���ܣ�ʹ��PD����ʹС��ƽ��
���룺float Angle,float Gyro
�����Balance��PWM��
���õĺ�������
--------------------------------*/
int balance(float Angle,float Gyro)
{  
   static float Bias;
	 float kp=150,kd=0.8; //140 0.7
	 int Balance;
	 Bias=Angle-0;       //===���ƽ��ĽǶ���ֵ �ͻ�е���
	 Balance=(int)(kp*Bias+(Gyro)*kd);   //===����ƽ����Ƶĵ��PWM  PD����   kp��Pϵ�� kd��Dϵ�� 
	 return Balance;
}

/*--------------------------------
���ܣ�ʹ��PI����ʹС������
���룺int encoder_left,int encoder_right
�����Velocity��PWM��
���õĺ�������
--------------------------------*/
int velocity(int encoder_left,int encoder_right)
{  
//		static float Velocity,Encoder_Least,Encoder,Movement;
//		static float Encoder_Integral;//Target_Velocity
//		float kp=100,ki=kp/200;

//	 //=============�ٶ�PI������=======================//	
//		Encoder_Least =(Encoder_Left+Encoder_Right)-0;                    //===��ȡ�����ٶ�ƫ��==�����ٶȣ����ұ�����֮�ͣ�-Ŀ���ٶȣ��˴�Ϊ�㣩 
//		Encoder *= 0.7;		                                                //===һ�׵�ͨ�˲���       
//		Encoder += Encoder_Least*0.3;	                                    //===һ�׵�ͨ�˲���    
//		Encoder_Integral +=Encoder;                                       //===���ֳ�λ�� ����ʱ�䣺10ms
//		Encoder_Integral=Encoder_Integral-Movement;                       //===����ң�������ݣ�����ǰ������
//		if(Encoder_Integral>10000)  Encoder_Integral=10000;               //===�����޷�
//		if(Encoder_Integral<-10000)	Encoder_Integral=-10000;              //===�����޷�	
//		Velocity=Encoder*kp+Encoder_Integral*ki;                          //===�ٶȿ���	
//		if(Angle_Balance<-40||Angle_Balance>40){													//��Ϊ���ٶ�ͻ�䣬����ֵҲ��Ҫͻ�䣨�ٶ�Ϊ��ʱ������ͻ���Ϊ���Ӧ������ʵӦ����ͣ������ʱ��ű��㣨����Ƿ����ƶ�����
//			Encoder_Integral=0;
//		}
//    return Velocity;
	return 0;
}

