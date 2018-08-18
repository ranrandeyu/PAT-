/*已知输入前序遍历，形成的树以及镜像后的树是否还为二叉搜索树
并递归实现后序输出*/ 
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
    //第一个点为根节点，往后比它小的点是它的左子树的点，
    // 再往后的全部是它右子树的点，应该全部大于等于它，
    //如果是镜像的，那么只要保证               小于     就好
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
    int choice=a[1]>a[2]?0:1;//先比较序列的前两个数，判断可能是镜像后的二叉搜索树还是原来的二叉搜索树
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
