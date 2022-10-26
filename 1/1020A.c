#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nextPtr;
};
struct Node* createList();
void freelist(struct Node*headPtr);
int findMAX(struct Node * headPtr);
int findMIN(struct Node * headPtr);
int sum;

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
            sum=sum+num;
            if(headPtr==NULL)//如果currentPtr是头结点
            {
                headPtr=currentPtr;//就一个结点，首尾都是他
                lastPtr=currentPtr;
            }
            else 
            {
                lastPtr->nextPtr=currentPtr;//将新结点连上链表尾结点后面 用last指向next，next就是current
                lastPtr=currentPtr;//使last指向当前链表的最后一个结点（就是新增的这个）
            }
        }
        scanf("%d", &num);
    }
    lastPtr->nextPtr=NULL;//设置链表结束标记
    return headPtr;
}

int findMAX(struct Node * headPtr)
{
    struct Node *p,*q;
    p=headPtr;
    q=headPtr;
    int max=0,min;
    while(p !=NULL)
    {
        if(max<p->data)
        {
            max=p->data;
        }
        p=p->nextPtr;
    }
    return max;
}

int findMIN(struct Node * headPtr)
{
    struct Node *q;
    q=headPtr;
    int min=q->data;
    while(q !=NULL)
    {
        if(min>q->data)
        {
            min=q->data;
        }
        q=q->nextPtr;
    }
    return min;
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
    int max,min;
    max=findMAX(headPtr);
    min=findMIN(headPtr);
    printf("The maximum,minmum and the total are:%d %d %d\n",max,min,sum);
    headPtr=NULL;
    freelist(headPtr);
}