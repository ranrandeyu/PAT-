/*ӳ�� ��������ͬ���ַ��б�Ϊ���������ȷ���ַ���*/ 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int num; 
	string s;
	cin>>num>>s;
	s.push_back('a');//�������ı���
	int stucked[1000]={0};//�洢������ 
	int worked[1000]={0};//�洢������ 
	vector<char> stuck;//�����������
	
	int count=1;
	int i=1;
	while(i<s.size())
	{
		//�ҵ�ǰ����ͬ������
		while(s[i]==s[i-1]&&i<s.size())
		{
			count++;
			i++;
		 } 
		
		//�ҵ����ϼ�������һ������� 
		if(count%num==0&&worked[s[i-1]]==0)
		{
			stuck.push_back(s[i-1]);
		}
		else
		worked[s[i-1]]=1;
		count=1;
		i++;
	 } 
	 
	 //��������Ľ�
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
	 //�����������ַ��� 
	 int j=0;
	 while(j<s.size()-1)
	 {
	 	if(stucked[s[j]]==0)//�õ� 
	 	{
	 		cout<<s[j];
	 		j++;
		 }
		 else
		 {
		 	cout<<s[j];//���� 
		 	j+=num;//jǰ��kλ 
		 }
	 }
	 cout<<endl;
 } 
