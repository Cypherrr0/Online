#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Person;
struct Node
{
    int data;
    Person next;
    Person front;
};

Person InitList(int n)
{
    Person head,temp,current;
    head=(Person)malloc(sizeof(struct Node));
    head->next=NULL;
    head->front=NULL;
    head->data=1;
    current=head;
    for(int i=2;i<=n;i++)
    {
        temp=(Person)malloc(sizeof(struct Node));
        temp->data=i;
        current->next=temp;
        temp->front=current;
        current=temp;
        temp->next=NULL;
    }
    current->next=head;
    head->front=current;
    return head;
}

Person Josephus(Person head,int m)
{
    Person current=head,former;
    int control=1;
    while(current->next!=head)
    {
        if(control%2!=0)
        {
            printf("NEXT\n");
            for(int i=1;i<=m;i++)
                current=current->next;
            printf("%d ",current->data);
            former=current->front;
            former->next=current->next;
            free(current);
            current=former->next;
            current->front=former;
        }
        else
        {
            printf("FRONT\n");
            for(int i=1;i<=m;i++)
                current=current->front;
            printf("%d ",current->data);
            former=current->front;
            former->next=current->next;
            Person temp=current->front;
            free(current);
            current=former->front;
            current->next=temp;
        }
        control++;
    }
}

int main()
{
    int n,m;
    scanf("%d,%d",&n,&m);
    Person head=InitList(n);
    Josephus(head,m);
}