#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000,INF = 0x3f3f3f3f;//定义一个INF表示无穷大。
int g[MAXN][MAXN],dist[MAXN],n,m,res;
//我们用g[][]数组存储这个图，dist[]储存到集合S的距离，res保存结果。
bool book[MAXN];//用book数组记录某个点是否加入到集合S中。

void prim()
{
    dist[1] = 0;//把点1加入集合S，点1在集合S中，将它到集合的距离初始化为0
    book[1] = true;//表示点1已经加入到了S集合中
    for(int i = 2 ; i <= n ;i++)
        dist[i] = min(dist[i],g[1][i]);//用点1去更新dist[]
    for(int i = 2 ; i <= n ; i++)
    {
        int temp = INF;//初始化距离
        int t = -1;//接下来去寻找离集合S最近的点加入到集合中，用t记录这个点的下标。
        for(int j = 2 ; j <= n; j++)
        {
            if(!book[j]&&dist[j]<temp)//如果这个点没有加入集合S，而且这个点到集合的距离小于temp就将下标赋给t
            {
                temp = dist[j];//更新集合V到集合S的最小值
                t = j;//把点赋给t
            }
        }
        if(t==-1){res = INF ; return ;}
        //如果t==-1，意味着在集合V找不到边连向集合S，生成树构建失败，将res赋值正无穷表示构建失败，结束函数
        book[t] = true;//如果找到了这个点，就把它加入集合S
        res+=dist[t];//加上这个点到集合S的距离
        for(int j = 2 ; j <= n ; j++)dist[j] = min(dist[j],g[t][j]);//用新加入的点更新dist[]
    }
}

int main()
{
    cin>>n>>m;//读入这个图的点数n和边数m
    for(int i = 1 ; i<= n ;i++)
    {
        for(int j = 1; j <= n ;j++)
        {
            g[i][j] = INF;//初始化任意两个点之间的距离为正无穷（表示这两个点之间没有边）
        }
        dist[i] = INF;//初始化所有点到集合S的距离都是正无穷
    }
    for(int i = 1; i <= m ; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;//读入a，b两个点之间的边
        g[a][b] = g[b][a] = w;//由于是无向边，我们对g[a][b]和g[b][a]都要赋值
    }
    prim();//调用prim函数
    if(res==INF)//如果res的值是正无穷，表示不能该图不能转化成一棵树，输出orz
        cout<<"orz";
    else
        cout<<res;//否则就输出结果res
    return 0;
}

//https://blog.csdn.net/qq_62213124/article/details/121597780