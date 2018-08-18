/*push为先序，pop为中序，需得到后序*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
#define maxsize 30

int pre[maxsize];
int in[maxsize];
int post[maxsize];

void solve(int prel,int inl,int postl,int n)
{
	int before,after,i;
	if(n==0) return;
	if(n==1)
	{
		post[postl]=pre[prel];
		return;
	}
	int root=pre[prel];
	cout<<"sda"<<pre[prel]<<endl;
	post[postl+n-1]=root;
	for(i=0;i<n;i++)
	{
		if(in[inl+i]==root)break;
	}
	before=i;after=n-before-1;
	solve(prel+1,inl,postl,before);
	solve(prel+before+1,inl+before+1,postl+before,after);
 } 
 
 int main()
 {
 	for(int i=0;i<maxsize;i++)
 	{
 		pre[i]=0;
 		in[i]=0;
 		post[i]=0;
	}
	
	stack<int> input;
	int num;
	cin>>num;
	int data,i;
	int preindex=0,inindex=0,postindex=0;
	string str;
	for(i=0;i<2*num;i++)
	{
		cin>>str;
		if(str=="Push")
		{
			cin>>data;
			pre[preindex++]=data;
			input.push(data);
		}
		else if(str=="Pop")
		{
			in[inindex++]=input.top();
			input.pop();
		}
	}
	solve(0,0,0,num);
	for(int i=0;i<num;i++)
	{
		if(i==num-1)
		cout<<post[i]<<endl;
		else
		cout<<post[i]<<" ";
	}
	
 }

