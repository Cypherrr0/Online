#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode* Position;
typedef struct AVLNode* Node;
typedef Position AVLTree;
struct AVLNode
{
    int data;
    AVLTree left;
    AVLTree right;
    int height;
};

int Max(int a,int b)
{
    return a>b ? a:b;
}

int GetHeight(Node node)
{
    if(node==NULL)
        return -1;
    int leftchildheight= GetHeight(node->left);
    int rightchildheight= GetHeight(node->right);
    return (leftchildheight > rightchildheight ? leftchildheight : rightchildheight)+1;
}

AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B= A->left;
    A->left=B->right;
    B->right=A;
    B->height=Max(GetHeight(B->left),GetHeight(B->right))+1;
    return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B=A->right;
    A->right=B->left;
    B->left=A;
    B->height=Max(GetHeight(B->left),GetHeight(B->right))+1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->left=SingleRightRotation(A->left);
    return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->right=SingleLeftRotation(A->right);
    return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T,int x)
{
    if(!T)
    {
        T=(AVLTree)malloc(sizeof(struct AVLNode));
        T->data=x;
        T->height=0;
        T->left=T->right=NULL;
    }
    else if(x<T->data)
    {
        T->left=Insert(T->left,x);
        if(GetHeight(T->left)-GetHeight(T->right)==2)
        {
            if(x<T->left->data)
                T=SingleLeftRotation(T);
            else
                T=DoubleLeftRightRotation(T);
        }
    }
    else if(x>T->data)
    {
        T->right=Insert(T->right,x);
        if(GetHeight(T->left)-GetHeight(T->right)==-2)
        {
            if(x>T->right->data)
                T=SingleRightRotation(T);
            else
                T=DoubleRightLeftRotation(T);
        }
    }
    T->height=Max(GetHeight(T->left),GetHeight(T->right))+1;
    return T;
}

void PreOrder(AVLTree root)
{
    if(root!=NULL)
    {
        printf("%d,",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main()
{
    AVLTree root=NULL;
    int x;
    scanf("%d,",&x);
    while(x!=-1)
    {
        root=Insert(root,x);
        x=-1;
        scanf("%d,",&x);
    }
    PreOrder(root);
    printf("\n");
}