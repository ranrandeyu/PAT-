/*寻找第一个不同的数字 两个数组，第一个数值嵌套在另一个数组里面计数*/ 
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

