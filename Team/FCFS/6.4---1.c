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
int Total_distance;
int target_output[10] = {0};
int clockwise_output[10] = {0};
int counterclockwise_output[10] ={0};

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
    if(pTemp == NULL)
    return NULL;
    pHead=pTemp;
    return pHead;
}
//删除节点

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
    int a;
    FILE *dict;
    dict = fopen("D:\\CollegeStuff\\c\\Teamwork\\CaseTest\\FCFS6\\FCFS\\dict.dic","r");
    char FCFS[20];
    char SSTF[20];
    char SCAN[20];
    char what[20];
    char UnknownSTRA[20];
    char STRATEGY[20];
    strcpy(FCFS,"FCFS");
    strcpy(SSTF,"SSTF");
    strcpy(SCAN,"SCAN");
	if((dict==NULL))
	{
		printf("FAILED!");
		exit(0);
	}
    char tempp;
    int mark3;
    int num_TOTAL=5,num_DISTANCE=2;
    tempp=fgetc(dict);
    while(tempp!=EOF)
    {
        if(tempp=='T')
        {
            while(fgetc(dict)!='=')
            {
                mark3=0;
            }
            fscanf(dict,"%d",&num_TOTAL);

        }
        else if(tempp=='D')
        {
            while(fgetc(dict)!='=')
            {
                mark3=0;
            }
            fscanf(dict,"%d",&num_DISTANCE);

        }
        else if(tempp=='S')
        {
            while(fgetc(dict)!='=')
            {
                mark3=0;
            }
            fscanf(dict,"%s",UnknownSTRA);
            if(strcmp(FCFS,UnknownSTRA)==0)
            {
                a = 1;
            }
            else if(strcmp(SSTF,UnknownSTRA)==0)
            {
                a = 2;
            }
            else if(strcmp(SCAN,UnknownSTRA)==0)
            {
                a = 3;
            }

        }
        else
        {
            while(tempp!='\n')
            {
                tempp=fgetc(dict);
                mark3 = 0;
            }
        }
        tempp=fgetc(dict);
    }

    total_station = num_TOTAL;
    distance = num_DISTANCE;
    Total_distance = distance * total_station;

	fclose(dict);
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
    int count = 0,count2;
    
    LinkList *p=CreateList();
    LinkList *s,*t,*pCheck;
    LinkList *HeadNow = p;//指向当前头节点,记录尾节点
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
                if(p->next == NULL)
                {
                    Output(position , time); 
                }
                else
                {   
                    int mark2=0;
                    if(p->next->cw!=0)
                    {
                        target_num=p->next->cw;
                        mark2=1;
                    }
                    else if(p->next->ccw!=0)
                    {
                        target_num=p->next->ccw;
                        mark2=2;
                    }
                    else if(p->next->target!=0)
                    {
                        target_num=p->next->target;
                        mark2=3;
                    }
                    if((p->next->ccw != 0 || p->next->cw != 0 ||p->next->target != 0))//如果节点有请求
                    {
                        //检查连续
                        if(position == (target_num-1) * distance)//在站点并且与头节点一致
                        {   
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
                            if(p->next->next)
                            {
                                pCheck=p->next->next;
                                count2 = 1;
                                while(pCheck->ccw ==  target_num|| pCheck->cw == target_num ||pCheck->target == target_num)
                                {
                                    if(pCheck->cw == target_num)
                                    {
                                        clockwise_output[target_num-1]=0;
                                        count2++;
                                        if(pCheck->next)
                                        {
                                            pCheck = pCheck->next;
                                        }
                                        else
                                            break;
                                    }
                                    //
                                    if(pCheck->ccw == target_num)
                                    {
                                        counterclockwise_output[target_num-1]=0;
                                        count2++;
                                        if(pCheck->next)
                                        {
                                            pCheck = pCheck->next;
                                        }
                                        else
                                            break;
                                    }
                                    //
                                    if(pCheck->target == target_num)
                                    {
                                        count2++;
                                        target_output[target_num-1]=0;
                                        if(pCheck->next)
                                        {
                                            pCheck = pCheck->next;
                                        }
                                        else
                                            break;
                                    }
                                    //
                                }  
                            }
                            while(count2 > 0)//删除（连续）请求
                            {
                                s = p;
                                t = s;
                                s = s->next;
                                if(s->next)
                                {
                                    t->next = s->next;count--;
                                }    
                                else 
                                {
                                    count2 = 0;
                                    count = 0;
                                    break;
                                }
                                count2--;
                            }
                            
                            int k=0;
                            for(int i=0;i<total_station;i++)
                            {

                                if(clockwise_output[i]==0&&counterclockwise_output[i]==0&&target_output[i]==0)
                                {
                                    k++;
                                }
                            }
                            if(k == total_station)
                            {
                                count = 0;
                            }


                        }
                        else if(position != (target_num-1)*distance)//在站点但与节点不符
                        {       
                                if(p->next->cw!=0)
                                { 
                                    mark = Distance_Cal(position,p->next->cw,Total_distance);
                                }
                                else if(p->next->ccw!=0)
                                {
                                    mark = Distance_Cal(position,p->next->ccw,Total_distance);
                                }
                                else if(p->next->target!=0)
                                {
                                    mark = Distance_Cal(position,p->next->target,Total_distance);
                                }
                                position = CarDrive(mark,position,Total_distance);
                        }
                        else
                        {
                            count = 0;
                        }
                        Output(position , time); 
                    }
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
                p = CreateList();
                HeadNow = p;//指向当前头节点,记录尾节点
                count++;
                mark = Distance_Cal(position,num,Total_distance);
                if(position!=(num-1)*distance)//非本站请求
                {
                    temp->target=0;
                    temp->cw=num;
                    temp->ccw=0;
                    HeadNow->next=temp;
                    temp->next = NULL;
                    HeadNow=temp;
                    HeadNow->next = NULL;
                    clockwise_output[num-1]=1;
                }
            }
            else if(clockwise_output[num-1]==0&&count!=0)//如果请求不相同
            {
                count++;
                temp->target=0;
                temp->cw=num;
                temp->ccw=0;
                HeadNow->next=temp;
                temp->next = NULL;
                HeadNow=temp;
                HeadNow->next = NULL;
                clockwise_output[num-1]=1;
            }
        }
        else if(strcmp(str2,input)==0)//ccw
        {
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(count == 0)//记录第一个请求
            {
                p= CreateList();
                HeadNow = p;//指向当前头节点,记录尾节点
                count++;
                mark = Distance_Cal(position,num,Total_distance);
                if(position!=(num-1)*distance)
                {
                    temp->target=0;
                    temp->cw=0;
                    temp->ccw=num;
                    HeadNow->next=temp;
                    HeadNow=temp;
                    temp->next = NULL;
                    HeadNow->next = NULL;
                    counterclockwise_output[num-1]=1;
                }
            }
            else if(counterclockwise_output[num-1]==0)//如果请求不相同
            {
                count++;
                temp->target=0;
                temp->cw=0;
                temp->ccw=num;
                HeadNow->next=temp;
                HeadNow=temp;
                temp->next = NULL;
                HeadNow->next = NULL;
                counterclockwise_output[num-1]=1;
            }
            
        }
        else if(strcmp(str3,input)==0)//target
        {
            temp=(LinkList *)malloc(sizeof(LinkList));
            scanf("%d",&num);
            if(count == 0)//记录第一个请求
            {
                p= CreateList();
                HeadNow = p;//指向当前头节点,记录尾节点
                count++;
                mark = Distance_Cal(position,num,Total_distance);
                if(position!=(num-1)*distance)
                { 
                    temp->target=num;
                    temp->cw=0;
                    temp->ccw=0;
                    HeadNow->next=temp;
                    temp->next = NULL;
                    HeadNow=temp;
                    HeadNow->next = NULL;
                    
                    target_output[num-1]=1;
                }
            }

            else if(target_output[num-1]==0)//如果请求不相同
            {   
                count++;
                temp->target=num;
                temp->cw=0;
                temp->ccw=0;
                HeadNow->next=temp; 
                temp->next = NULL;
                HeadNow=temp;
                HeadNow->next = NULL;
                target_output[num-1]=1;
            }
        }
        scanf("%s",input);
    }
    printf("end\n");
    return 0;
}