/*��ѧ���� stringstream�ַ���ת�� substr��ȡ������������ 
ת�����������stringstream������ڲ������У�������������������Զ��ʹ�ã���clear���� */ 
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string ans="";
	if(s[0]=='-')
		ans+=s[0];//����ǰ�ӷ��� 
	int  indexe=s.find("E");
	string num=s.substr(1,indexe-1);
	char figure=s[indexe+1];
	string exp=s.substr(indexe+2,s.length()-indexe-2);
	stringstream ss;
	ss<<exp;//��ss�в���exp 
	int e;
	ss>>e;//��ȡss�е�ֵ��e�� 
	if (e==0)//ָ��Ϊ0��ֱ����� 
	{
		cout<<ans<<num<<endl;
		return 0;
	}
	if(figure=='+')//��ָ�� 
	{
		//����С��������
		if(e<num.length()-2)
		{
			ans=ans+num[0]+num.substr(2,e)+"."+num.substr(e+2,num.length()-2-e);	 
		}
	
		//��ȫ������ 
		else{
			ans=ans+num[0]+num.substr(2,num.length()-2);
			for(int i=0;i<e-num.length()+2;i++)
			ans+="0";						
		}
	}
	
	
	if(figure=='-')//��ָ��
	{
		ans=ans+"0.";
		while(e--!=1)
		ans+="0";
		ans=ans+num[0]+num.substr(2,num.length()-2);		
	} 
	cout<<ans<<endl;
	return 0;
}


