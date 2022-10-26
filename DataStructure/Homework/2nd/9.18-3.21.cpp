#include <bits/stdc++.h>
#include <sys/time.h>
#define MAXSIZE 10
using namespace std;

struct Stack
{
    int Data[MAXSIZE];
    int top;
};
typedef struct Stack *LinkStack;
LinkStack InitStack()
{
    LinkStack linkstack=(LinkStack)malloc(sizeof(struct Stack));
    linkstack->top=-1;
    return linkstack;
}

void Push(LinkStack linkstack,int x)
{
    if(linkstack->top==MAXSIZE-1)
    {
        cout << "FULL!" << endl;
        
    }
    else
    {
        linkstack->top++;
        linkstack->Data[linkstack->top]=x;
        
    }
}

void pop(LinkStack linkstack,int *e)
{
    if(linkstack->top==-1)
    {
        cout << "EMPTY!" << endl;
    }
    else
    {
        *e=linkstack->Data[linkstack->top];
        linkstack->top--;
        cout << "SUCCESS!" << endl;
    }
}

void GetTop(LinkStack linkstack,int *e)
{
    if(linkstack->top==-1)
        cout << "FAILED!" << endl;
    else
    {
        *e=linkstack->Data[linkstack->top];
        cout << "TOP ELEMENT:" << *e;
    }
}

int main()
{
    int top;
    int *topElement=&top;
    LinkStack linkstack=NULL;
    linkstack=InitStack();
    cout << "PUSH STACK: ENTER 0 TO END" << endl;
    int temp;
    cin >> temp;
    while(temp!=0)
    {
        Push(linkstack,temp);
        cin >>temp;
    }
    struct timeval begin,end;
    gettimeofday(&begin,0);
    GetTop(linkstack,topElement);
    cout << "POP STACK" << endl;
    
    pop(linkstack,topElement);
    GetTop(linkstack,topElement);
    gettimeofday(&end,0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    cout << endl << "Time Used:" << elapsed << "s" << endl;
}