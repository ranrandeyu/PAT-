#include<iostream>
#include<queue>
using namespace std;
//��������
int postorder[40],inorder[40];
 
class node
{
public:
    int data;
    node *left,*right;
};
 
queue<node *> st;
 
node *CreateTree(int n,int *post,int *in)
{
	if(n<=0)
		return NULL;
	//������0��ʼ 
	int k=0;
	//�����е����һλ�Ǹ��ڵ㣬�������Ը��ڵ����һ��֣�kΪ���������ĸ�����n-k-1Ϊ���������ĸ��� 
	while(post[n-1]!=in[k])
		k++;
	node *root=new node;
	root->data=post[n-1];
	//����������
	root->left=CreateTree(k,post,in);
	/*������������post+k���ɺ����������������м���СΪpost��ͷ���+���������ĸ�����
	in+1+k���ɺ�������������д�СΪin��ͷ���+���������ĸ���+�����*/ 
	root->right=CreateTree(n-k-1,post+k,in+1+k);
	return root;
}

int main()
{
	int num,i;
	cin>>num;
	for(i=0;i<num;i++)
		cin>>postorder[i];
	for(i=0;i<num;i++)
		cin>>inorder[i];
	node *root=new node;
	root->left=NULL;
	root->right=NULL;
	root=CreateTree(num,postorder,inorder);
	st.push(root);
	int tag=0;
	while(!st.empty())
	{
		//�½�һ�������нṹ��ָ����е�ͷָ�룬һ��ʼָ����Ŀ�еĸ����4 
		node *tmp=st.front();
		//���ͷָ�������������ڰ��������ĸ����push��� 
		if(tmp->left!=NULL)st.push(tmp->left);
		if(tmp->right!=NULL)st.push(tmp->right);
		//��һ�����ֻ��dataֵ 
		if(tag==0)cout<<tmp->data,tag=1;
		//֮�������ո��dataֵ 
		else cout<<" "<<tmp->data;
		//�����ӣ��Դ˸ı�ͷ������ֵ 
		st.pop();
	}
	return 0;
}
	


