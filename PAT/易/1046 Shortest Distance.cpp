/*ģ�⻷�����ҳ���С����  swap��������  */ 
#include<iostream>
using namespace std;
int dist[100001],sum[100001],result[100001];
int main()
{
	int num,total;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		cin>>dist[i];
		total+=dist[i];
		sum[i]=sum[i-1]+dist[i];
	}
	int n,a,b;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a<b)
		swap(a,b);
		int temp=sum[a-2]-sum[b-2];//��ʼ��0��ʼ��13֮��ľ������D1+D2 
		result[i]=min(temp,total-temp);
	}
	for(int i=0;i<n;i++)
	{
		cout<<result[i]<<endl;
	}
	return 0;
}
