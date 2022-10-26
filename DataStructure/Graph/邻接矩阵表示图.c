#include <stdio.h>

int MaxVertexNum=100;

//邻接矩阵表述图
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    int G[MaxVertexNum][MaxVertexNum];
    int Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;
typedef int Vertex;
typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex v1,v2;
    int weight;
};

typedef PtrToENode Edge;


MGraph CreateGraph(int vertexNum)
{
    MGraph Graph=(MGraph)malloc(sizeof(struct GNode));
    Vertex V,W;
    Graph->Nv=vertexNum;
    Graph->Ne=0;
    for(V=0;V<Graph->Nv;V++)
    {
        for(W=0;W<Graph->Nv;W++)
        {
            Graph->G[V][W]=0;
        }
    }
    return Graph;
}
void InsertEdge(MGraph Graph,Edge E)
{
    Graph->G[E->v1][E->v2]=E->weight;//插入边<V1,V2>
    Graph->G[E->v2][E->v1]=E->weight;//插入边<V2,V1> (因为是无向图)
}
MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0)
    {
        E=(Edge)malloc(sizeof(struct ENode));
        InsertEdge(Graph,E);
    }
    for(V=0;V<Graph->Nv;V++)
    {
        scanf("%c",&(Graph->Data[V]));
    }
    return Graph;
}
