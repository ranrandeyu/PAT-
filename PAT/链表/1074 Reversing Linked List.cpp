/*��֪��������һ�����֣�����0-n�������
1�������򣬸�ֵ��list 
2������ת�õ� result
��һ���������ݶ������ã����Լ�һ��������*/ 

#include<iostream>
using namespace std;
int main()
{
	int first,k,n,count=0;
	cin>>first>>n>>k;
	int temp,data[100005],next[100005];
	int list[100005],result[100005];
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		cin>>data[temp]>>next[temp]; 
	}
	//����ǰһ������next���һ������firstһ������first��Ϊ�м���� 
	while(first!=-1)
	{
		list[count++]=first; 
		first=next[first];
	}
	for(int i=0;i<count;i++)
	{
		result[i]=list[i];
	}
	//�˷���Ϊ���ǵ�������Ҫ�������� 
	
	/*for(int i=0;i<k;i++)
	{
		result[i]=list[k-1-i];
	}
	for(int i=k;i<count;i++)
	{
		result[i]=list[i];
	 } */
	 for (int i = 0; i < (count - count % k); i++)
        result[i] = list[i / k * k + k - 1 - i % k]; 
	for(int i=0;i<count-1;i++)
	{
		printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);
	}
 	printf("%05d %d -1",result[count-1],data[result[count-1]]);
 return 0;
}
