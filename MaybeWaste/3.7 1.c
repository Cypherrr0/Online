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
    while(count<=t)
    {
        int n;
        scanf("%d", &n);
        currentPtr=NULL;
        headPtr=NULL;
        lastPtr=NULL;
        
        for(int i=0;i<n;i++)
        {
            scanf("%d", &num);
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
            
        }
        lastPtr->nextPtr=NULL;
        
        currentPtr=headPtr;
        int temp=1,count1=0;
        while(currentPtr!=NULL)
        {
            if(temp%2==0)//加上temp++，只有temp是偶数的时候才输出，奇数的时候也照常current转到下一个
            {
                if(count1==0)
                {
                    count1++;
                }
                else
                {
                    printf(" ");
                }
                printf("%d",currentPtr->data);
            }
            temp++;
            currentPtr=currentPtr->nextPtr;

        }
        printf("\n");
        count++;
        
    }
    return headPtr;
}
main()
{
    struct Node *head=createFIFOList();
}