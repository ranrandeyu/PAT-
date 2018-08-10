#include<stdio.h>
#define time 3
char choice[3]={'W','T','L'};//不能用双引号，不然会出现too many initializers的情况 
char last[time];
int main()
{
	int index;
	double sum=1.0,max,a;
	for(int i=0;i<3;i++)
	{
		max=0.0;
		for(int j=0;j<3;j++)
		{
			scanf("%lf",&a);
			if(a>max)
			{
				max=a;
				index=j;
			}
		}
		sum*=max;
		last[i]=choice[index];	///%c一个字符，%s一串字符 
	}
	for(int i=0;i<3;i++)
	printf("%c ",last[i]);
	printf("%.2f",(sum*0.65-1)*2);
	return 0;
}



