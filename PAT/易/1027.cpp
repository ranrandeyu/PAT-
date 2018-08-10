#include<stdio.h>
int main()
{
	char color[14]={"0123456789ABC"};
	char a[6];
	char b[6];
	for(int i=0;i<3;i++)
	{
		int num;
		scanf("%d",&num);
		a[i]=color[num/13];
		b[i]=color[num%13];
	}
	printf("#");
	for(int i=0;i<3;i++)
	{
		printf("%c%c",a[i],b[i]);
	}
	return 0;
}
