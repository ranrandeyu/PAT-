/*整数计算各位的总和，列出位数总和 */ 
#include<iostream>
#define max 37//数据范围是10000，最大为9999，散列表开到37即可 
using namespace std;
int t[max];
int count=0;

void caculate(int num)
{
	int sum=0;
	while(num)
	{
		sum=sum+num%10;
		num=num/10;
	}
	if(t[sum]==1)//相加和被标记过 
	return;
	else//相加和未被标记过 
	{
		t[sum]=1;
		count++;
	}
 } 
 
 int main()
 {
 	int n;
 	cin>>n;
 	int figure;
 	for(int i=0;i<n;i++)
 	{
 		cin>>figure;
 		caculate(figure);
	}
	cout<<count<<endl;
	
	bool flag=false;//控制格式的输出 
	for(int i=0;i<max;i++)
	{
		if(t[i]==1)
		{
			if(flag==false)
			{
				cout<<i;
				flag=true;
			}
			else
			cout<<" "<<i;
		}
	}
	return 0;
  } 
