/* 根据选项排序，choice=1：按照id升序
choice=2：按照name从a-z，name一样按照id升序
choice=3：按照grade不降序，grade一样按照id升序*/ 

#include<iostream>
#include <algorithm>
#include<string.h>
using namespace std;
const int maxn = 100001; ///定义为max，出现[Error] reference to 'max' is ambiguous
//NODE 定义的结构体类型，node为结构体数组（变量） 
struct NODE{
	int id,grade;
	char name[10];
}node[maxn];

int choice;
int cmp(NODE a, NODE b)
{
	if (choice==1)
	{
		return a.id<b.id;
	}
	else if(choice==2)
	{
		if(strcmp(a.name,b.name)==0)
		return a.id<b.id;
		//strcmp比较的是ACSII码，a<z 
		return strcmp(a.name,b.name)<=0;
	}
	else{
		if(a.grade==b.grade)return a.id<b.id;
		return a.grade<=b.grade;
	}
}


int main()
{
	int num;
	scanf("%d %d",&num,&choice);
	for(int i=0;i<num;i++)
	{
		scanf("%d %s %d",&node[i].id,&node[i].name,&node[i].grade);
	}
	sort(node,node+num,cmp);
	for(int i=0;i<num;i++)
	{
		printf("%06d %s %d\n",node[i].id,node[i].name,node[i].grade);
	}
	return 0;
}
 

