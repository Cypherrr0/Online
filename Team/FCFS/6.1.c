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

int total_station;
int distance;

int Distance_Cal(int position, int target, int Total_distance,int total_station);
LinkList *CreateList();
void CarDrive(int mark,int position,int Total_distance);
void Output(int position,int target_output[total_station],int clockwise_output[total_station],int counterclockwise_output[total_station]);
LinkList *DeleteHead(LinkList *pHead);

LinkList *CreateList()
{
    LinkList *head=(LinkList *)malloc(sizeof(LinkList));
    head->target = 0;
    head->ccw = 0;
    head->cw = 0;
    head->next = NULL;
    return head;
}

LinkList *DeleteHead(LinkList *pHead)
{
    if(pHead==NULL)
    {
        return NULL;
    }
    LinkList *pTemp=pHead->next;
    free(pHead);
    if(pTemp==NULL)
    {
        return NULL;
    }
    pHead=pTemp;
    return pHead;
}

int Distance_Cal(int position,int target,int Total_distance,int total_station)
{
    if(position > (target-1)*distance)
    {
        if(fabs(position-(target-1)*distance)*2>=Total_distance)
        {
            return 1;//cw
        }
        else
        {
            return 0;//ccw
        }
    }
    else if(position < (target-1)*distance)
    {
        if(fabs(position-(target-1)*distance)*2<=Total_distance)
        {
            return 1;//cw
        }
        else
        {
            return 0;//ccw
        }
    }
}
//////////��
void CarDrive(int mark,int position,int Total_distance)
{
    if(mark==1)//cw
    {
        if(position+1 == Total_distance)
        {
            position=0;
        }
        else
        {
            position++;
        }
    }
    else//ccw
    {
        if(position-1 == Total_distance)
        {
            position=Total_distance;
        }
        else
        {
            position--;
        }
    }
}




int main()
{
    int Total_distance=distance*total_station;
    char end[10]="end";
    char clock[10]="clock";
    char str1[20]; strcpy(str1,"clockwise");
    char str2[20]; strcpy(str2,"counterclockwise");
    char str3[20]; strcpy(str3,"target");
    char str4[20];strcpy(str4,"clock");
    
    char input[20];
    int num;int mark;
    int position=0;
    int target_num=0;
    
    total_station=5;
    distance=3;
    
    LinkList *p=CreateList();
    LinkList *temp = p;
    LinkList *last = p;

    int target_output[total_station-1] ;
    int clockwise_output[total_station-1];
    int counterclockwise_output[total_station-1];

    scanf("%s",input);

    while(strcmp(end,input)!=0)
    {
        if(strcmp(str4,input)==0)//clock
        {   
            if(position % distance == 0)//�����վ��
            {  
                printf("%d", p->target);
                int a=temp->cw;
                int b=temp->ccw;
                int c=temp->target;
                if(a!=0)
                {
                    target_num=a;
                    mark=1;
                }
                if(b!=0)
                {
                    target_num=b;
                    mark=2;
                }
                if(c!=0)
                {
                    target_num=c;
                    mark=3;
                }
                //�������
                if(position==(target_num-1)*distance&&a!=0&&b!=0&&c!=0)
                {   
                    LinkList *pCheck=p->next;
                    int count = 1;
                    //
                    while(pCheck->cw == target_num)
                    {
                        pCheck=pCheck->next;
                        count++;
                    }
                    pCheck=p->next;count = 1;
                    //
                    while(pCheck->ccw == target_num)
                    {
                        pCheck=pCheck->next;
                        count++;
                    }
                    pCheck=p->next;count = 1;
                    //
                    while(pCheck->target == target_num)
                    {
                        pCheck=pCheck->next;
                        count++;
                    }
                    pCheck=p->next;count = 1;
                    //
                    while(count > 0)//��ǰ����ɵ�����Ŀ�ĺ���һ������Ŀ����ͬ
                    {
                        p = DeleteHead(p);
                        count--;
                    }
                    temp=p;
                    //�����������
                    if(mark==1)//�����ɵ���cw
                    {
                        clockwise_output[target_num-1]=0;
                    }
                    else if(mark==2)//�����ɵ���ccw
                    {
                        counterclockwise_output[target_num-1]=0;
                    }
                    else if(mark==3)//�����ɵ���target
                    {
                        target_output[target_num-1]=0;
                    }
                    Output(position , target_output[total_station], clockwise_output[total_station], counterclockwise_output[total_station]);
                }

            }
            else //�������վ��
            {
                Output(position , target_output[total_station], clockwise_output[total_station], counterclockwise_output[total_station]);
                mark = Distance_Cal(position,target_num,Total_distance,total_station);
                CarDrive(mark,position,Total_distance);
            }
        }
        else if(strcmp(str1,input)==0)//cw
        {
            
            scanf("%d",&num);
            //�ж�clockwise_output[num-1]�Ƿ�Ϊ0
            //Ϊ0���ӽ�㣬Ϊ1�����ӽ��
            if(clockwise_output[num-1]==0)
            {
                temp->target=0;
                temp->cw=num;
                temp->ccw=0;
                temp->next=NULL;
                last->next=temp;
                last=temp;
                clockwise_output[num-1]=1;
            }
            
        }
        else if(strcmp(str2,input)==0)//ccw
        {
            
            scanf("%d",&num);
            if(counterclockwise_output[num-1]==0)
            {
                temp->target=0;
                temp->cw=0;
                temp->ccw=num;
                temp->next=NULL;
                last->next=temp;
                last=temp;
                counterclockwise_output[num-1]=1;
            }
            
        }
        else if(strcmp(str3,input)==0)//target
        {
            
            scanf("%d",&num);
            if(target_output[num-1]==0)
            {
                temp->target=num;
                temp->cw=0;
                temp->ccw=0;
                temp->next=NULL;
                last->next=temp;
                last=temp;
                target_output[num-1]=1;
            }
        }
        scanf("%s",input);
    }

    free(target_output);
    free(clockwise_output);
    free(counterclockwise_output);
}
void Output(int position,int target_output[total_station],int clockwise_output[total_station],int counterclockwise_output[total_station])
{
    printf("BUS:\n");
    printf("position:%d\n",position);
    printf("target:");
    for(int i=0;i<total_station;i++)
    {
        printf("%d",target_output[i]);
    }
    printf("\nSTATION:\n");
    printf("clockwise:");
    for(int i=0;i<total_station;i++)
    {
        printf("%d",clockwise_output[i]);
    }
    printf("\n");
    printf("counterclockwise:");
    for(int i=0;i<total_station;i++)
    {
        printf("%d",counterclockwise_output[i]);
    }
    printf("\n\n");
}