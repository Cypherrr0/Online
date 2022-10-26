#include <stdio.h>
#include <stdlib.h>

// 20:03

int cnt=0;

typedef struct list *LinkList;
struct list
{
	char data;
	LinkList next;
};

LinkList CreateList()
{
	char c;
	scanf("%c",&c);
	LinkList head,current;
	head=(LinkList)malloc(sizeof(struct list));
	head->data=c;
	head->next=NULL;
	current=head;
	cnt++;
	scanf("%c",&c);
	while(c!='\n')
	{
		if(c!=',')
		{
			LinkList p;
			p=(LinkList)malloc(sizeof(struct list));
			current->next=p;
			p->data=c;
			p->next=NULL;
			current=p;
			
			cnt++;
		}
		scanf("%c",&c);
	}
	return head;
}

LinkList FindTerm(LinkList linklist,int n)
{
	LinkList temp=linklist;
	for(int i=1;i<n;i++)
	{
		temp=temp->next;
	}
	return temp;
}

int ListMatch(LinkList linklist)
{
	int hold=1;
	int sum=hold+cnt;
	LinkList Front,Rear;
	if(cnt%2==0)
		return 0;
	else
	{
		while(1)
		{
		
		Front=FindTerm(linklist,hold);
		Rear=FindTerm(linklist,sum-hold);
		if(Front->data!=Rear->data)
		{
			return 0;
			break;
		}
		else if(hold==(cnt/2)+1)
		{
			return 1;
			break;
		}
		else
			hold++;
		}
	}
	
}

void PrintList(LinkList linklist)
{
	LinkList p=linklist;
	while(p!=NULL)
	{
		printf("%c ",p->data);
		p=p->next;
	}
}

int main()
{
	LinkList linklist=CreateList();
	PrintList(linklist);
	printf("\n");
	int judge=ListMatch(linklist);
	if(judge==1)
		printf("Yes\n");
	else if(judge==0)
		printf("No\n");
	else
		printf("??\n");
}
