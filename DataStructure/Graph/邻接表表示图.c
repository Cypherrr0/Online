#include <stdio.h>

typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

typedef struct Vnode
{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];
typedef PtrToGNode LGraph;

typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct ENode *PtrToENode;
struct ENode
{
    Vertex v1,v2;
    int weight;
};

typedef PtrToENode Edge;
typedef int Vertex;
typedef int WeightType;

LGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    LGraph Graph;
    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;
    for(V=0;V<Graph->Nv;V++)
    {
        Graph->G[V].FirstEdge=NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E)
{
    PtrToAdjVNode NewNode;
    /*** 插入边<V1,V2> ***/
    /* 为V2建立新的邻接点 */
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->v2;
    NewNode->Weight=E->weight;
    
    /* 为V2插入V1的表头 */
    NewNode->Next=Graph->G[E->v1].FirstEdge;
    Graph->G[E->v1].FirstEdge=NewNode;

    /*** 对于无向图，插入<V2,V1> ***/
    /* 为V1建立新的邻接点 */
    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->v1;
    NewNode->Weight=E->weight;
    
    /* 为V1插入V2的表头 */
    NewNode->Next=Graph->G[E->v2].FirstEdge;
    Graph->G[E->v2].FirstEdge=NewNode;
}

int main()
{

}