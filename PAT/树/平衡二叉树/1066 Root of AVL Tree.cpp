#include<iostream>
using namespace std;
struct node{
	int x;
	struct node *left,*right;
};
//RR 右单旋 （逆时针） 
node *RR(node *root)
{
	node *tree=root->right;	
	root->right=tree->left;
	tree->left=root;
	return tree;
} 

node *LL(node *root)
{
	node *tree=root->left;	
	root->left=tree->right;
	tree->right=root;
	return tree;
} 
//root必须有一个左子结点B，而且B必须有一个右子结点C 
node *LR(node *root)
{
	//将B、C做右单旋，C被返回 
	root->left=RR(root->left);
	//将A、C做左单旋，C被返回 
	return LL(root);
 } 
 
 node *RL(node *root)
{
	root->right=LL(root->right);
	return RR(root);
 } 
 
int gethigh(node *root)
{
	if(root==NULL)
	return 0;
	return max(gethigh(root->left),gethigh(root->right)) +1;
}

node *insert(node *root,int x)
{
	if(root==NULL)
	{
		root=new node();
		root->x=x;
		root->right=root->left=NULL;
	}
	else if(x<root->x)
	{
		root->left=insert(root->left,x);
		if(gethigh(root->left)-gethigh(root->right)==2) 
		if(x<root->left->x)
		root=LL(root);
		else
		root=LR(root);
	} 
	else
	{
		root->right=insert(root->right,x);
		if(gethigh(root->left)-gethigh(root->right)==-2) 
		if(x>root->right->x)
		root=RR(root);
		else
		root=RL(root);		
	}
	return root;
}

int main()
{
	int n,x;
	scanf("%d",&n);
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		root=insert(root,x);
	}
	printf("%d",root->x);
	return 0;
}
