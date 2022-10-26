#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

struct stack
{
    char data[MAXSIZE];
    int top;
};
typedef struct stack *linkstack;
struct postfix
{
    char data[MAXSIZE];
    int top;
};
typedef struct postfix *linkpostfix;

struct calculate
{
    int data[MAXSIZE];
    int top;
};
typedef struct calculate *CalPost;

linkstack InitStack()
{
    linkstack LinkStack;
    LinkStack->top=-1;
    return LinkStack;
}

linkpostfix InitPostfix()
{
    linkpostfix LinkPostfix;
    LinkPostfix->top=-1;
    return LinkPostfix;
}

CalPost InitCal()
{
    CalPost CalPostfix;
    CalPostfix->top=-1;
    return CalPostfix;
}

int ISP(char c)
{
    if(c=='(')
        return 1;
    else if(c=='*'||c=='/')
        return 5;
    else if(c=='+'||c=='-')
        return 3;
    else if(c==')')
        return 6;
}

int ICP(char c)
{
    if(c=='(')
        return 6;
    else if(c=='*'||c=='/')
        return 4;
    else if(c=='+'||c=='-')
        return 2;
    else if(c==')')
        return 1;
}

void PopAndOut(linkstack LinkStack,linkpostfix LinkPostfix)
{
    LinkPostfix->top++;
    LinkPostfix->data[LinkPostfix->top]=LinkStack->data[LinkStack->top];
    LinkStack->data[LinkStack->top]='\0';
    LinkStack->top--;
}

void PopOnly(linkstack LinkStack)
{
    LinkStack->data[LinkStack->top]='\0';
    LinkStack->top--;
}

void PushStack(linkstack LinkStack,char c)
{
    LinkStack->top++;
    LinkStack->data[LinkStack->top]=c;
}

void Decide(char c,linkstack LinkStack,linkpostfix LinkPostfix)
{
    if(LinkStack->top==-1)
        PushStack(LinkStack,c);
    while(1)
    {
        char x=LinkStack->data[LinkStack->top];
        if(ISP(x)>ICP(c))
        {
            PopAndOut(LinkStack,LinkPostfix);
        }
        else if(ISP(x)==ICP(c))
        {
            PopOnly(LinkStack);
            break;
        }
        else if(ISP(x)<ICP(c))
        {
            PushStack(LinkStack,c);
            break;
        }
    }
    
}

float CalPop(CalPost CalPostfix)
{
    float x=CalPostfix->data[CalPostfix->top];
    CalPostfix->top--;
    return x;
}

void Calculate(linkpostfix LinkPost,CalPost CalPostfix)
{
    char c=LinkPost->data[LinkPost->top];
    if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
    {
        CalPostfix->top++;
        int x=c-'0';
        CalPostfix->data[CalPostfix->top]=x;
    }
    else
    {
        float a=CalPop(CalPostfix);
        float b=CalPop(CalPostfix);
        float sum;
        if(c=='+')
            sum=a+b;
        else if(c=='-')
            sum=b-a;
        else if(c=='*')
            sum=a*b;
        else if(c=='/')
            sum=b/a;
        CalPostfix->top++;
        CalPostfix->data[CalPostfix->top]=sum;
    }
    printf("%.2f\n",CalPostfix->data[0]);
}

int main()
{
    linkstack LinkStack=InitStack();
    linkpostfix LinkPostfix=InitPostfix();
    char temp[50];
    fgets(temp,50,stdin);
    for(int i=0;temp[i]!='\0';i++)
    {
        if(temp[i]=='0'||temp[i]=='1'||temp[i]=='2'||temp[i]=='3'||temp[i]=='4'||temp[i]=='5'||temp[i]=='6'||temp[i]=='7'||temp[i]=='8'||temp[i]=='9')
        {
            LinkPostfix->top++;
            LinkPostfix->data[LinkPostfix->top]=temp[i];
        }
        else if(temp[i]=='+'||temp[i]=='-'||temp[i]=='*'||temp[i]=='/'||temp[i]=='('||temp[i]==')')
        {
            Decide(temp[i],LinkStack,LinkPostfix);
        }
    }
    if(LinkPostfix->top!=-1)
    {
        for(int i=LinkStack->top;i>=0;i--)
            PopAndOut(LinkStack,LinkPostfix);
    }
    CalPost CalPostfix=InitCal();
    Calculate(LinkPostfix,CalPostfix);
    for(int i=LinkPostfix->top;i>=0;i--)
        printf("%c ",LinkPostfix->data[LinkPostfix->top]);
}
