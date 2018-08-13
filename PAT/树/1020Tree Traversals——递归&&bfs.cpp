#include<iostream>
#include<queue>
using namespace std;
//后序、中序
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
	//序数从0开始 
	int k=0;
	//后序中的最后一位是根节点，在中序以根节点左右划分，k为左子树结点的个数，n-k-1为右子树结点的个数 
	while(post[n-1]!=in[k])
		k++;
	node *root=new node;
	root->data=post[n-1];
	//建立左子树
	root->left=CreateTree(k,post,in);
	/*建立右子树，post+k理解成后右子树结点后序排列即大小为post的头结点+左子树结点的个数，
	in+1+k理解成后右子树结点排列大小为in的头结点+左子树结点的个数+根结点*/ 
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
		//新建一个链队列结构，指向队列的头指针，一开始指向题目中的根结点4 
		node *tmp=st.front();
		//如果头指针有左子树，在把左子树的根结点push入队 
		if(tmp->left!=NULL)st.push(tmp->left);
		if(tmp->right!=NULL)st.push(tmp->right);
		//第一次输出只有data值 
		if(tag==0)cout<<tmp->data,tag=1;
		//之后的输出空格加data值 
		else cout<<" "<<tmp->data;
		//出链队，以此改变头结点的数值 
		st.pop();
	}
	return 0;
}
	


