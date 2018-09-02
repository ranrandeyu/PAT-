/*两组数据的排序sort*/ 
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct student{
	char id[19];
	int score;
	int number;
	int local_rank;
	int all_rank;
}stu[30001];

bool cmp(student a,student b)
{
	if(a.score!=b.score)
	return a.score>b.score;
	else return strcmp(a.id,b.id)<0;//id从低到高 
}

int main()
{
	int n,k,num=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>stu[num].id>>stu[num].score;
			stu[num].number=i+1;
			num++;
		}
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].local_rank=1;
		for(int l=num-k+1;l<num;l++)
		{
			if(stu[l].score==stu[l-1].score)
			stu[l].local_rank=stu[l-1].local_rank;
			else
			stu[l].local_rank=l+1-num+k; 
		}
	}
	sort(stu,stu+num,cmp);
	stu[0].all_rank=1;
	for(int i=0;i<num;i++)
	{
		if(stu[i].score==stu[i-1].score)
		stu[i].all_rank=stu[i-1].all_rank;
		else
		stu[i].all_rank=i+1;
	 } 
	cout<<num<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<stu[i].id<<" "<<stu[i].all_rank<<" "<<stu[i].number<<" "<<stu[i].local_rank<<endl;
	}	
	return 0;	
 } 
