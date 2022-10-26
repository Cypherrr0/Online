#include <stdio.h>
//构建二叉树
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode *CreateTreeNode(int data)
{
    TreeNode *p=(TreeNode *)malloc(sizeof(TreeNode));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}
//构建二叉树的函数
TreeNode *CreateTree(TreeNode *root,int data)
{
    if(root==NULL)
    {
        root=CreateTreeNode(data);
    }
    else
    {
        if(data<root->data)
        {
            root->left=CreateTree(root->left,data);
        }
        else
        {
            root->right=CreateTree(root->right,data);
        }
    }
    return root;
}


//前序遍历二叉树
void PreOrder(TreeNode *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
//层序遍历二叉树
void LevelOrder(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    TreeNode *p=root;
    TreeNode *q=NULL;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        q=p->left;
        p=p->right;
        if(q!=NULL)
        {
            p=q;
        }
    }
}
//求二叉树的高度
int TreeHeight(TreeNode *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=TreeHeight(root->left);
    int right=TreeHeight(root->right);
    return left>right?left+1:right+1;
}
//判断树是否同构
int IsSameTree(TreeNode *root1,TreeNode *root2)
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
    if(root1->left==NULL&&root2->left==NULL)
    {
        return IsSameTree(root1->right,root2->right);
    }
    if((root1->left==NULL&&root2->left==NULL)&&(root1->left->left->data==root2->left->left->data))
    {
        return IsSameTree(root1->left,root2->left)&&IsSameTree(root1->right,root2->right);
    }
    else
    {
        return IsSameTree(root1->right,root2->right)&&IsSameTree(root1->left,root2->left);
    }
    //return && ：如果a true，返回b，否则返回a
}

int main()
{
    int x;
    cin >> x;
    TreeNode *p=CreateTreeNode;
}