/*遍历&&dbs 
提供经销商（树），生产商为根结点，给出生产商的价格以及比率r，每一级价格都会张r%
求经销商（叶子节点）最高销售（层级越多），并算出有多少人卖这样的价格 */ 

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> t[100001];
int n,maxdepth=0,maxnum=0; 

void dfs(int index,int depth)
{
	//没有孩子结点，即叶子结点 
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	

