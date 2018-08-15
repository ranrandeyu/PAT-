/*已知一个数，每项乘以2后的数字组成还是跟原来一样
则输出yes，不管什么情况均需打印此成2以后的数*/ 

#include <stdio.h>
#include <string.h>
using namespace std; 
int main ()
{
    char start[21];
    char end[21];
    scanf("%s",&start);//输入数
    int t,i,j,m=0,s;
    t=strlen(start);//存入数的长度即位数
    int flag1=1;
    if((start[0]-'0')*2>=10)//第一位数字大于5要进位，字符运算
    {
        end[0]='1';//乘2进位只可能为1
        flag1=0;//位数改变则表明一定不同
    }
    for(i=t-1; i>=0; i--)//从末尾开始做乘法
    {
 
        if((start[i]-'0')*2>=10)//有进位
        {
            s=(start[i]-48)*2%10+m;
            end[i+1]='0'+s;//全部往后移动一位，防止数据乘以2后，长度加1 
            m=1;//进位存储
        }
        else//无进位
        {
            s=(start[i]-48)*2+m;
            end[i+1]='0'+s;
            m=0;
        }
    }
    int flag=1;
    for(i=1; i<=t; i++)//在end数组中遍历，若存在两数相等，则在start数组中将此数变为a
        for(j=0; j<t; j++)
        {
            if(end[i]==start[j])
            {
                start[j]='a';
                break;
            }
        }
    for(i=0; i<t; i++)//若start数组中不全为a，则证明有不同的数产生
    {
        if(start[i]!='a')
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        printf("Yes\n");
    else printf("No\n");
    if(flag1==0)
    {
        for(i=0; i<=t; i++)//进位后输出从第一位开始
        {
            printf("%c",end[i]);
        }
    }
    else
    {
        for(i=1; i<=t; i++)//无进位从第二位开始
        {
            printf("%c",end[i]);
        }
    }
    return 0;
 
}

