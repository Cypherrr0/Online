#include <stdio.h>
#include <stdlib.h>
//21:52
#define MAXSIZE 50
typedef struct stack *LinkStack;
struct stack
{
	char data[MAXSIZE];
	int top;
};

int cnt1=0,cnt2=0,cnt3=0;

LinkStack InitStack()
{
	LinkStack linkstack=(LinkStack)malloc(sizeof(struct stack));
	linkstack->top=-1;
	return linkstack;
}

void push(LinkStack linkstack,char c)
{
	linkstack->top++;
	linkstack->data[linkstack->top]=c;
}

char gettop(LinkStack linkstack)
{
	return linkstack->data[linkstack->top];
}

void pop(LinkStack linkstack)
{
	
	linkstack->data[linkstack->top]='\0';
	linkstack->top--;
}

void Match(LinkStack linkstack,char c)
{
	char x=gettop(linkstack);
	if(c=='('||c=='['||c=='{')
		push(linkstack,c);
	else
	{
		if(linkstack->top==-1)
		{
			if(c==')')
				cnt1=1;
			else if(c==']')
				cnt2=2;
			else if(c=='}')
				cnt3=3;
		}
		if(c==')')
		{
			if(x=='(')
				pop(linkstack);
			else if(x=='[')
			{
				cnt2=2;
				cnt1=1;
			}
				
			else if(x=='{')
			{
				cnt3=3;
				cnt1=1;
			}
				
				
		}
		else if(c==']')
		{
			if(x=='[')
				pop(linkstack);
			else if(x=='(')
			{
				cnt1=1;
				cnt2=2;
			}
				
			else if(x=='{')
			{
				cnt3=3;
				cnt2=2;
			}
				
		}
		else if(c=='}')
		{
			if(x=='{')
				pop(linkstack);
			else if(x=='[')
			{
				cnt2=2;
				cnt3=3;
			}
				
			else if(x=='(')
			{
				cnt1=1;
				cnt3=3;
			}
				
		}
	}
}

int main()
{
	LinkStack linkstack=InitStack();
	char temp[MAXSIZE];
	fgets(temp,MAXSIZE,stdin);
	for(int i=0;temp[i]!='\0';i++)
	{
		char c=temp[i];
		Match(linkstack,c);
	}

	while(linkstack->top!=-1)
	{
		char x=gettop(linkstack);
		if(x=='(')
			cnt1=1;
		else if(x=='[')
			cnt2=2;
		else if(x=='{')
			cnt3=3;
		pop(linkstack);
	}
	if(cnt1==1)
		printf("1,");
	if(cnt2==2)
		printf("2,");
	if(cnt3==3)
		printf("3,");
	if(cnt1==0&&cnt2==0&cnt3==0)
		printf("0\n");
	else
		printf("\n");
}
