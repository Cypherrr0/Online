#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nextPtr;
};
struct Node* createList();
void freelist(struct Node*headPtr);
void printList(struct Node*headPtr);
int isPalindrome(struct Node*headPtr);

//判断链表是否为回文链表
int isPalindrome(struct Node*headPtr)
{
    struct Node *p=headPtr,*q=headPtr;
    int count=0;
    while(p!=NULL)
    {
        p=p->nextPtr;
        count++;
    }
    p=headPtr;
    while(count>0)
    {
        q=q->nextPtr;
        count--;
    }
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            return 0;
        }
        p=p->nextPtr;
        q=q->nextPtr;
    }
    return 1;
}


struct Node* createList()
{
    int num;
    struct Node * currentPtr=NULL;
    struct Node * headPtr=NULL;
    struct Node * lastPtr=NULL;
    
    scanf("%d", &num);
    while(num!=-1)
    {
        currentPtr=(struct Node*)malloc(sizeof(struct Node));
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
//打印链表
void printList(struct Node*headPtr)
{
    struct Node *p;
    p=headPtr;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->nextPtr;
    }
    printf("\n");
}

void freelist(struct Node*headPtr)
{
    struct Node *p;
    while(headPtr!=NULL)
    {
        p=headPtr;
        headPtr=headPtr->nextPtr;
        free(p);
    }
}
int main()
{
    struct Node *headPtr;
    headPtr=createList();
    printList(headPtr);
    int a=isPalindrome(headPtr);
    if(a==1)
    {
        printf("true");
    }
    else
    {
        printf("false\n");
    }
    freelist(headPtr);
    return 0;
}