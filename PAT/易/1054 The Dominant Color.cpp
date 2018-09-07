#include<iostream>
#include<map>
using namespace std;
#define max 800
int main()
{
	int m,temp=0,n;
	map<int,int>b;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&temp);
			b[temp]++;
			if(b[temp]>(m*n/2))
			{
				printf("%d",temp);
				return 0;
			}
		}
	}
	return 0;
}

