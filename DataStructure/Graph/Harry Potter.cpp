#include <bits/stdc++.h>

#define INFINITY 99999

using namespace std;

int N,M;
int cnt;
typedef struct Graph* PtrGraph;
typedef struct Graph
{
    int Ne;
    int Nv;
    int Data[101][101];
}graph;

void CreateGraph(PtrGraph G)
{
    int i,j,w;
    cin >> N >> M;
    G->Nv=N;
    G->Ne=M;
    for(int i=1;i<=G->Nv;i++)
    {
        for(int j=1;j<=G->Nv;j++)
        {
            G->Data[i][j]=INFINITY;
            if(i==j)
            {
                G->Data[i][j]=0;
            }
        }
    }
    for(int k=0;k<G->Ne;k++)
    {
        cin >> i >> j >> w;
        G->Data[i][j]=w;
        G->Data[j][i]=w;
    }
}

int Dijkstra(PtrGraph G,int a,int vis[])
{
    int dist[101]={0};
    int max=0;
    vis[a]=1;
    cnt++;
    for(int i=1;i<=G->Nv;i++)
    {
        dist[i]=G->Data[a][i];
    }
    while(1)
    {
        int m=-1;
        int min=INFINITY;
        for(int i=1;i<=G->Nv;i++)
        {
            if(dist[i]<min&&vis[i]!=1)
            {
                min=dist[i];
                m=i;
            }
        }
        if(m==-1)
        {
            break;
        }
        vis[m]=1;
        cnt++;
        for(int i=1;i<=G->Nv;i++)
        {
            if(vis[i]!=1&&G->Data[m][i]+min<dist[i])
            {
                dist[i]=G->Data[m][i]+min;
            }
        }
    }
    for(int i=1;i<=G->Nv;i++)
    {
        if(dist[i]>max)
        {
            max=dist[i];
        }
    }
    return max;
}

int main(int argc, char** argv)
{
    PtrGraph G;
    int flag=0;
    vector<int> v;
    int min=100,array[101],k=1;
    G=(PtrGraph)malloc(sizeof(struct Graph));
    CreateGraph(G);
    int a=1;
    v.push_back(a);

    for(int i=1;i<=G->Nv&&flag==0;i++)
    {
        cnt=0;
        int visited[101]={0};
        int temp=Dijkstra(G,i,visited);
        array[k++]=temp;
        v.push_back(temp);
        if(cnt!=N)
        {
            flag=1;
        }

    }
    if(flag==1)
    {
        cout << "0" << endl;
    }
    else
    {
        sort(v.begin()+1,v.end());
        for(int i=1;i<=k;i++)
        {
            if(array[i]==v[1])
            {
                if(i<min)
                {
                    min=i;
                }
            }
        }
        cout <<min<<' '<<v[1] << endl;
    }
}

//https://blog.csdn.net/qq_48508278/article/details/117667039