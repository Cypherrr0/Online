#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nextPtr;

}; 
struct Node* createFIFOList(){
    int num;
    int t;
    int count=1;
    scanf("%d", &t);
    struct Node * currentPtr=NULL;
    struct Node * headPtr=NULL;
    struct Node * lastPtr=NULL;
    struct Node *p,*q,*tempPtr;
    for(int i=0; i<t; i++)
    {
        currentPtr=NULL;
        headPtr=NULL;
        lastPtr=NULL;
        p=NULL;
        q=NULL;
        tempPtr=NULL;
        scanf("%d", &num);
        while(num!=-1)
        {
            currentPtr=(struct Node*)malloc(sizeof(struct Node));//动态申请节点内存存放数据
            if(currentPtr!=NULL)
            {
                currentPtr->data=num;//插入结点
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

        p=headPtr->nextPtr;    
        headPtr->nextPtr=NULL;
        while(p!=NULL)
        {
            q=p;
            p=p->nextPtr;
            q->nextPtr=headPtr->nextPtr;
            headPtr->nextPtr=q;//方向改变
        }

    //middle作为新的头结点
        tempPtr=headPtr->nextPtr;
        while(tempPtr!=NULL)
        {
            printf("%d",tempPtr->data);
            tempPtr=tempPtr->nextPtr;
            if(tempPtr!=NULL)
            {
                printf(" ");
            }
        }
        if(tempPtr==NULL)
        {
            printf("\n");
        }
    }
    struct Node *Reverse=headPtr; 
    return headPtr;
}

int main()
{
    struct Node *head=createFIFOList();
    
}

