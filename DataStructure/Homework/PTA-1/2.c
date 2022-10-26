#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int cnt=0;
struct Stack
{
    char Data[MAXSIZE];
    int top;
};
typedef struct Stack *LinkStack;

struct Array
{
    char Post[MAXSIZE];
    int now;
};
typedef struct Array *PostArray;

struct Calculate
{
    float Cal[MAXSIZE];
    int top;
};
typedef struct Calculate *CalculatePost;


LinkStack InitStack()
{
    LinkStack linkstack=(LinkStack)malloc(sizeof(struct Stack));
    linkstack->top=-1;
    return linkstack;
}

PostArray InitArray()
{
    PostArray array=(PostArray)malloc(sizeof(struct Array));
    array->now=-1;
    return array;
}

CalculatePost InitCal()
{
    CalculatePost cal=(CalculatePost)malloc(sizeof(struct Calculate));
    cal->top=-1;
    return cal;
}

float CalPop(CalculatePost cal)
{
    if(cal->top==-1)
        printf("Stack empty");
    else
    {
        
        float a=cal->Cal[cal->top];
        cal->Cal[cal->top]='\0';
        cal->top--;
        
        return a;
    }
}

void CalPush(CalculatePost cal,float x)
{
    if(cal->top==MAXSIZE-1)
    {
        printf("FULL!\n");
        
    }
    else
    {
        cal->top++;
        cal->Cal[cal->top]=x;
        
    }
}

void Stack(CalculatePost cal,PostArray array)
{
    CalculatePost p=cal;
    PostArray q=array;
    for(int i=0;i<cnt;i++)
    {
        char c=array->Post[i];
        int x=c;
        if(x>=48&&x<=57)//数字进栈
        {
            x=x-48;
            CalPush(cal,x);
        }
            
        else
        {
            float a=CalPop(cal);
            float b=CalPop(cal);
            float sum;
            if(x==43)
                sum=a+b;
            else if(x==45)
                sum=b-a;
            else if(x==42)
                sum=a*b;
            else if(x==47)
                sum=b/a;
            CalPush(cal,sum);
        }
    }
    printf("%.2f\n",cal->Cal[0]);
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
    else return -10;
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
    else
        return -10;
}

void Push(LinkStack linkstack,char c)
{
    if(linkstack->top==MAXSIZE-1)
    {
        printf("FULL!\n");
        
    }
    else
    {
        linkstack->top++;
        linkstack->Data[linkstack->top]=c;
        
    }
}

void PopAndPrint(LinkStack linkstack,PostArray Array)
{
    if(linkstack->top==-1)
        printf("Stack empty");
    else
    {
        cnt++;
        Array->now++;
        char b=linkstack->Data[linkstack->top];
        linkstack->Data[linkstack->top]='\0';
        linkstack->top--;
        Array->Post[Array->now]=b;
    }
}

void PopOnly(LinkStack linkstack)
{
    if(linkstack->top==-1)
        printf("Stack empty");
    else
        linkstack->Data[linkstack->top]='\0';
        linkstack->top--;
}

LinkStack DecideAndPush(LinkStack linkstack,PostArray Array,char c)
{
    if(linkstack->top==-1)
        Push(linkstack,c);
    else
    {
        while(1)
        {
            char a=linkstack->Data[linkstack->top];
        
            if(ISP(a)>ICP(c))
            {
                PopAndPrint(linkstack,Array);
            }
            else if(ISP(a)<ICP(c))
            {
                Push(linkstack,c);
                break;
            }
            else if(ISP(a)==ICP(c))
            {
                PopOnly(linkstack);
                break;
            }
        }
        
    }
    return linkstack;
}

LinkStack Postfix(LinkStack linkstack,PostArray Array)
{
    // printf("11\n");
    char c[50];
    fgets(c,30,stdin);
    // printf("44444\n");
    for(int i=0;c[i]!='\0';i++)
    {
        
        int n=c[i];
        if(n>=40&&n<=47)
        {
            linkstack=DecideAndPush(linkstack,Array,c[i]);
            
        }
        else if((n>=48&&n<=57))
        {
            Array->now++;
            Array->Post[Array->now]=c[i];
            cnt++;
        }
    }
    if(linkstack->top!=-1)
    {
        for(int i=linkstack->top;i>=0;i--)
            PopAndPrint(linkstack,Array);
    }
    return linkstack;
}

void PrintArray(PostArray array)
{
    // printf("\n"); 
    for(int i=0;i<cnt;i++)
        printf("%c ",array->Post[i]);
}

void PrintStack(LinkStack linkstack)
{
    for(int i=0;i<linkstack->top;i++)
        printf("%c",linkstack->Data[0]);
}

int main()
{
    LinkStack linkstack=InitStack();
    PostArray array=InitArray();
    linkstack=Postfix(linkstack,array);//
    CalculatePost cal=InitCal();

    Stack(cal,array);
    PrintArray(array);
    printf("\n");
    
}
// 2*(3+4)/5#
// 3234+5
// 234+*5/
// 1+2-3*((4+5)/6-7)+8#