// 带头结点链表删除x

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode *List;
struct LinkNode
{
    int data;
    List next;
};

List InitList()
{
    List head=(List)malloc(sizeof(struct LinkNode));
    List p,current=head;
    head->next=NULL;
    int num;
    scanf("%d",&num);
    while(num!=-1)
    {
        p=(List)malloc(sizeof(struct LinkNode));
        current->next=p;
        current=p;
        p->next=NULL;
        p->data=num;
        scanf("%d",&num);
    }
    return head;
}

List FindAndDelete(List head,int x)
{
    List p=head->next;
    List pre=head,q;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }
    return head;
}

List SortAndInsert(List head)
{
    
}

void PrintList(List head)
{
    List p=head->next;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}

int main()
{
    printf("START ENTER LIST -1 TO END\n");
    List head=InitList();
    PrintList(head);
    printf("ENTER X:\n");
    int x;
    scanf("%d",&x);
    head=FindAndDelete(head,x);
    PrintList(head);
}