#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nextPtr;
};
struct Node* createList();
void freelist(struct Node*headPtr);
void EXlist(struct Node**headPtr,int s1,int t1,int s2,int t2);
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

void EXlist(struct Node **headPtr,int s1,int t1,int s2,int t2)
{
    struct Node *s1Ptr=*headPtr,*t1Ptr=*headPtr,*s2Ptr=*headPtr,*t2Ptr=*headPtr;
    struct Node *temp1=*headPtr,*temp2=*headPtr,*temp3=*headPtr,*temp4=*headPtr;
    int a=1,b=1,c=1,d=1,e=1,f=1,g=1,h=1;

    while(a<s1-1)
    {
        s1Ptr=s1Ptr->nextPtr;
        a++;
    }
    while(b<s1)
    {
        temp1=temp1->nextPtr;
        b++;
    }
    while(c<t1)
    {
        t1Ptr=t1Ptr->nextPtr;
        c++;
    }

    while(e<s2-1)
    {
        s2Ptr=s2Ptr->nextPtr;
        e++;
    }
    while(f<s2)
    {
        temp3=temp3->nextPtr;
        f++;
    }
    while(g<t2)
    {
        t2Ptr=t2Ptr->nextPtr;
        g++;
    }

    temp4=t2Ptr->nextPtr;

    if(s1==1)
    {
       *headPtr=temp3;
    }
    else
        s1Ptr->nextPtr = temp3;
    if(s2-t1!=1)
    {
        t2Ptr->nextPtr=t1Ptr->nextPtr;
        s2Ptr->nextPtr=temp1;
        t1Ptr->nextPtr=temp4;
    }
    else
    {
        t2Ptr->nextPtr = temp1;
        t1Ptr->nextPtr = temp4;
    }
    

}

int main()
{
    int s1,t1,s2,t2;
    struct Node *headPtr=createList();
    scanf("%d%d%d%d",&s1,&t1,&s2,&t2);
    
    EXlist(&headPtr,s1,t1,s2,t2);
    
    printf("The new list is:");
    while(headPtr)
    {
        if(headPtr->nextPtr)
        {
            printf("%d ",headPtr->data);
        }
        else
        {
            printf("%d\n",headPtr->data);
        }
            
        headPtr=headPtr->nextPtr;
    }
    freelist(headPtr);
}