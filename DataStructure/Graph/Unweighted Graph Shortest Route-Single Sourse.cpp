#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;


#define MAXN 1010

int Nv,Ne;//顶点 边
struct LNode
{
    int data;
    LNode* next;
};

LNode* G[MAXN];

void CreateL()
{
    cin>>Nv>>Ne;

    for(int i=0;i<Nv;i++)
    {
        G[i]=new LNode;
        G[i]->data=i;
        G[i]->next=NULL;
    }

    int v1,v2;
    for(int i=0;i<Ne;i++)
    {
        cin>>v1>>v2;
        LNode* tmp=new LNode;
        tmp->data=v2;
        tmp->next=G[v1]->next;
        G[v1]->next=tmp;//邻接表 表示图 定义！！

    /*LNode* tmp1=new LNode;
        tmp1->data=v1;
        tmp1->next=G[v2]->next;
        G[v2]->next=tmp1;*/
    }
}

void Unweighted(int S,int* dist,int* path)
{
    queue<int> q;
    q.push(S);
    dist[S]=0;//dist是初始点到【】内距离

    int tmp;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();

        LNode* w=G[tmp]->next;//每一个邻接点
        while(w)
        {
            if(dist[w->data]==-1)
            {
                dist[w->data]=dist[tmp]+1;
                path[w->data]=tmp;
                q.push(w->data);
            }
            w=w->next;
        }
    }
}

void PrintL(int start,int* path)
{
    cout<<start;

    int tmp=path[start];
    while(tmp!=-1){
        cout<<" "<<tmp;
        tmp=path[tmp];
    }
}

int main()
{
    CreateL();

    int dist[MAXN],path[MAXN];
    fill(dist,dist+Nv,-1);
    fill(path,path+Nv,-1);

    //从2出发到所有顶点的最短路径dist
    Unweighted(2,dist,path);
    
    //2到5的最短路径
    PrintL(5,path);

    return 0;
}
//https://blog.csdn.net/fftx_00/article/details/119492498