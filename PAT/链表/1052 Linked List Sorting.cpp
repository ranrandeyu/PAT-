#include<iostream>
///�Զ���cmp,sort���������ļ�
#include<algorithm>
using namespace std;
struct node
{
	int add,data,next;
};
node print[100001],link[100001];

///a.data<b.data�򷵻�1����������0
int cmp(node a,node b)
{
	return a.data<b.data;
}

int main()
{
	int num,first,y;
	int k=0;
	cin>>num>>first;
	///����ǰһ��next��ֵ����һ��add��ֵ��ȵ���������add��Ϊ�±�
	for(int i=0;i<num;i++)
	{
		cin>>y;
		cin>>print[y].data>>print[y].next;
		print[y].add=y;
	}
	
	while(first!=-1)
	{
		link[k++]=print[first];
		first=print[first].next;
	}
	//sort(������������ʼ��ַ,������ַ�����򷽷�)
	sort(link,link+num,cmp);
	
	if(k==0)
	{
		cout<<0<<" "<<-1<<endl;
		return 0;
	}
	
	printf("%d %05d\n",k,link[0].add);
	for(int i=0;i<k-1;i++)
	printf("%05d %d %05d\n",link[i].add,link[i].data,link[i+1].add);
	printf("%05d %d %d\n",link[k-1].add,link[k-1].data,-1);
	return 0;
}






















