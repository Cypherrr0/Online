#include <stdio.h>
//构建二叉搜索树
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

//二叉搜索树创建结点
TreeNode *CreateTreeNode(int data)
{
    TreeNode *p=(TreeNode *)malloc(sizeof(TreeNode));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}
//二叉搜索树创建二叉树
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
//二叉搜索树的插入函数
TreeNode *Insert(TreeNode *root,int data)
{
    if(root==NULL)
    {
        root=CreateTreeNode(data);
    }
    else
    {
        if(data<root->data)
        {
            root->left=Insert(root->left,data);
        }
        else if(data>root->data)
        {
            root->right=Insert(root->right,data);
        }
    }
    return root;
}
//二叉搜索树的删除函数
TreeNode *Delete(TreeNode *root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(data<root->data)
        {
            root->left=Delete(root->left,data);
        }
        else if(data>root->data)
        {
            root->right=Delete(root->right,data);
        }
        else
        {
            if(root->left==NULL)
            {
                TreeNode *p=root->right;
                free(root);
                return p;
            }
            else if(root->right==NULL)
            {
                TreeNode *p=root->left;
                free(root);
                return p;
            }
            else
            {
                TreeNode *p=root->right;
                while(p->left!=NULL)
                {
                    p=p->left;
                }
                root->data=p->data;
                root->right=Delete(root->right,p->data);
            }
        }
    }
    return root;
}
//平衡二叉搜索树的调整函数
TreeNode *Adjust(TreeNode *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        root->left=Adjust(root->left);
        root->right=Adjust(root->right);
        int lh=Height(root->left);
        int rh=Height(root->right);
        if(lh-rh>1)
        {
            if(Height(root->left->left)>Height(root->left->right))
            {
                root=RotateRight(root);
            }
            else
            {
                root->left=RotateLeft(root->left);
                root=RotateRight(root);
            }
        }
        else if(rh-lh>1)
        {
            if(Height(root->right->right)>Height(root->right->left))
            {
                root=RotateLeft(root);
            }
            else
            {
                root->right=RotateRight(root->right);
                root=RotateLeft(root);
            }
        }
        return root;
    }
}
int main()
{

}