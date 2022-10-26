
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;//4
    struct Node *nextPtr;//4

}; 

struct Node* createFIFOList(){
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
    lastPtr->nextPtr=NULL;//设置链表结束标记
    return headPtr;
}
main()
{
    struct Node *head=createFIFOList();
}