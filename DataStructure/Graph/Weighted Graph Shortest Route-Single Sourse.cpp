#include <bits/stdc++.h>


//邻接表法

#define MAXN 1010
#define INFINITY 0x3f3f3f3f
using namespace std;

int Nv,Ne;
struct LNode
{
    int data;
    int weight;
    LNode* next;
};

LNode* G[MAXN];

void CreateL(){
    cin>>Nv>>Ne;

    int v1,v2,w;
    for(int i=0;i<Ne;i++)
    {
        cin>>v1>>v2>>w;
        LNode* tmp=new LNode;
        tmp->data=v2;
        tmp->weight=w;
        tmp->next=G[v1];
        G[v1]=tmp;
    }
}


int FindMin(int* dist,int* collected)
{
//遍历找最小：适用于稠密图
    int MinDist=INFINITY;
    int MinV=-1;
    for(int i=0;i<Nv;i++)
    {
        if(collected[i]==-1 && MinDist>dist[i])
        {
            MinDist=dist[i];
            MinV=i;
        }
    }

    return MinV;
}

void Dijkstra(int S,int* dist,int* path,int* collected)
{
    dist[S]=0;

    int vetex;
    while(1)
    {
        vetex=FindMin(dist,collected);
        if(vetex==-1)
            break;
        collected[vetex]=1;

        LNode* w=G[vetex];
        while(w)
        {
            if(collected[w->data]==-1)
            {
                if(dist[vetex]+w->weight<dist[w->data])
                {
                    dist[w->data]=dist[vetex]+w->weight;
                    path[w->data]=vetex;
                }
            }
            w=w->next;
        }        
    }   
}

void PrintL(int vetex,int* path)
{
    cout<<vetex;
    
    int w=path[vetex];
    while(w!=-1)
    {
        cout<<" "<<w;
        w=path[w];
    }
}


int main(){
    CreateL();

    int dist[MAXN],path[MAXN];
    int collected[MAXN];
//dist初始化为极大值
    fill(dist,dist+Nv,INFINITY);
    fill(path,path+Nv,-1);
//collected初始化为-1
    fill(collected,collected+Nv,-1);

    Dijkstra(0,dist,path,collected);
    PrintL(5,path);

    return 0;
}

//https://blog.csdn.net/fftx_00/article/details/119521593