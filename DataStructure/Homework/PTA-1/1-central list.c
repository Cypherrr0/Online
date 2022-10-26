#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cnt = 0;

typedef struct LinkNode *Link;
struct LinkNode
{
    int Data;
    Link next;
};

Link CreateLinkList()
{
    cnt=1;
    Link Head,current,p;
    Head=(Link)malloc(sizeof(struct LinkNode));
    Head->next=NULL;
    current=Head;
    char num,ch;
    scanf("%c",&num);
    while(num!='\n')
    {
        if(isdigit(num)!=0)
        {
            p=(Link)malloc(sizeof(struct LinkNode));
            current->next=p;
            current=p;
            p->next=NULL;
            p->Data=num;
            cnt++;
        }
        scanf("%c",&num);
            
    }
    Head=Head->next;
    cnt--;
    return Head;
}

void PrintLinkList(Link Head)
{
    Link q=Head;
    
    while(q!=NULL)
    {
        printf("%c ",q->Data);
        q=q->next;
    }
}

Link FindNode(Link Head,int num)
{
    Link temp=Head;
    num--;
    for(;num!=0;num--)
    {
        temp=temp->next;
    }
    return temp;
}

int CentralList(Link Head)
{
    int hold=1,sum=hold+cnt;
    Link Front,Rear;
    if(cnt%2==0)
        return 0;
    else
    {
        while(1)
        {
            Front=FindNode(Head,hold);
            Rear=FindNode(Head,sum-hold);
            if((Front->Data!=Rear->Data))
            {
                return 0;
                break;
            }
                
            else if(hold==(cnt/2)+1)
            {
                return 1;
                break;
            }
                
            else
                hold++;
        }
    }
}

int main()
{
    Link Head=CreateLinkList();
    PrintLinkList(Head);
    // printf("\n%d",cnt);
    int judge=CentralList(Head);
    if(judge==0)
        printf("No\n");
    else
        printf("Yes\n");
}