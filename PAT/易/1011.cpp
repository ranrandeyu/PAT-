#include<stdio.h>
#define time 3
char choice[3]={'W','T','L'};//������˫���ţ���Ȼ�����too many initializers����� 
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
		last[i]=choice[index];	///%cһ���ַ���%sһ���ַ� 
	}
	for(int i=0;i<3;i++)
	printf("%c ",last[i]);
	printf("%.2f",(sum*0.65-1)*2);
	return 0;
}



