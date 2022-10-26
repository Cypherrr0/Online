#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nextPtr;
};
struct Node* createList();
void freelist(struct Node*headPtr);
void SortList(struct Node*headPtr);
int count=0;

struct Node* createList()
{
    int num;
    struct Node * currentPtr=NULL;
    struct Node * headPtr=NULL;
    struct Node * lastPtr=NULL;
    headPtr=(struct Node*) malloc(sizeof(struct Node));
    headPtr->data=0;
    headPtr->nextPtr=NULL;
    lastPtr=headPtr;
    scanf("%d", &num);
    while(num!=-1)
    {
        currentPtr=(struct Node*)malloc(sizeof(struct Node));//动态申请节点内存存放数据
        if(currentPtr!=NULL)
        {
            currentPtr->data=num;
            lastPtr->nextPtr=currentPtr;
            currentPtr->nextPtr=NULL;
            lastPtr=currentPtr;
        }
        count++;
        scanf("%d", &num);
    }
    lastPtr->nextPtr=NULL;//设置链表结束标记
    return headPtr;
}

void SortList(struct Node*headPtr)
{
    struct Node *q,*p,*end;
    end=NULL;
    while(headPtr->nextPtr!=end)
    {
        q=headPtr;
        p=headPtr->nextPtr;
        while(p->nextPtr!=end)
        {
            if(p->data>p->nextPtr->data)
            {
                q->nextPtr=p->nextPtr;
                p->nextPtr=q->nextPtr->nextPtr;
                q->nextPtr->nextPtr=p;
            }
            else
            {
                p=p->nextPtr;
            }
            q=q->nextPtr;
            
        }
        end=p;
    }
}


void freelist(struct Node*headPtr)
{
	struct Node *temp;
	while(headPtr!=NULL)
	{
		temp=headPtr;
		headPtr=headPtr->nextPtr;
		free(temp);
	}
} 
int main()
{
    struct Node * headPtr=createList();
    int hold=1;
    printf("The new list is:");
    if(count==1)
    {
        printf("%d\n",headPtr->nextPtr->data);
    }
    else
    {
        SortList(headPtr);
        headPtr=headPtr->nextPtr;
        while(headPtr->nextPtr!=NULL)
        {
            printf("%d ",headPtr->data);
            headPtr=headPtr->nextPtr;
            if(headPtr->nextPtr==NULL)
            {
                printf("%d\n",headPtr->data);
                break;
            }
        }
    }
    freelist(headPtr);
    headPtr=NULL;
}