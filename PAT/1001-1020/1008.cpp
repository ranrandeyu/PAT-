#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0;
	int first=0;
	int next=0;
	for(int i=0;i<n;i++)
	{
		first=next;
		cin>>next;
		if(next-first>0)
		sum+=6*(next-first);
		else if(next-first<0)
		sum+=4*(first-next);
		sum+=5;
	}
	cout<<sum<<endl;
	return 0;	
}
