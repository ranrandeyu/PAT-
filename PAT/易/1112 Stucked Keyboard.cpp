/*映射 找连续相同的字符判别为错误，输出正确的字符串*/ 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int num; 
	string s;
	cin>>num>>s;
	s.push_back('a');//方便后序的遍历
	int stucked[1000]={0};//存储坏掉的 
	int worked[1000]={0};//存储正常的 
	vector<char> stuck;//用于输出坏的
	
	int count=1;
	int i=1;
	while(i<s.size())
	{
		//找到前后相同的数字
		while(s[i]==s[i-1]&&i<s.size())
		{
			count++;
			i++;
		 } 
		
		//找到符合几个连在一起的数字 
		if(count%num==0&&worked[s[i-1]]==0)
		{
			stuck.push_back(s[i-1]);
		}
		else
		worked[s[i-1]]=1;
		count=1;
		i++;
	 } 
	 
	 //输出坏掉的健
	 for(int i=0;i<stuck.size();i++)
	 {
	 	if(worked[stuck[i]]==0)
	 	{
	 		cout<<stuck[i];
	 		stucked[stuck[i]]=1;
	 		worked[stuck[i]]=1;
		 }
	 }
	 cout<<endl;
	 //输出整理过的字符串 
	 int j=0;
	 while(j<s.size()-1)
	 {
	 	if(stucked[s[j]]==0)//好的 
	 	{
	 		cout<<s[j];
	 		j++;
		 }
		 else
		 {
		 	cout<<s[j];//坏的 
		 	j+=num;//j前移k位 
		 }
	 }
	 cout<<endl;
 } 
