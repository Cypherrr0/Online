//层次顺序遍历二叉树 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 128

// 定义二叉树 
typedef struct Node
{                             
    char         data;       // 数据元素
    struct Node* lchild;     // 指向左孩子节点
    struct Node* rchild;     // 指向右孩子节点
}BiNode;                     // struct Node 的别名
typedef BiNode* BiTree;

// 定义顺序队
typedef struct Queue
{         
    int front;               // 队头指针（实际上不是指针，是一个标签） 
    int rear;                // 队尾指针（实际上不是指针，是一个标签）
    BiNode* data[MaxSize];   // 存放队中元素（保存指针的数组） 
}SqQueue;                    // struct Queue 的别名

//创建二叉树 
BiTree CreateTree()
{ 
	BiTree T;
    char x=getchar();
    if(x=='#')  return T=NULL;
	if(x=='\n') return T;
	else
	{ 
		T=(BiTree)malloc(sizeof(BiNode));
		T->data=x;
		T->lchild=CreateTree();
		T->rchild=CreateTree();
		return T;
	}	
}

//层序遍历  
void LevelOrder(BiTree T)
{
	BiNode *q= NULL;                      //创建临时指针q，移动它，来访问输出节点
    SqQueue* Q;                           //定义队列 Q
    Q=(SqQueue*)malloc(sizeof(SqQueue));  //给Q获取（创建）地址
    Q->front=Q->rear=-1; //初始化
    if(T==NULL)
		return; 
	Q->data[++Q->rear]=T;    //入队 队列内存放指针                            
    while(Q->front!=Q->rear)//队列非空
	{
		Q->front++;
		q=Q->data[Q->front];//出队 出根节点
		
		printf("%c",q->data);                                    
        if (q->lchild != NULL)
			Q->data[++Q->rear]=q->lchild; //入队 左右儿子作为根节点入队
        if (q->rchild != NULL)
			Q->data[++Q->rear]=q->rchild; //入队 左右儿子作为根节点入队
	}  
} 

int main()
{
	BiTree T;
	T=CreateTree();
    LevelOrder(T);
    return 0;   
}

//https://blog.csdn.net/henry_moon/article/details/121025145?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-121025145-blog-51237061.pc_relevant_multi_platform_whitelistv3&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-121025145-blog-51237061.pc_relevant_multi_platform_whitelistv3&utm_relevant_index=1