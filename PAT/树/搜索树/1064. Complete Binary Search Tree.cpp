/* ����n�������Ƚ�����ȫ������������ٰ��չ�����ȱ���ÿһ����� 
��Ϊ��ȫ����������Ľ������ͨ����������ķ�ʽʵ�֡�
����ֻ��Ҫ���źõ����а������򴢴沢���������*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,a[1001],b[1001],num=0;
void dfs(int index)
{
	 if(index>=n)
    {
        num++;
       // printf("qianindex:%d\n",index);
        return;
    }
    dfs(2*index+1);
    b[index]=a[num-1];
    //printf("num-1:%d\n",num-1);
   // printf("index:%d\n",index);
    dfs(2*index+2);
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{	
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		dfs(0);
		for(int i=0;i<n-1;i++)
		{
			printf("%d ",b[i]);
		}
		printf("%d",b[n-1]);
	}
	return 0;
}
