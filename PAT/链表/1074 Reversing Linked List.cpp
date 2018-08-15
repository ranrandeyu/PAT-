/*已知链表，给定一个数字，按照0-n倒序输出
1）先排序，赋值给list 
2）再逆转得到 result
不一定给的数据都是有用，所以加一个计数器*/ 

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
	//利用前一个结点的next与后一个结点的first一样，将first作为中间变量 
	while(first!=-1)
	{
		list[count++]=first; 
		first=next[first];
	}
	for(int i=0;i<count;i++)
	{
		result[i]=list[i];
	}
	//此方法为考虑到后面需要逆序的情况 
	
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
