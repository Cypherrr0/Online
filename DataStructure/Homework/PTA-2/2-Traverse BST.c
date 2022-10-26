#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct TreeNode *BiTree;
struct TreeNode
{
    int data;
    BiTree Lchild;
    BiTree Rchild;
};

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
        root=CreateTreeNode(n);
    else
    {
        if(n<root->data)
            root->Lchild = CreateTree(root->Lchild,n);
        else
            root->Rchild = CreateTree(root->Rchild,n);
    }
    return root;
}

void PreOrder(BiTree root)
{
    if(root!=NULL)
    {
        printf("%d,",root->data);
        PreOrder(root->Lchild);
        PreOrder(root->Rchild);
    }
}

int main(int argc, char *argv[])
{
    // printf("%d ",seq);
    int seq,cnt=1;
    char temp;
    BiTree root=NULL;
    int x;
    scanf("%d,",&x);
    // temp=getchar();
    while(scanf("%d",&x)!=EOF)
    {
        
        root=CreateTree(root,x);
        // x=-1;
        // scanf("%d,",&x);
        temp=getchar();
    }
    PreOrder(root);
    printf("\n");
}