/*����&&dbs 
�ṩ�����̣�������������Ϊ����㣬���������̵ļ۸��Լ�����r��ÿһ���۸񶼻���r%
�����̣�Ҷ�ӽڵ㣩������ۣ��㼶Խ�٣���������ж������������ļ۸� */ 

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> t[100001];
int mindepth=99999,minnum=1;

void dfs(int index,int depth)
{
	if(mindepth<depth)
	{
		return;
	}
	//û�к��ӽ�㣬��Ҷ�ӽ�� 
	if(t[index].size()==0)
	{
		if(mindepth==depth)
		{
			minnum++;	
		} 
		else if(mindepth>depth)
		{
			mindepth=depth;
			minnum=1;
		}
	}
	for(int i=0;i<t[index].size();i++)
	dfs(t[index][i],depth+1);
}

int main()
{
	int n,k,c;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&c);
			t[i].push_back(c);
		}
	}
	dfs(0,0);
	printf("%.4f %d",p*pow(1+r/100,mindepth),minnum);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	

