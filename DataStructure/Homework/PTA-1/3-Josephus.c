#include <stdio.h>
#include <stdlib.h>

typedef struct Link *LinkList;
struct Link
{
	int data;
	LinkList next;
};

LinkList InitList(int n)
{
	LinkList Head=(LinkList)malloc(sizeof(struct Link));
	LinkList current=Head;
	Head->data=1;
	Head->next=NULL;
	for(int i=2;i<=n;i++)
	{
		LinkList p=(LinkList)malloc(sizeof(struct Link));
		current->next=p;
		p->data=i;
		current=p;
	}
	current->next=Head;
	return Head;
}

void PrintList(LinkList linklist)
{
	LinkList temp=linklist;
	while(temp->next!=linklist)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
	printf("\n");
}

void Josephus(LinkList linklist,int m)
{
	LinkList pre=linklist,current=linklist;
	while(current->next!=current)
	{
		for(int i=0;i<m;i++)
		{
			pre=current;
			current=current->next;
		}
		LinkList temp=current;
		printf("%d,",temp->data);
		
		pre->next=current->next;
		current=pre->next;
		free(temp);
	}
	printf("%d\n",current->data);
}

int main()
{
	int n,m;
	scanf("%d,%d",&n,&m);
	LinkList linklist=InitList(n);
	PrintList(linklist);
	Josephus(linklist,m);
}