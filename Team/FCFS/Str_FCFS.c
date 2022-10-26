#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Request
{
    int target;
    int ccw,cw;
    struct Request *next;
}LinkList;

int total_station=5;
int distance=3;

int Distance_Cal(int position, int target, int total_station);
int wise_clock_position();
LinkList *input_struct();
void clockwise(int total_station);
void Cclockwise();
void conti_check();
void RequestList();


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

int Distance_Cal(int position,int target,int total_station)
{
    if(fabs(target - position) <= total_station/2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int wise_clock_position(int mark,int position,int target,int total_station,int distance)
{
    if(mark==0)
    {
        while(position!=target*distance)
        {
            position++;
            if(position==total_station)
            {
                position=0;
            }
        }
        
    }
    else if(mark==1)
    {
        while(position!=target*distance)
        {
            position--;
            if(position==-1)
            {
                position=total_station-1;
            }
        }
    }
    return position;
}

void clockwise(int ,int Clockwise_Mark)
{
    
    if(Clockwise_Mark==1)
    {
        
    }
}

void Cclockwise()
{

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
    FILE *dict;
    dict = fopen("dict.txt","r");
    char total_station[20];
    char strategy[20];
    char distance[20];
    char FCFS[20];
    char SSTF[20];
    char SCAN[20];
    strcpy(total_station,"total_station");
    strcpy(strategy,"strategy");
    strcpy(distance,"distance");
    strcpy(FCFS,"FCFS");
    strcpy(SSTF,"SSTF");
    strcpy(SCAN,"SCAN");
    char Unknown1[20];
    char Unknown2[10];
    int num_TOTAL;
    int num_DISTANCE;
    for(int i=0;i<3;i++)
    {
        fscanf(dict,"%[^=]",Unknown1);
        if(strcmp(total_station,Unknown1)==0)
        {
            getchar();
            scanf("%d",&num_TOTAL);
        }
        else if(strcmp(strategy,Unknown1)==0)
        {
            getchar();
            scanf("%[^\n]",Unknown2);
            if(strcmp(FCFS,Unknown2))
            {
                printf("FCFS");
            }
            else if(strcmp(SSTF,Unknown2))
            {
                printf("SSTF");
            }
            else if(strcmp(SCAN,Unknown2))
            {
                printf("SCAN");
            }
        }
        else if(strcmp(distance,Unknown1))
        {
            getchar();
            scanf("%d",&num_DISTANCE);
        }
    }

    int position=0;
    LinkList *p = input_struct();
    LinkList *q=p;
    while(q!=NULL)
    {
        int target_num;
        target_num=q->target;
        if(target_num==0)
        {
            target_num=q->cw;
        }
        if(target_num==0)
        {
            target_num=q->ccw;
        }
        int mark=distance_cal(position,target_num,total_station);
        
        wise_clock_position(mark,position,target_num,total_station,distance);
        q->target=0;
        q->cw=0;
        q->ccw=0;
    }


    free_linklist(p);
}