#include<reg51.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define out1 P2
#define out2 P3
uchar code seg[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void delayms(uint);
void main()
{
uchar i=0;
while(1)
{
for(i=0;i<59;i++)
{
out1=seg[i/10];
out2=seg[i%10];
delayms(300);
}
}
}
void delayms(uint j)
{
uchar i;
for(;j>0;j--)
{
i=250;
while(--i);
i=249;
while(--i);
}
}

