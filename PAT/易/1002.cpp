#include<stdio.h>
#define max 1010
int main()
{
	int num,expon;
	float coef;
	scanf("%d",&num);
	if(num!=0)
	{
		float node[max]={0};///���������Ų�ָͬ����ϵ���ĺͣ��±�Ϊָ�� 
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
		num=0;//�˳�ѭ�� 
	
		//��������	
		for(int i=0;i<max;i++)
		{
			if(node[i]!=0)
			num++;
		}
		printf("%d",num);
		
		//����ָ���Ӵ�С��� 
		for(int i=max-1;i>=0;i--)
		{
			if(node[i]!=0)
			printf(" %d %.1f",i,node[i]);
		}
		printf("\n");
	}
} 
		
