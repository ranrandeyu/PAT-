/*��֪����ǰ��������γɵ����Լ����������Ƿ�Ϊ����������
���ݹ�ʵ�ֺ������*/ 
#include<iostream>
#include<queue>
using namespace std;
int a[1005],flag,n;
queue<int> q;
void dfs(int prel,int r,int choice)
{
    if (prel>r||!flag) return ;
    if (prel==r) {q.push(a[prel]);return;}
    int k=r+1;
    for (int i=prel+1;i<=r;i++)
    {
        if (a[i]<a[prel]&&!choice) continue;
        if (a[i]>=a[prel]&&choice) continue;
        k=i;
        break;
    }
    //��һ����Ϊ���ڵ㣬�������С�ĵ��������������ĵ㣬
    // �������ȫ�������������ĵ㣬Ӧ��ȫ�����ڵ�������
    //����Ǿ���ģ���ôֻҪ��֤               С��     �ͺ�
    for (int i=k;i<=r;i++)
    {
        if (a[i]<a[prel]&&!choice) flag=0;
        if (a[i]>=a[prel]&&choice) flag=0;
    }
    if (!flag) return ;
    dfs(prel+1,k-1,choice);
    dfs(k,r,choice);
    q.push(a[prel]);
}
int main()
{
    cin>>n;

    for (int i=1;i<=n;i++)
        cin>>a[i];
    flag=1;
    int choice=a[1]>a[2]?0:1;//�ȱȽ����е�ǰ���������жϿ����Ǿ����Ķ�������������ԭ���Ķ���������
    dfs(1,n,choice);
    if (!flag) {cout<<"NO";return 0;}
    cout<<"YES"<<endl;
    cout<<q.front();
    q.pop();
    while(!q.empty())
    {
        cout<<" "<<q.front();
        q.pop();
    }
    return 0;
}
