/*输入：结点数目N和非叶子结点数目M
M行： 非叶子结点的ID 孩子个数K 孩子的ID[i]
输出： 每层叶子结点的个数 */
#include<stdio.h>
int n,noleaf,k,father,child,a[101],v[101],count[101],level=0,maxlevel=0,flag=-1;
 //深度遍历 
 void dfs(int x){
 	for(int i=x+1;i<=n;i++)
	 {
	 	if(v[i]==0&&a[i]==x)
	 	{
	 		level++;
	 		if(level>maxlevel)
	 		maxlevel=level;
	 		flag=i;
	 		dfs(i);
	 		v[i]=1;
			level--; 
		}
	} 
	if(flag==x)
	count[level]++;
 	
 }
int main()
{    
	scanf("%d %d",&n,&noleaf);
	//初始化
	for(int i=0;i<100;i++)
	{
		a[i]=-1;
		count[i]=0;
		v[i]=0;
	}
	//输入 
	for(int i=0;i<noleaf;i++){
		scanf("%d %d",&father,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			a[child]=father; 
		}	
	}
	

	if(n!=1){
		v[1]=1;
		dfs(1);
		printf("%d",count[0]);
		for(int i=1;i<=maxlevel;i++)
		{
		printf(" %d",count[i]);
		}
	}
	else printf("1\n");
	return 0;	
 } 

