/*��֪���ſεĳɼ����ó�ƽ���֣��������ĸ���������
�ó�ÿ��ѧ��������ǰ�������Լ���Ŀ����������ͬ������£�
����A>C>M>E����������ǰ��id�����������N/A*/ 
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct student{
	int id;
	int grade[4];
}stu[2010];

int now=0;
char ch[4]={'A','C','M','E'};

bool cmp(student s1,student s2)
{
	return s1.grade[now]>s2.grade[now];//�Ӵ�С����
}

int main()
{
	int n,m,num,index=-1,last=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
		stu[i].grade[0]=(stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3])/3.0+0.5;
	}
	//�����У�ACME�����ս�������
	for(now=0;now<4;now++)
	{
		sort(stu,stu+n,cmp);
		last=stu[0].grade[now];//��¼�óɼ������ɼ����бȽ��Ƿ����
		stu[0].grade[now]=1;//���ɼ��ı�Ϊ����
		//��һ������stu[i].grade[0]={1,2,3,3,5}
		for (int i=1;i<n;i++)
		{
			if(stu[i].grade[now]==last)
			{
				stu[i].grade[now]=i;
			}
			else
			{
				last=stu[i].grade[now];
				stu[i].grade[now]=i+1;
			}
		}
	}
	//��ÿ��stu��������С����
	for(int i=0;i<m;i++)
	{
		scanf("%d",&num);
		for(int j=0;j<n;j++)
		{
			if(stu[j].id==num)
			{
				index=j;
				break;
			}
		}
		if(index==-1)printf("N/A\n");
		else
		{
			int k=0;
			for(int p=0;p<4;p++)
			{
				if(stu[index].grade[p]<stu[index].grade[k])
				{
					k=p;
				}
			}
			printf("%d %c\n",stu[index].grade[k],ch[k]);
			index=-1;
		}
	}
	return 0;
}
	

