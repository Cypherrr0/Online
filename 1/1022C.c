#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nextPtr;
};
struct Node* createList();
void freelist(struct Node*headPtr);
void judge(struct Node *headPtr1,struct Node *headPtr2);

struct Node* createList()
{
    int num;
    struct Node * currentPtr=NULL;
    struct Node * headPtr=NULL;
    struct Node * lastPtr=NULL;
    
    scanf("%d", &num);
    while(num!=-1)
    {
        currentPtr=(struct Node*)malloc(sizeof(struct Node));//动态申请节点内存存放数据
        if(currentPtr!=NULL)
        {
            currentPtr->data=num;
            if(headPtr==NULL)
            {
                headPtr=currentPtr;
                lastPtr=currentPtr;
            }
            else
            {
                lastPtr->nextPtr=currentPtr;
                lastPtr=currentPtr;
            }
        }
        
        scanf("%d", &num);
    }
    lastPtr->nextPtr=NULL;
    return headPtr;
}

void judge(struct Node *headPtr1,struct Node *headPtr2)
{

    struct Node *newPtr1=headPtr1;
    struct Node *newPtr2=headPtr2;
    struct Node *p=NULL,*q=NULL;
    int mark=0;
    while(newPtr1)
    {
        if(newPtr1->data==newPtr2->data)
        {
            p=newPtr1;
            q=newPtr2;
            while(p&&q)
            {
                if(p->data==q->data)
                {
                    p=p->nextPtr;
                    q=q->nextPtr;
                }
                else
                {
                    break;
                }
            }
            if(!q)
            {
                mark=1;
                printf("ListB is the sub sequence of ListA.");
                break;
            }
        }
        newPtr1=newPtr1->nextPtr;
    }
    if(mark==0)
    {
        printf("ListB is not the sub sequence of ListA.");
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
    struct Node * headPtr1=createList();
    struct Node * headPtr2=createList();
    judge(headPtr1,headPtr2);
    freelist(headPtr1);
    freelist(headPtr2);
    headPtr1=NULL;
    headPtr2=NULL;
}