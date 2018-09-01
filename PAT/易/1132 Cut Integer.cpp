/*一个数分成两半 看是否能被整除 保证后面的数字为非0*/ 
#include<iostream>
#include<string.h> 
using namespace std;
int main()
{
	int n;
	char a[30][20];
	string result[30];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		int len;
		int suma=0,sumb=0,sum=0;
		len=strlen(a[i]);
		for(int j=0;j<len;j++)
		sum=a[i][j]-'0'+sum*10;
		for(int j=0;j<len/2;j++)
		suma=a[i][j]-'0'+suma*10;
		for(int j=len/2;j<len;j++)
		sumb=a[i][j]-'0'+sumb*10;
		
		if(sumb==0)
		//cout<<"No"<<endl;
		result[i]="No";
		else
		{
			if(sum%(suma*sumb)==0&&(suma*sumb)!=0)
			//cout<<"Yes"<<endl;
			result[i]="Yes";
			else
			//cout<<"No"<<endl;
			result[i]="No";
		 } 
	}
	for(int i=0;i<n;i++)
	{
		cout<<result[i]<<endl;
	}
} 
