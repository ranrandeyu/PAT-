/* ����ѡ������choice=1������id����
choice=2������name��a-z��nameһ������id����
choice=3������grade������gradeһ������id����*/ 

#include<iostream>
#include <algorithm>
#include<string.h>
using namespace std;
const int maxn = 100001; ///����Ϊmax������[Error] reference to 'max' is ambiguous
//NODE ����Ľṹ�����ͣ�nodeΪ�ṹ�����飨������ 
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
		//strcmp�Ƚϵ���ACSII�룬a<z 
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
 

