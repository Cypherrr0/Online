#include<cstdio>
#include<stack>
#include<iostream>
#include<string>
using namespace std;

#define MAX 30
int preOrder[MAX];
int inOrder[MAX];
int postOrder[MAX];


//根据前序和中序划分，来确定后序遍历。前序的第一个数字为根结点，
//找到根结点root在中序数组位置，中序数组中root左边为根结点左子树，右边为右子树
void Solve(int preL,int inL,int postL,int n)
{   
    if(n==0)return;
    if(n==1)
    {
        postOrder[postL]=preOrder[preL]; 
    }
    int root=preOrder[preL];
    postOrder[postL+n-1]=root;
    int i,R,L;
    for(i=0;i<n;i++)
    {
    if(root==inOrder[inL+i])break;
    }
    L=i,R=n-i-1;                  //L为左子树结点数目，R为右子树结点数目
    Solve(preL+1,inL,postL,L);    //确定后序数组中根结点root左边的排列顺序
    Solve(preL+L+1,inL+L+1,postL+L,R);
}

int main()
{
    int n;
    for(int i=0;i<MAX;i++)
    {
    preOrder[i]=0;
    inOrder[i]=0;
    postOrder[i]=0;
    }
    stack<int> s;
    cin>>n;
    string str;
    int data;
    int index=0,pos=0;
    for(int i=0;i<2*n;i++)
    {
    cin>>str;
    if(str=="Push")//push代表前序遍历
    {      
        cin>>data;
        s.push(data);
        preOrder[index++]=data;
    }
    else if(str=="Pop")
    { //pop为中序遍历
        inOrder[pos++]=s.top();
        s.pop();
    }
    }
    Solve(0,0,0,n);
    for(int i=0;i<n;i++)
    {
    if(i>0)printf(" ");
    printf("%d",postOrder[i]);
    }
    return 0;
}
//https://www.cnblogs.com/patatoforsyj/p/9758403.html
//https://blog.csdn.net/liyuanyue2017/article/details/83545926
//https://blog.csdn.net/mlm5678/article/details/83686123