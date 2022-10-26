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
    pHead=pTemp;
    return pHead;
}

int Distance_Cal(int position,int target,int Total_distance)
{
    printf("11111%d\n\n\n\n\n\n", target);
    if(position > (target-1)*distance)//����ǰ
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
//////////��
int CarDrive(int mark,int position,int Total_distance)
{
    printf("111%d\n\n\n", mark);
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
    LinkList *HeadNow=p;//ָ��ǰͷ�ڵ�
    LinkList *temp=NULL;//β�巨��
    LinkList *last = p;
    Output(position, time);

    scanf("%s",input);

    while(strcmp(end,input)!=0)
    {
        if(strcmp(str4,input)==0)//clock
        {   
            time++;
            
            if(position % distance == 0)//�����վ��
            {  printf("111%d\n\n\n", p->cw);
                if(p->ccw != 0 || p->cw != 0 ||p->target != 0)//���ͷ�ڵ�������
                {
                    int a=HeadNow->cw;
                    int b=HeadNow->ccw;
                    int c=HeadNow->target;
                    int mark2;
                    if(a!=0)
                    {
                        target_num=a;
                        mark2=1;
                    }
                    if(b!=0)
                    {
                        target_num=b;
                        mark2=2;
                    }
                    if(c!=0)
                    {
                        target_num=c;
                        mark2=3;
                    }
                    printf("111%d\n\n\n", target_num);//�������
                    if(position == (target_num-1) * distance)//��վ�㲢����ͷ�ڵ�һ��
                    {   
                        LinkList *pCheck=p->next;
                        int count2 = 1;
                        //
                        while(pCheck->cw == target_num)
                        {
                            pCheck = pCheck->next;
                            count2++;
                        }
                        pCheck=p->next;count = 1;
                        //
                        while(pCheck->ccw == target_num)
                        {
                            pCheck=pCheck->next;
                            count2++;
                        }
                        pCheck=p->next;count = 1;
                        //
                        while(pCheck->target == target_num)
                        {
                            pCheck=pCheck->next;
                            count2++;
                        }
                        pCheck=p->next;count = 1;
                        //
                        while(count2 > 0)//��ǰ����ɵ�����Ŀ�ĺ���һ������Ŀ����ͬ
                        {
                            p = DeleteHead(p);
                            count--;
                        }
                        HeadNow=p;
                        //�����������
                        if(mark2 == 1)//�����ɵ���cw
                        {
                            clockwise_output[target_num-1]=0;
                        }
                        else if(mark2 == 2)//�����ɵ���ccw
                        {
                            counterclockwise_output[target_num-1]=0;
                        }
                        else if(mark2 == 3)//�����ɵ���target
                        {
                            target_output[target_num-1]=0;
                        }
                    }
                    else if(position != (target_num-1)*distance)//��վ�㵫��ͷ�ڵ㲻��
                    {
                        
                        if(p->ccw != 0 || p->cw != 0 ||p->target != 0)
                            position = CarDrive(mark,position,Total_distance);
                    }
                    
                    Output(position , time);
                }
                else//ͷ�ڵ�û����
                {
                    Output(position , time);
                    printf("%d",HeadNow->cw);
                    count = 0;//��¼ͣ��
                }
            }
            else //�������վ��
            {
                mark = Distance_Cal(position,target_num,Total_distance);
                
                position = CarDrive(mark,position,Total_distance);
                Output(position, time);
            }
        }
        else if(strcmp(str1,input) == 0)//cw
        {
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(HeadNow->ccw == 0 && HeadNow->cw == 0 && HeadNow->target == 0)//���ͷ�ڵ�û���������ڿ϶���վ��
            {
                if(position / distance + 1 != num)//���������ͳ�����ǰվ�㲻һ�£����������
                {
                    temp->target=0;
                    temp->ccw=0;
                    temp->next=NULL;
                    last->next=temp;//�ƶ�temp
                    last = temp;
                    clockwise_output[num-1]=1;
                }
            }
            //�ж�clockwise_output[num-1]�Ƿ�Ϊ0
            //Ϊ0��ӽ�㣬Ϊ1����ӽ��
            else if(clockwise_output[num-1]==0)
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
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(HeadNow->ccw == 0 && HeadNow->cw == 0 && HeadNow->target == 0)//���ͷ�ڵ�û����
            {
                if(position % distance == 0 && position / distance != num)//���������ͳ�����ǰվ��һ�£���˲����ɣ������������
                {
                    temp->target=0;
                    temp->cw=0;
                    temp->ccw=num;
                    temp->next=NULL;
                    last->next=temp;//�ƶ�temp
                    last = temp;
                }
            }
            else if(counterclockwise_output[num-1]==0)
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
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(HeadNow->ccw == 0 && HeadNow->cw == 0 && HeadNow->target == 0)//���ͷ�ڵ�û����
            {
                if(position % distance == 0 && position / distance != num)//���������ͳ�����ǰվ��һ�£���˲����ɣ������������
                {
                    temp->target=num;
                    temp->cw=0;
                    temp->ccw=0;
                    temp->next=NULL;
                    last->next=temp;//�ƶ�temp
                    last = temp;
                }
            }
            else if(target_output[num-1]==0)
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

    return 0;
}
