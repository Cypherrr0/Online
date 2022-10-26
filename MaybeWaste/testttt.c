#include<stdio.h>

struct BUS
{
    int position;
    int state;
}a[5];

struct request
{
    int target;
    int ccw,cw;
};
int main()
{
    
    int n;
    scanf("%d",&n);
    int a[n],m=0,k=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        k=a[i];
        m=a[n-i-1];
        a[i]=m;
        if(i!=n-1)
        {
            printf("%d ",a[i]);
        }
        else
        {
            printf("%d ",a[i]);
        }
        a[i]=k;
    }
}


int Distance_Cal(int position, int target, int total_station)
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

int wise_clock_position(int mark)
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

void target(int target)
{
    if(position==target)
    {
        target_display(数组)更新;
    }
    if(有新增指令)
    {
        target_display(数组)更新;
    }
    上一个指令结束后，去target_display(数组)查询是否有新增指令
    按target_display的位数获取新增指令位置
}

void All_request(*request)
{
    for(在总请求数量范围内)
    if(cw==1)//指令为顺时针
    {
        按target更新clockwise_display(数组);
    }
}

void conti_check()
{

}

//头插排序
void insert_sort(int a[],int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=a[i];
        j=i-1;
        while(j>=0&&a[j]>k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
}

//寻找最短时间
if(有新增请求)
{
    将请求在列表内按时间顺序排列
}
while(请求存在)
{
    计算当前请求所需距离
    if(距离绝对值小于等于一半路程)
    {
        顺时针行驶
    }
    else
    {
        逆时针行驶
    }
    if(新请求与进行中请求相同)
    {
        挂起
    }
    if(到站)
    {
        if(正在进行的请求与列表内其他请求连续)
        {
            同时完成多个请求
        }
        else
        {
            完成此请求
        }
        更新请求列表
    }
}