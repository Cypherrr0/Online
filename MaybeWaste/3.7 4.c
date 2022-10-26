#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *front;
}node;
node *create(node *head,int n)
{
    int i=1;
    node *s,*p=head;
    while(i<=n)
    {
        s=(node*)malloc(sizeof(node));
        s->data=i++;
        p->next=s;
        p=p->next;
    }
    p->next=head->next;
    return p->next;
}
int main()
{
    int n,m,k,flag=0;
    node *head,*newstart,*h,*t;
    head=(node*)malloc(sizeof(node));
    scanf("%d%d%d",&n,&m,&k);
    newstart=create(head,n);
    h=newstart;
    while(h!=h->next)
    {
        if(flag==0)
        {
            for(int i=1;i<m-1;i++)
            {
                h=h->next;
            }
            flag=1;
        }
        else if(flag==1)
        {
            for(int i=1;i<k-1;i++)
            {
                h=h->next;
            }
            flag=0;
        }
        t=h->next;
        printf("%d ",h->next->data);
        h->next=t->next;
        h=t->next;
        
    }
}