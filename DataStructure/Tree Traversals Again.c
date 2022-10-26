//题干：中序非递归遍历需要用到一个栈，
//给定针对这个栈的操作，就可以唯一确定一个树
//我们的任务就是后序遍历这棵树

#include <stdio.h>
#include <string.h>

int PreOrder[30];
int InOrder[30];
int PostOrder[30];

void Solve(int preL,int inL,int postL,int n)
{
    if(n==0)
    {
        return;
    }
    if(n==1)
    {
        PostOrder[postL]=PreOrder[preL];
        return;
    }
    int root=PreOrder[preL];
    PostOrder[postL+n-1]=root;
    int i,R,L;
    for(i=0;i<n;i++)
    {
        if(root==InOrder[inL+i])
            break;
    }
    L=i;
    R=n-i-1;
    Solve(preL+1,inL,postL,L);
    Solve(preL+L+1,inL+L+1,postL+L,R);
}
void InOrderInput(int *InOrder,int Index2,int *a,int top)
{
    InOrder[Index2]=a[top];
    Index2++;
}
int Push(int *a,int top,int Element)
{
    a[++top]=Element;
    return top;
}
int Pop(int *a,int top,int *InOrder,int Index2)
{
    if(top==-1)
    {
        printf("Stack is empty\n");
    }
    InOrderInput(InOrder,Index2,a,top);
    top--;
    return top;
}

int main()
{
    int n,Data,Index1=0,Index2=0;
    for(int i=0;i<30;i++)
    {
        PreOrder[i]=0;
        InOrder[i]=0;
        PostOrder[i]=0;
    }
    char temp[30];
    int a[100],top=-1;
    scanf("%d",&n);

    for(int i=0;i<2*n;i++)
    {
        scanf("%s",temp);

        if(strcmp(temp,"Push")==0)
        {
            scanf("%s",&Data);
            PreOrder[Index1++]=Data;
            top=Push(a,top,Data);
        }
        else if(strcmp(temp,"Pop")==0)
        {
            top=Pop(a,top,InOrder,Index2);
        }
    }
    Solve(0,0,0,n);
    for(int i=0;i<n;i++)
    {
        if(i>0)
        printf(" ");
        printf("%d",PostOrder[i]);
    }
}