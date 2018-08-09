#include<stdio.h>
#define max 1010
int main()
{
	int num,expon;
	float coef;
	scanf("%d",&num);
	if(num!=0)
	{
		float node[max]={0};///定义数组存放不同指数下系数的和，下标为指数 
		for(int i=0;i<num;i++)
		{
			scanf("%d %f",&expon,&coef);
			node[expon]+=coef;
		}
		scanf("%d",&num);
		for(int i=0;i<num;i++)
		{
			scanf("%d %f",&expon,&coef);
			node[expon]+=coef;
		}	
		num=0;//退出循环 
	
		//计算项数	
		for(int i=0;i<max;i++)
		{
			if(node[i]!=0)
			num++;
		}
		printf("%d",num);
		
		//按照指数从大到小输出 
		for(int i=max-1;i>=0;i--)
		{
			if(node[i]!=0)
			printf(" %d %.1f",i,node[i]);
		}
		printf("\n");
	}
} 
		
