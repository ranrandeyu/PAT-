/*���룺�����ĿN�ͷ�Ҷ�ӽ����ĿM
M�У� ��Ҷ�ӽ���ID ���Ӹ���K ���ӵ�ID[i]
����� ÿ��Ҷ�ӽ��ĸ��� */
#include<stdio.h>
int n,noleaf,k,father,child,a[101],v[101],count[101],level=0,maxlevel=0,flag=-1;
 //��ȱ��� 
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
	//��ʼ��
	for(int i=0;i<100;i++)
	{
		a[i]=-1;
		count[i]=0;
		v[i]=0;
	}
	//���� 
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

