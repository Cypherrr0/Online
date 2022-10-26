#include <bits/stdc++.h>
#include <Queue.h>
using namespace std;

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

void InitQueue(TreeNode *node);
void EnQueue(TreeNode *node);
void DeQueue(TreeNode *node);
bool IsEmpty(TreeNode *node);
void QueueDestroy(TreeNode *node);
void LevelOrder(TreeNode *root)
{
    if(root==NULL)
        return;
    Queue q;
    InitQueue(&q);
    EnQueue(&q, root);
    while(!IsEmpty(&q))
    {
        TreeNode *front=QueueFront(&q);
        DeQueue(&q);
        cout << front->left;
        if(front->left!=NULL)
            EnQueue(&q,front->left);
        if(front->right!=NULL)
            EnQueue(&q,front->right);
    }
    cout << endl;
    QueueDestroy(&q);
}

//https://blog.csdn.net/m0_57330725/article/details/121741152