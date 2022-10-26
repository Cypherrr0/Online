#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
}*Link;

Link AppendNode(Link head,int data);
void DisplyNode(Link head);

int main()
{
    int    data;
    Link head = NULL;
    while (1)
    {
        scanf("%d",&data);
        if (data==-1)
            break;
        head = AppendNode(head,data);
    }
    DisplyNode(head);
    return 0;
}


Link AppendNode(Link head,int data)
{
    Link currentPtr =(struct link*)malloc(sizeof(struct link));
    currentPtr->data = data;
    currentPtr->next = NULL;
    if(head==NULL)
    {
        head=currentPtr;

    }
    else
    {
        Link tempPtr=head;
        while(tempPtr->next!=NULL)
        {
            tempPtr=tempPtr->next;
        }
        tempPtr->next=currentPtr;
    }
    return head;
}
void DisplyNode(Link head)
{
    if(head==NULL)
    {
        printf("NULL");
    }
    while(head!=NULL)
    {
        printf("%d",head->data);
        if(head->next!=NULL)
        {
            printf(",");
            Link tempPtr=head;
            head=head->next;
            
        }
    }
}