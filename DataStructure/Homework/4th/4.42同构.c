#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 150
typedef struct Tree *TreeNode; 
struct Tree
{
    int data;
    TreeNode Lchild;
    TreeNode Rchild;
};

typedef struct Queue
{         
    int front;               // 队头指针（实际上不是指针，是一个标签） 
    int rear;                // 队尾指针（实际上不是指针，是一个标签）
    TreeNode data[MaxSize];   // 存放队中元素（保存指针的数组） 
}SqQueue;     

TreeNode CreateTree1()
{ 
	TreeNode T;
    
    char x=getchar();
    if(x=='#')  return T=NULL;
	if(x=='\n') return T;
	else
	{ 
		T=(TreeNode)malloc(sizeof(struct Tree));
		T->data=x;
		T->Lchild=CreateTree1();
		T->Rchild=CreateTree1();
		return T;
	}	
}

int cnt=0;

TreeNode CreateTree2()
{ 
	TreeNode T;
    char x=getchar();
    if(cnt==0)
    {
        x=getchar();
        cnt=1;
    }
    
        
    if(x=='#')  return T=NULL;
	if(x=='\n') return T;
	else
	{ 
		T=(TreeNode)malloc(sizeof(struct Tree));
        if(T==NULL)
            printf("Error\n");
		T->data=x;
		T->Lchild=CreateTree2();
		T->Rchild=CreateTree2();
		return T;
	}	
}

void LeverOrder(TreeNode T)
{
	TreeNode q= NULL;                      //创建临时指针q，移动它，来访问输出节点
    SqQueue* Q;                           //定义队列 Q
    Q=(SqQueue*)malloc(sizeof(SqQueue));  //给Q获取（创建）地址
    Q->front=Q->rear=-1; //初始化
    if(T==NULL)
		return; 
	Q->data[++Q->rear]=T;    //入队 队列内存放指针                            
    while(Q->front!=Q->rear)//队列非空
	{
		q=Q->data[++Q->front]; //出队 出根节点
		// q=Q->data[Q->front++];
		printf("%c",q->data);                                    
        if (q->Lchild != NULL)
			Q->data[++Q->rear]=q->Lchild; //入队 左右儿子作为根节点入队
        if (q->Rchild != NULL)
			Q->data[++Q->rear]=q->Rchild; //入队 左右儿子作为根节点入队
	}  
}

int IsSameTree(TreeNode root1,TreeNode root2)
{
    if(root1==NULL&&root2==NULL)
    {
        return 1;
    }
    if(root1==NULL||root2==NULL)
    {
        return 0;
    }
    if(root1->data!=root2->data)
    {
        return 0;
    }
    if(root1->Lchild==NULL&&root2->Lchild==NULL)
    {
        return IsSameTree(root1->Rchild,root2->Rchild);
    }
    if((root1->Lchild==NULL&&root2->Lchild==NULL)&&(root1->Lchild->Lchild->data==root2->Lchild->Lchild->data))
    {
        return IsSameTree(root1->Lchild,root2->Lchild)&&IsSameTree(root1->Rchild,root2->Rchild);
    }
    else
    {
        return IsSameTree(root1->Rchild,root2->Rchild)&&IsSameTree(root1->Lchild,root2->Lchild);
    }
    //return && ：如果a true，返回b，否则返回a
}

bool IsSameTree2(TreeNode root1,TreeNode root2)
{
    if(root1!=root2)
        return false;
    if(root1!=NULL&&root2!=NULL)
    {
        if((IsSameTree2(root1->Lchild,root2->Lchild)&&IsSameTree2(root1->Rchild,root2->Rchild))||(IsSameTree2(root1->Lchild,root2->Rchild)&&IsSameTree2(root1->Rchild,root2->Lchild)))
            return true;
    }
    return true;
}

int main(int argc, char *argv[])
{
    printf("ENTER TREE:\n");
    TreeNode T1=CreateTree1();
    printf("11111\n");
    LeverOrder(T1);
    printf("ENTER TREE:\n");
    TreeNode T2=CreateTree2();
    printf("11111\n");
    LeverOrder(T2);
    if(IsSameTree2(T1,T2)==true)
        printf("YES\n");
    else
        printf("NO\n");
}

// AC#D##B##