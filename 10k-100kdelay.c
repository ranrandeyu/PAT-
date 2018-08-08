#include "STC15Fxxxx.h"  
#include "config.h"
///占空比有关定义
//频率调节有关定义
#define			Main_Fosc			11059200
//#define 		Divide_K			4
//#define 		Frequent			20000//输出频率可调范围50hz-10khz
#define         duty_step           0x1a

unsigned int step;
unsigned int duty;
unsigned int Frequent = 20000;//输出频率可调范围50hz-10khz

//								   一、 二、      四、      六、      八、                十二
//unsigned int divide[13] = {0xFF,0x88,0x82,0xFF,0x8A,0xFF,0x8C,0xFF,0x8E,0XFF,0xFF,0xFF,0x80};


sbit KEY1=P4^0;///按键状态，‘1’为弹起态，‘0’按下态，增加占空比
sbit KEY2=P4^1;///按键状态，‘1’为弹起态，‘0’按下态，减小占空比
sbit KEY3=P4^2;///按键状态，‘1’为弹起态，‘0’按下态，增加频率
sbit KEY4=P4^3;///按键状态，‘1’为弹起态，‘0’按下态，减小频率

void Delay250ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 11;
	j = 130;
	k = 111;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void setFrequent()
{
	step 			= (Main_Fosc)/2/Frequent;
	CMOD=0x82;
	CCON=0;
	CL=0;
	CH=0;
	duty = step;
	CCAP0L=duty;
	CCAP0H=duty>>8;
	CCAPM0=0x42;
	CR=1;
}

void main()
{
	KEY1=1;
	KEY2=1;
	KEY3=1;
	KEY4=1;
	P1M1 = 0x00;	P1M0 = 0x00;	
	P4M1 = 0x00;	P4M0 = 0x00;	
	
	setFrequent();
	EA=1;
	
	while(1)
	{
		//增加占空比
		if(KEY1 == 0)
		{	
			CCAP0H=duty;
			duty+=duty_step;
			Delay250ms();
		}
		
		///增加频率
		if(KEY3 == 0)
		{			
			Delay250ms();
			CR=0;
			Frequent += 1000;
			setFrequent();
		}
		///减小频率
		if(KEY4 == 0)
		{
			CR=0;
			Frequent -= 1000;
			duty			= (Main_Fosc)/2/Frequent;
			Delay250ms();
			CCAP0L=duty;
			CCAP0H=duty>>8;
			CCAPM0=0x42;
			CR=1;
		}
		
		
	}
}

void PCA() interrupt 7
{
	CCF0=0;
	duty+=step;
	CCAP0L=duty;
	CCAP0H=duty>>8;
}
