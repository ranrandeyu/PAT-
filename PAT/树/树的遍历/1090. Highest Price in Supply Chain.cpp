/*����&&dbs 
�ṩ�����̣�������������Ϊ����㣬���������̵ļ۸��Լ�����r��ÿһ���۸񶼻���r%
�����̣�Ҷ�ӽڵ㣩������ۣ��㼶Խ�ࣩ��������ж������������ļ۸� */ 

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> t[100001];
int n,maxdepth=0,maxnum=0; 

void dfs(int index,int depth)
{
	//û�к��ӽ�㣬��Ҷ�ӽ�� 
	if(t[index].size()==0)
	{
		if(maxdepth==depth)
		{
			maxnum++;	
		} 
		else if(maxdepth<depth)
		{
			maxdepth=depth;
			maxnum=1;
		}
		return ;
	}
	for(int i=0;i<t[index].size();i++)
	dfs(t[index][i],depth+1);
}

int main()
{
	int n,temp,root;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp==-1)
			root=i;
		else	
			t[temp].push_back(i);
		
	}
	dfs(root,0);
	printf("%.2f %d",p*pow(1+r/100,maxdepth),maxnum);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

