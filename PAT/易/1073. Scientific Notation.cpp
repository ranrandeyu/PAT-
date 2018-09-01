/*科学计数 stringstream字符串转换 substr截取部分数字内容 
转换结果保存在stringstream对象的内部缓冲中，缓冲区不会溢出，可以多次使用，加clear（） */ 
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
		ans+=s[0];//负数前加符号 
	int  indexe=s.find("E");
	string num=s.substr(1,indexe-1);
	char figure=s[indexe+1];
	string exp=s.substr(indexe+2,s.length()-indexe-2);
	stringstream ss;
	ss<<exp;//向ss中插入exp 
	int e;
	ss>>e;//抽取ss中的值到e中 
	if (e==0)//指数为0，直接输出 
	{
		cout<<ans<<num<<endl;
		return 0;
	}
	if(figure=='+')//正指数 
	{
		//还有小数点的情况
		if(e<num.length()-2)
		{
			ans=ans+num[0]+num.substr(2,e)+"."+num.substr(e+2,num.length()-2-e);	 
		}
	
		//补全零的情况 
		else{
			ans=ans+num[0]+num.substr(2,num.length()-2);
			for(int i=0;i<e-num.length()+2;i++)
			ans+="0";						
		}
	}
	
	
	if(figure=='-')//负指数
	{
		ans=ans+"0.";
		while(e--!=1)
		ans+="0";
		ans=ans+num[0]+num.substr(2,num.length()-2);		
	} 
	cout<<ans<<endl;
	return 0;
}


