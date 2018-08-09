#include<iostream>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b;
	c=a+b;
	int dd;
	scanf("%d",&dd);
	cout<<dd;
	if(c<0)
	{
		c=-c;
		cout<<"-";
	}
	if(c>=1000000)
	{
		printf("%d,%3d,%3d",c/1000000,(c%100000)/1000,c%1000); 
	}
	else if(c>=1000&&c<=999999)
	printf("%d,%3d",c/1000,c%1000);
	else
	printf("%d",c);
	return 0;
}
	
