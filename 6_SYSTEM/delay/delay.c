#include "delay.h"
#include "sys.h"

static u8  fac_us=0;//us延时倍乘数
static u16 fac_ms=0;//ms延时倍乘数

/*--------------延时初始化-------------*/
void delay_init()	 
{

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//选择外部时钟  HCLK/8
	fac_us=SystemCoreClock/8000000;	//为系统时钟的1/8  
	fac_ms=(u16)fac_us*1000;//非ucos下,代表每个ms需要的systick时钟数  
}								    

/*-------------微秒级延时-------------*/		    								   
void delay_us(u32 nus)
{		
	u32 temp;	 
	int save_time=0;
	char flag=0;
	/*-----防止两个delay相互打断--------*/
	temp=SysTick->CTRL;
	if(temp&0x01&&!(temp&(1<<16)))
	{
		flag=1;
		save_time=(SysTick->VAL-((nus)*fac_us));
	}
	
	SysTick->LOAD=nus*fac_us; //时间加载	  		 
	SysTick->VAL=0x00;        //清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //开始倒数	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //关闭计数器
	SysTick->VAL =0X00;       //清空计数器	 
	
		if(1==flag&&save_time>0)
	{
		SysTick->LOAD=save_time;
		SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //开始倒数
	}
}

/*--------毫秒级延时（对72M条件下,nms<=1864）--------*/
void delay_ms(u16 nms)
{	 		  	  
	u32 temp=0;
	int save_time=0;
	char flag=0;
	/*-------防止两个delay相互打断-------*/
	temp=SysTick->CTRL;
	if(temp&0x01&&!(temp&(1<<16)))
	{
		flag=1;
		save_time=(SysTick->VAL-((nms)*fac_ms));
	}		
	
	SysTick->LOAD=(u32)nms*fac_ms;//时间加载(SysTick->LOAD为24bit)
	SysTick->VAL =0x00;           //清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //开始倒数  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;       //关闭计数器
	SysTick->VAL =0X00;       //清空计数器	  	
	
	if(1==flag&&save_time>0)
	{
		SysTick->LOAD=save_time;
		SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;          //开始倒数
	}

} 

/*-------毫秒级延时（没有延时时间限制）-------*/
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

































