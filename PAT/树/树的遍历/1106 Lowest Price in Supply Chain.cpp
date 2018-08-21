/*遍历&&dbs 
提供经销商（树），生产商为根结点，给出生产商的价格以及比率r，每一级价格都会张r%
求经销商（叶子节点）最低销售（层级越少），并算出有多少人卖这样的价格 */ 

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
	//没有孩子结点，即叶子结点 
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	

