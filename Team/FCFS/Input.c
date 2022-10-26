#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct Request
{
    int target;
    int ccw,cw;
    struct Request *next;
}LinkList;

LinkList *input_struct();
void free_linklist(LinkList *head); 

LinkList *input_struct()
{
    char end[10]="end";
    char clock[10]="clock";
    char str1[20];
    strcpy(str1,"clockwise");
    char str2[20];
    strcpy(str2,"counterclockwise");
    char str3[20];
    strcpy(str3,"target");
    char input[20];
    int num;

    LinkList *head = (LinkList *)malloc(sizeof(LinkList));
    head->target = 0;
    head->ccw = 0;
    head->cw = 0;
    head->next = NULL;
    LinkList *temp = NULL;
    LinkList *last = head;
    scanf("%s",input);
    while(strcmp(end,input)!=0)
    {
        
        if(strcmp(str1,input)==0)
        {
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            temp->target=0;
            temp->cw=num;
            temp->ccw=0;
            temp->next=NULL;
            last->next=temp;
            last=temp;
        }
        else if(strcmp(str2,input)==0)
        {
        	temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            temp->target=0;
            temp->cw=0;
            temp->ccw=num;
            temp->next=NULL;
            last->next=temp;
            last=temp;
        }
        else if(strcmp(str3,input)==0)
        {
        	temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            temp->target=num;
            temp->cw=0;
            temp->ccw=0;
            temp->next=NULL;
            last->next=temp;
            last=temp;
        }
        scanf("%s",input);
    }
    return head;
}

void free_linklist(LinkList *head)
{
    LinkList *temp = head;
    LinkList *next = NULL;
    while(temp!=NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

int main()
{
	LinkList *p = input_struct();
    LinkList *q = p;
    q=q->next;
    while(q!=NULL)
    {
        printf("target:%d ccw:%d cw:%d\n",q->target,q->ccw,q->cw);
        q=q->next;
    }
    free_linklist(p);
}
