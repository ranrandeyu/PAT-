#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector> 
using namespace std; 

struct people{
	int id;
	int virtue;
	int talent;
}peo;

vector<people>a,b,c,d;

bool cmp(people a,people b)
{
	if(a.virtue+a.talent!=b.virtue+b.talent)
	return (a.virtue+a.talent)>(b.virtue+b.talent);
	else
	{
		if(a.virtue!=b.virtue)
			return a.virtue>b.virtue;
		else 
			return b.id>a.id;//从低到高 
	 } 
}
int main()
{
	int num,min,high;
	int count=0,sage=0,fool=0;
	scanf("%d%d%d",&num,&min,&high);
	for(int i=0;i<num;i++)
	{
		scanf("%d%d%d",&peo.id,&peo.virtue,&peo.talent);
		//排除的人 
		if (peo.virtue<min||peo.talent<min)
		{
			continue;
		}
		//圣人 
		if(peo.virtue>=high&&peo.talent>=high)
		{
			a.push_back(peo);
		}
		//君子 
		else if(peo.virtue>=high&&peo.talent<high)
		{
			b.push_back(peo);
		} 
		//愚人 
		else if(peo.virtue<high&&peo.talent<high&&peo.virtue>=peo.talent)
		{	
			c.push_back(peo);
		}
		//小人
		else
			d.push_back(peo);
		count++;
	} 
	cout<<count<<endl;
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++)
	{
		printf("%d %d %d\n",a[i].id,a[i].virtue,a[i].talent);	
	} 	
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<b.size();i++)
	{
		printf("%d %d %d\n",b[i].id,b[i].virtue,b[i].talent);	
	} 
	sort(c.begin(),c.end(),cmp);
	for(int i=0;i<c.size();i++)
	{
		printf("%d %d %d\n",c[i].id,c[i].virtue,c[i].talent);	
	} 		
	sort(d.begin(),d.end(),cmp);
	for(int i=0;i<d.size();i++)
	{
		printf("%d %d %d\n",d[i].id,d[i].virtue,d[i].talent);	
	} 					
	return 0;
}

