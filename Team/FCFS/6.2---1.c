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
int target_output[100] = {0};
int clockwise_output[100] = {0};
int counterclockwise_output[100] ={0};

int Distance_Cal(int position, int target, int Total_distance);
LinkList *CreateList();
int CarDrive(int mark,int position,int Total_distance);
void Output(int position, int time);
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
    pHead=pTemp;printf("11111\n\n\n\n\n\n");
    return pHead;
}

int Distance_Cal(int position,int target,int Total_distance)
{
    if(position > (target-1)*distance)//车在前
    {
        if((position-(target-1)*distance)*2>=Total_distance)
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
//////////改
int CarDrive(int mark,int position,int Total_distance)
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
    else if(mark == 0)//ccw
    {
        if(position==0)
        {
            position=Total_distance-1;
        }
        else
        {
            position--;
        }
    }
    return position;
}
void Output(int position ,int time)
{
    printf("Time:%d\nBUS:\n",time);
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
    printf("\n");
}
//删除头节点

int main()
{ 
    total_station=5;
    distance=3;
    int Total_distance=distance*total_station;
    char end[10]="end";
    char clock[10]="clock";
    char str1[20]; strcpy(str1,"clockwise");
    char str2[20]; strcpy(str2,"counterclockwise");
    char str3[20]; strcpy(str3,"target");
    char str4[20];strcpy(str4,"clock");
    
    char input[20];
    int num;
    int mark = 100;
    int position=0;
    int target_num=100;
    int time = 0;
    int count = 0;
    
    LinkList *p=CreateList();
    LinkList *last = (LinkList *)malloc(sizeof(LinkList));
    p->next = last;last->next = NULL;
    
    LinkList *HeadNow = p;//指向当前头节点
    LinkList *temp=NULL;//尾插法用
    
    Output(position, time);

    scanf("%s",input);

    while(strcmp(end,input)!=0)
    {
        if(strcmp(str4,input)==0)//clock
        {   
            time++;
            if(position % distance == 0)//如果在站点
            {   
                if(p->ccw != 0 || p->cw != 0 ||p->target != 0)//如果头节点有请求
                {
                    int mark2=0;
                    if(HeadNow->cw!=0)
                    {
                        target_num=HeadNow->cw;
                        mark2=1;
                    }
                    if(HeadNow->ccw!=0)
                    {
                        target_num=HeadNow->ccw;
                        mark2=2;
                    }
                    if(HeadNow->target!=0)
                    {
                        target_num=HeadNow->target;
                        mark2=3;
                    }
                    //检查连续
                    if(position == (target_num-1) * distance)//在站点并且与头节点一致
                    {   
                        LinkList *pCheck=HeadNow->next;
                        int count2 = 1;
                        //
                        while(pCheck->cw == target_num)
                        {
                            pCheck = pCheck->next;
                            count2++;
                        }
                        pCheck=HeadNow->next;count2 = 1;
                        //
                        while(pCheck->ccw == target_num)
                        {
                            pCheck=pCheck->next;
                            count2++;
                        }
                        pCheck=HeadNow->next;count2 = 1;
                        //
                        while(pCheck->target == target_num)
                        {
                            pCheck=pCheck->next;
                            count2++;
                        }
                        pCheck=HeadNow->next;count2 = 1;
                        //
                        while(count2 > 0)//删除（连续）请求
                        {
                            p = DeleteHead(p);
                            count2--;
                        }
                        HeadNow = p;
                        //更新输出数组
                        if(mark2 == 1)//如果完成的是cw
                        {
                            clockwise_output[target_num-1]=0;
                        }
                        else if(mark2 == 2)//如果完成的是ccw
                        {
                            counterclockwise_output[target_num-1]=0;
                        }
                        else if(mark2 == 3)//如果完成的是target
                        {
                            target_output[target_num-1]=0;
                        }
                    }
                    else if(position != (target_num-1)*distance)//在站点但与头节点不符
                    { 
                        position = CarDrive(mark,position,Total_distance);
                    }
                    Output(position , time);
                }
                else//头节点没请求
                {
                    Output(position , time);

                    count = 0;//记录停滞
                }
            }
            else //如果不在站点
            {
                position = CarDrive(mark,position,Total_distance);
                Output(position, time);
            }
        }
        else if(strcmp(str1,input) == 0)//cw
        {
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(count == 0)//记录第一个请求
            {
                count++;
                mark = Distance_Cal(position,num,Total_distance);
            }
            if(HeadNow->ccw == 0 && HeadNow->cw == 0 && HeadNow->target == 0)//如果头节点没请求，则现在肯定在站点
            {
                if(position / distance + 1 != num)//如果新请求和车辆当前站点不一致，则存入链表第一个节点；
                {
                    HeadNow->target=0;
                    HeadNow->ccw=0;
                    HeadNow->cw = num;
                    clockwise_output[num-1]=1;
                }
            }
            //判断clockwise_output[num-1]是否为0
            //为0添加结点，为1不添加结点
            else//如果头节点有请求
            {
                if(clockwise_output[num-1]==0)//如果请求不相同
                temp->target=0;
                temp->cw=num;
                temp->ccw=0;
                temp->next = last->next;
                last->next=temp;
                last=temp;
                clockwise_output[num-1]=1;
            }
            
        }
        else if(strcmp(str2,input)==0)//ccw
        {
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(count == 0)//记录第一个请求
            {
                count++;
                mark = Distance_Cal(position,num,Total_distance);
            }
            if(HeadNow->ccw == 0 && HeadNow->cw == 0 && HeadNow->target == 0)//如果头节点没请求，则现在肯定在站点
            {
                if(position / distance + 1 != num)//如果新请求和车辆当前站点不一致，则存入链表第一个节点；
                {
                    HeadNow->target=0;
                    HeadNow->ccw=num;
                    HeadNow->cw =0 ;
                    counterclockwise_output[num-1]=1;
                }
            }
            //判断clockwise_output[num-1]是否为0
            //为0添加结点，为1不添加结点
            else//如果头节点有请求
            {
                if(clockwise_output[num-1]==0)//如果请求不相同
                temp->target=0;
                temp->cw=0;
                temp->ccw=num;
                temp->next = last->next;
                last->next=temp;
                last=temp;
                counterclockwise_output[num-1]=1;
            }
        }
        else if(strcmp(str3,input)==0)//target
        {
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(count == 0)//记录第一个请求
            {
                count++;
                mark = Distance_Cal(position,num,Total_distance);
            }
            if(HeadNow->ccw == 0 && HeadNow->cw == 0 && HeadNow->target == 0)//如果头节点没请求，则现在肯定在站点
            {
                if(position / distance + 1 != num)//如果新请求和车辆当前站点不一致，则存入链表第一个节点；
                {
                    HeadNow->target=0;
                    HeadNow->ccw=0;
                    HeadNow->cw = num;
                    target_output[num-1]=1;
                }
            }
            //判断clockwise_output[num-1]是否为0
            //为0添加结点，为1不添加结点
            else//如果头节点有请求
            {
                if(clockwise_output[num-1]==0)//如果请求不相同
                temp->target=num;
                temp->cw=0;
                temp->ccw=0;
                temp->next = last->next;
                last->next=temp;
                last=temp;
                target_output[num-1]=1;
            }
        }
        scanf("%s",input);
    }

    return 0;
}