/*���������λ���ܺͣ��г�λ���ܺ� */ 
#include<iostream>
#define max 37//���ݷ�Χ��10000�����Ϊ9999��ɢ�б���37���� 
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
	if(t[sum]==1)//��Ӻͱ���ǹ� 
	return;
	else//��Ӻ�δ����ǹ� 
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
	
	bool flag=false;//���Ƹ�ʽ����� 
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
