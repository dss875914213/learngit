#include "delay.h"
#include "sys.h"

static u8  fac_us=0;//us��ʱ������
static u16 fac_ms=0;//ms��ʱ������

/*--------------��ʱ��ʼ��-------------*/
void delay_init()	 
{

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//ѡ���ⲿʱ��  HCLK/8
	fac_us=SystemCoreClock/8000000;	//Ϊϵͳʱ�ӵ�1/8  
	fac_ms=(u16)fac_us*1000;//��ucos��,����ÿ��ms��Ҫ��systickʱ����  
}								    

/*-------------΢�뼶��ʱ-------------*/		    								   
void delay_us(u32 nus)
{		
	u32 temp;	 
	int save_time=0;
	char flag=0;
	/*-----��ֹ����delay�໥���--------*/
	temp=SysTick->CTRL;
	if(temp&0x01&&!(temp&(1<<16)))
	{
		flag=1;
		save_time=(SysTick->VAL-((nus)*fac_us));
	}
	
	SysTick->LOAD=nus*fac_us; //ʱ�����	  		 
	SysTick->VAL=0x00;        //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	 
	
		if(1==flag&&save_time>0)
	{
		SysTick->LOAD=save_time;
		SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����
	}
}

/*--------���뼶��ʱ����72M������,nms<=1864��--------*/
void delay_ms(u16 nms)
{	 		  	  
	u32 temp=0;
	int save_time=0;
	char flag=0;
	/*-------��ֹ����delay�໥���-------*/
	temp=SysTick->CTRL;
	if(temp&0x01&&!(temp&(1<<16)))
	{
		flag=1;
		save_time=(SysTick->VAL-((nms)*fac_ms));
	}		
	
	SysTick->LOAD=(u32)nms*fac_ms;//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;           //��ռ�����
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����	  	
	
	if(1==flag&&save_time>0)
	{
		SysTick->LOAD=save_time;
		SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //��ʼ����
	}

} 

/*-------���뼶��ʱ��û����ʱʱ�����ƣ�-------*/
void delay_ms_long(u16 nms)
{
	int i=nms/1000;
	int j=nms%1000;
	while(i--)
	{
		delay_ms(1000);
	}
	if(j!=0)
	{
		delay_ms(j);
	}
	
}

































