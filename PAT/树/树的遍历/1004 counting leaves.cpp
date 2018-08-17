/*输入：结点数目N和非叶子结点数目M
M行： 非叶子结点的ID 孩子个数K 孩子的ID[i]
输出： 每层叶子结点的个数 */
#include<stdio.h>
int v[101],count[101],k1,n,m,a[101],layer=0,maxlevel=0;
void dfs(int x)
{
	int i; 
	for(i=x+1;i<=n;i++)
	{
		if(a[i]==x&&v[i]==0)
		{
			layer++;
			//printf("layer:%d\n",layer);
			if(maxlevel<layer)maxlevel=layer;
			k1=i;
			//printf("k1:%d\n",k1);
			dfs(i);
			v[i]=1;
			//printf("i:%d\n",i);
			layer--;
		    //printf("layer:%d\n",layer);
		}
	}
	if(x==k1)
//	printf("k1:%d\n",k1);
	count[layer]++;
//	printf("layer:%d\n",layer);}
}
int main()
{
	int father,k,child;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<100;i++)
	{
		v[i]=0;
		count[i]=-1;
		a[i]=-1;
	}
	
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&father,&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&child);
			a[child]=father;
		}
	}
	
	if(n!=1)
	{
		v[1]=1;
		dfs(1);
		printf("%d",count[0]+1);
	//	printf("v[0]:%d\n",v[0]);
		for(int i=1;i<=maxlevel;i++)
		{
			printf(" %d",count[i]+1);
	//		printf("v[0]: %d\n",v[i]);
		}
		
	}else printf("1\n");
	return 0;
}
	
	
		
