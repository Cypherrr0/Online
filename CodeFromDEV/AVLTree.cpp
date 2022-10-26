//23:08
// 21min
#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *AVLTree;
struct AVLNode
{
	int data;
	AVLTree left;
	AVLTree right;
	int height;
};

int max(int a,int b)
{
	return a>b ? a:b;
}

int getheight(AVLTree T)
{
	if(T=NULL)
		return -1;
	
	int leftchildheight = getheight(T->left);
	int rightchildheight = getheight(T->right);
	return max(leftchildheight,rightchildheight)+1;
}

AVLTree SingleLeftRotation(AVLTree A)
{
	AVLTree B=A->left;
	A->left=B->right;
	B->right=A;
	B->height=max(getheight(B->left),getheight(B->right))+1;
	return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B=A->right;
	A->right=B->left;
	B->left=A;
	B->height=max(getheight(B->left),getheight(B->right))+1;
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

AVLTree Insert(AVLTree T,int n)
{
	if(T==NULL)
	{
		T=(AVLTree)malloc(sizeof(struct AVLNode));
		T->data=n;
		T->height=0;
		T->left=T->right=NULL;
	}
	else if(n<T->data)
	{
		T->left=Insert(T->left,n);
		if(getheight(T->left) - getheight(T->right) == 2)
		{
			if(n<T->left->data)
				T=SingleLeftRotation(T);
			else
				T=DoubleLeftRightRotation(T);
		}
	}
	else if(n>T->data)
	{
		T->right=Insert(T->right,n);
		if(getheight(T->left)- getheight(T->right) == -2)
		{
			if(n>T->right->data)
				T=SingleRightRotation(T);
			else
				T=DoubleRightLeftRotation(T);
		}
	}
	T->height=max(getheight(T->left),getheight(T->right))+1;
	return T;
}

void preorder(AVLTree T)
{
	if(T!=NULL)
	{
		printf("%d,",T->data);
		preorder(T->left);
		preorder(T->right);
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
    preorder(root);
    printf("\n");
}
