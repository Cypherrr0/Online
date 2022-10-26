#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct TreeNode *BiTree;
typedef struct TreeNode
{
    int data;
    BiTree Lchild;
    BiTree Rchild;
}BiNode;


BiTree CreateTreeNode(int n)
{
    BiTree root=(BiTree)malloc(sizeof(struct TreeNode));
        root->data = n;
        root->Lchild =NULL;
        root->Rchild =NULL;
    return root;
}

BiTree CreateTree(BiTree root, int n)
{
    if(root == NULL)
    {
        root=CreateTreeNode(n);
    }
        // root=CreateTreeNode(n);
    else
    {
        if(n<root->data)
            root->Lchild = CreateTree(root->Lchild,n);
        else
            root->Rchild = CreateTree(root->Rchild,n);
    }
    return root;
}
int cnt=0;
void PrintLevel(BiTree root,int n)
{
    if(root == NULL)
    {
        return;
    }
    if(n==1)
    {
        printf("%d,",root->data);
        cnt++;
    }
    else
    {
        PrintLevel(root->Lchild,n-1);
        PrintLevel(root->Rchild,n-1);
    }

}

int main(int argc, char *argv[])
{
    int num,level;
    scanf("%d",&num);
    getchar();
    int seq;
    scanf("%d",&seq);
    getchar();
    BiTree root=NULL;
    root=CreateTree(root,seq);
    // printf("%d ",seq);
    for(int i=2;i<=num;i++)
    {
        scanf("%d",&seq);
        root=CreateTree(root,seq);
        // printf("%d ",seq);
        getchar();
    }
    getchar();
    scanf("%d",&level);
    
    PrintLevel(root,level);
    if(cnt==0)
        printf("-1");
    printf("\n");
}