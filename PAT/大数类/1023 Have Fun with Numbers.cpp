/*��֪һ������ÿ�����2���������ɻ��Ǹ�ԭ��һ��
�����yes������ʲô��������ӡ�˳�2�Ժ����*/ 

#include <stdio.h>
#include <string.h>
using namespace std; 
int main ()
{
    char start[21];
    char end[21];
    scanf("%s",&start);//������
    int t,i,j,m=0,s;
    t=strlen(start);//�������ĳ��ȼ�λ��
    int flag1=1;
    if((start[0]-'0')*2>=10)//��һλ���ִ���5Ҫ��λ���ַ�����
    {
        end[0]='1';//��2��λֻ����Ϊ1
        flag1=0;//λ���ı������һ����ͬ
    }
    for(i=t-1; i>=0; i--)//��ĩβ��ʼ���˷�
    {
 
        if((start[i]-'0')*2>=10)//�н�λ
        {
            s=(start[i]-48)*2%10+m;
            end[i+1]='0'+s;//ȫ�������ƶ�һλ����ֹ���ݳ���2�󣬳��ȼ�1 
            m=1;//��λ�洢
        }
        else//�޽�λ
        {
            s=(start[i]-48)*2+m;
            end[i+1]='0'+s;
            m=0;
        }
    }
    int flag=1;
    for(i=1; i<=t; i++)//��end�����б�����������������ȣ�����start�����н�������Ϊa
        for(j=0; j<t; j++)
        {
            if(end[i]==start[j])
            {
                start[j]='a';
                break;
            }
        }
    for(i=0; i<t; i++)//��start�����в�ȫΪa����֤���в�ͬ��������
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
        for(i=0; i<=t; i++)//��λ������ӵ�һλ��ʼ
        {
            printf("%c",end[i]);
        }
    }
    else
    {
        for(i=1; i<=t; i++)//�޽�λ�ӵڶ�λ��ʼ
        {
            printf("%c",end[i]);
        }
    }
    return 0;
 
}

