/*Ѱ�ҵ�һ����ͬ������ �������飬��һ����ֵǶ������һ�������������*/ 
#include<iostream> 
using namespace std;
int main()
{
	int a[10000],m[10000];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	m[a[i]]++;
 	} 
 	for(int i=0;i<n;i++)
 	{
 		if(m[a[i]]==1)
 		{
 			printf("%d\n",a[i]);
 			return 0;
		 }
	 }
	 printf("None");
	 return 0;
}

