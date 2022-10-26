#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
struct stack
{
    char data[MAXSIZE];
    int top;
};
typedef struct stack *LinkStack;

LinkStack InitStack()
{
    LinkStack linkstack=(LinkStack)malloc(sizeof(struct stack));
    linkstack->top=-1;
    return linkstack;
}

void StackPopOnly(LinkStack linkstack)
{
    linkstack->data[linkstack->top]='\0';
    linkstack->top--;
}

void StackPush(LinkStack linkstack,char c)
{
    linkstack->top++;
    linkstack->data[linkstack->top]=c;
}

int main()
{
    char temp[MAXSIZE],postfix[MAXSIZE];
    LinkStack linkstack=InitStack();
    int x=-1;//postfix数组的位置
    fgets(temp,MAXSIZE,stdin);
    for(int i=0;temp[i]!='\0';i++)
    {
        char mid=temp[i];
        if(mid=='0'||mid=='1'||mid=='2'||mid=='3'||mid=='4'||mid=='5'||mid=='6'||mid=='7'||mid=='8'||mid=='9')
        {
            x++;
            postfix[x]=mid;
        }
        else if(mid=='+'||mid=='-')
        {
            while(linkstack->top!=-1&&linkstack->data[linkstack->top]!='(')
            {
                x++;
                postfix[x]=linkstack->data[linkstack->top];
                StackPopOnly(linkstack);
            }
            StackPush(linkstack,mid);
        }
        else if(mid=='*'||mid=='/')
        {
            while(linkstack->top!=-1&&(linkstack->data[linkstack->top]=='*'||linkstack->data[linkstack->top]=='/'))
            {
                x++;
                postfix[x]=linkstack->data[linkstack->top];
                StackPopOnly(linkstack);
            }
            StackPush(linkstack,mid);
        }
        else if(mid=='(')
        {
            StackPush(linkstack,mid);
        }
        else if(mid==')')
        {
            while(linkstack->top!=-1&&linkstack->data[linkstack->top]!='(')
            {
                x++;
                postfix[x]=linkstack->data[linkstack->top];
                StackPopOnly(linkstack);
            }
            if(linkstack->data[linkstack->top]=='(')
            {
                StackPopOnly(linkstack);
            }
        }
    }
    while(linkstack->top!=-1)
    {
        x++;
        postfix[x]=linkstack->data[linkstack->top];
        StackPopOnly(linkstack);
    }

    float calculate[MAXSIZE];
    int a=-1;//for calculate array
    for(int i=0;i<=x;i++)
    {
        if(postfix[i]=='0'||postfix[i]=='1'||postfix[i]=='2'||postfix[i]=='3'||postfix[i]=='4'||postfix[i]=='5'||postfix[i]=='6'||postfix[i]=='7'||postfix[i]=='8'||postfix[i]=='9')
        {
            a++;
            calculate[a]=postfix[i]-'0';
        }
        else
        {
            float y=calculate[a-1];
            float z=calculate[a];
            a=a-2;
            a++;
            if(postfix[i]=='+')
                calculate[a]=y+z;
            else if(postfix[i]=='-')
                calculate[a]=y-z;
            else if(postfix[i]=='*')
                calculate[a]=y*z;
            else if(postfix[i]=='/')
                calculate[a]=y/z;
        }
    }
    printf("%.2f\n",calculate[0]);
    for(int i=0;i<=x;i++)
        printf("%c ",postfix[i]);
    printf("\n");
}