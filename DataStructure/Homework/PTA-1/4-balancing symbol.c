#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100
struct Stack
{
    char data[MAXSIZE];
    int top;
};

int cnt1=0;//for()
int cnt2=0;//for[]
int cnt3=0;//for{}
int hold=0;

typedef struct Stack *Brackets;

Brackets InitStack()
{
    Brackets stack;
    stack=(Brackets)malloc(sizeof(struct Stack));
    stack->top=-1;
    return stack;
}

void Push(Brackets stack,char c)
{
    if(stack->top==MAXSIZE-1)
        printf("FULL!");
    else
    {
        stack->top++;
        stack->data[stack->top]=c;
    }
}

char Top(Brackets stack)
{
    return stack->data[stack->top];
}

void Pop(Brackets stack)
{
    if(stack->top==-1)
        printf("EMPTY!!\n");
    else
    {
        stack->data[stack->top]='\0';
        stack->top--;
    }
}

bool JudgeMatch(Brackets stack,char c)
{
    char x=Top(stack);
    if(x=='('&&c==')')
        return true;
    else if(x=='('&&c!=')')
    {
        cnt1=1;
        if(c==']')
            cnt2=2;
        else if(c=='}')
            cnt3=3;
        return false;
    }
    if(x=='['&&c==']')
        return true;
    else if(x=='['&&c!=']')
    {
        cnt2=2;
        if(c==')')
            cnt1=1;
        else if(c=='}')
            cnt3=3;
        return false;
    }
    if(x=='{'&&c=='}')
        return true;
    else if(x=='{'&&c!='}')
    {
        cnt3=3;
        if(c==']')
            cnt2=2;
        else if(c==')')
            cnt1=1;
        return false;
    }
}

Brackets BracketsMatch(Brackets stack)
{
    char c[30];
    fgets(c,30,stdin);
    for(int i=0;c[i]!='\0';i++)
    {
        if(c[i]=='('||c[i]=='['||c[i]=='{')
            Push(stack,c[i]);
        else if(c[i]==')'||c[i]==']'||c[i]=='}')
        {
            if(stack->top==-1)
            {
                if(c[i]==')')
                    cnt1=1;
                else if(c[i]==']')
                    cnt2=2;
                else if(c[i]=='}')
                    cnt3=3;
            }
            else
            {
                if(JudgeMatch(stack,c[i])==false)
                    hold=1;
                    // printf("NOT MATCHING!!\n");
                else
                    Pop(stack);
            }
        }
    }
    if(stack->top!=-1)
    {
        while(stack->top!=-1)
        {
            char x=stack->data[stack->top];
            if(x=='(')
                cnt1=1;
            else if(x=='[')
                cnt2=2;
            else if(x=='{')
                cnt3=3;
            stack->top--;
        }
    }
    
}
void PrintStack(Brackets stack)
{
    // for(int i=0;i<stack->top;i++)
        printf("%c",stack->data[0]);
}

int main()
{
    Brackets stack=InitStack();
    BracketsMatch(stack);
    if(cnt1!=0)
        printf("%d,",cnt1);
    if(cnt2!=0)
        printf("%d,",cnt2);
    if(cnt3!=0)
        printf("%d,",cnt3);
    if(cnt1==0&&cnt2==0&&cnt3==0)
        printf("0\n");
    else
        printf("\n");
    // printf("%d",stack->top);
    // PrintStack(stack);
}

// {a*(b-c)-x/2]