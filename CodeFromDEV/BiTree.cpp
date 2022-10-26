// 23:30
// 21min
#include <stdio.h>
#include <stdlib.h>

typedef struct BiNode *BiTree;
struct BiNode
{
	int data;
	BiTree left;
	BiTree right;
};

BiTree CreateTreeNode(int n)
{
	BiTree T=(BiTree)malloc(sizeof(struct BiNode));
	T->data=n;
	T->left=T->right=NULL;
	return T;
}

BiTree CreateTree(BiTree T,int n)
{
	if(T==NULL)
		T=CreateTreeNode(n);
	else
	{
		if(n<T->data)
			T->left=CreateTree(T->left,n);
		else
			T->right=CreateTree(T->right,n);
	}
	return T;
}
int cnt=0;
void PrintLevel(BiTree T,int x)
{
	if(T==NULL)
		return;
	if(x==1)
	{
		printf("%d,",T->data);
		cnt++;
	}
		
	else
	{
		PrintLevel(T->left,x-1);
		PrintLevel(T->right,x-1);
	}
}

int main()
{
	int num;
	scanf("%d",&num);
	getchar();
	BiTree root=NULL;
	for(int i=0;i<10;i++)
	{
		int x;
		scanf("%d,",x);
		root=CreateTree(root,x);
	}
	getchar();
	int level;
	
	scanf("%d",&level);
	PrintLevel(root,level);
	if(cnt==0)
		printf("-1");
	printf("\n");
}
