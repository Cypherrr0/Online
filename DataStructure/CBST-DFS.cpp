#include <bits/stdc++.h>
using namespace std;
const int N=1e4;
typedef long long ll;
ll a[N],b[N];
int n,j=0;
void dfs(int i)//深度优先搜索
{
    if(i>n)
    {
        return ;
    }
    dfs(i*2);//向左
    b[i]=a[++j];
    dfs(i*2+1);//向右
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];//原始数列
    }
        
    sort(a+1,a+1+n);//排序
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(i!=1)cout<<" ";
        cout<<b[i];
    }
    return 0;
}