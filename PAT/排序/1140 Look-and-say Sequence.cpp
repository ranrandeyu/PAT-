#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> v;
	v.push_back(n);
	int count=1;
	for(int i=1;i<m;i++)
	{
		vector<int> temp;
		temp.push_back(v[0]);
		int count=1;
		

		for(int j=1;j<v.size();j++)
		{
			if(v[j]==v[j-1])
			count++;
			else
			{
				temp.push_back(count);
				temp.push_back(v[j]);
				count=1;
			}
		}
 		temp.push_back(count);
 		v.clear();
 		v=temp;
 		temp.clear();
 	}
 	for(int i=0;i<v.size();i++)
 	{
 		cout<<v[i];
	 }
	 return 0;}
	 
