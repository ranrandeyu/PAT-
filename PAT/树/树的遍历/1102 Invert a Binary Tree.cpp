#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct tree_key{
	int lkey,rkey;
}key[20];

struct node{
	node *lchild;
	node *rchild;
	int data;
};
//���һ�����ֵ����� 
node *create(int k)
{
	if(k==-1)
	return NULL;
	node *root=new node;
	root->data=k;
	root->lchild=create(key[k].lkey);
	root->rchild=create(key[k].rkey);
	return root;
}
//������������ת�ƺ�Ϊ�Ҹ���
void inorder(node *root,int &n)
{
	if(root==NULL)
	return;
	inorder(root->rchild,n);
	n--;
	if(n==0)printf("%d\n",root->data);
	else
	printf("%d ",root->data);
	inorder(root->lchild,n);
 } 
 //�������
void bfs(node *root,int n)
{
	queue<node *>que;
	que.push(root);
	while(!que.empty()){
	node *p=que.front();
	n--;
	que.pop();
	if(n==0)printf("%d\n",p->data);
	else
	printf("%d ",p->data);
	if(p->rchild)que.push(p->rchild);
	if(p->lchild)que.push(p->lchild);	
	}	
 } 
 
 int main()
 {
 	int n;
 	char left,right;
 	while(scanf("%d",&n)!=EOF)
 	{
 		bool flag[20];
 		int root_key;
 		memset(flag,false,sizeof(flag));
 		for(int i=0;i<20;i++)
 		{
 			key[i].lkey=-1;
 			key[i].rkey=-1;
		}
		for(int i=0;i<n;i++)
		{
			getchar();
			scanf("%c %c",&left,&right);
			if(left!='-'){
				key[i].lkey=left-'0';
				flag[left-'0']=true;
			}
			if(right!='-'){
				key[i].rkey=right-'0';
				flag[right-'0']=true;
			}		
		}
		//�Ҹ����
		for(int i=0;i<n;i++)
		{
			if(!flag[i])
			root_key=i; 
		 } 
		 //����
		 node *root=create(root_key);
		 
		 bfs(root,n);
		 
		 inorder(root,n);
	 }
	 return 0;
 }
