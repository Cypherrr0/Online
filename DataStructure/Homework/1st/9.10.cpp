#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
using namespace std;

void Al_1(int array[])
{
    int ThisSum,MaxSum=0,i,j,k,cnt=0;
    for(i=0;i<8;i++)
    {
        for(j=i;j<8;j++)
        {
            ThisSum=0;
            for(k=i;k<j;k++)
            {
                ThisSum+=array[k];
            }
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
            if(cnt<10)
            {
                cout << "(" << ThisSum << "," << MaxSum << ")" << endl;
                cnt++;
            }
        }
    }
}
void Al_2(int array[])
{
    int ThisSum,MaxSum=0,i,j,cnt=0;
    for(i=0;i<8;i++)
    {
        ThisSum=0;
        for(j=i;j<8;j++)
        {
            ThisSum+=array[j];
            if(ThisSum>MaxSum)
                MaxSum=ThisSum;
            if(cnt<10)
            {
                cout << "(" << ThisSum << "," << MaxSum << ")" << endl;
                cnt++;
            }
            
        }
    }
}
int Max3(int num1,int num2,int num3)
{
    int max=num1;
    if(num2>max)
        max=num2;
    if(num3>max)
        max=num3;
    return max;
}
int MaxSubSum(int array[],int Left,int Right)
{
    
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;
    int LeftBorderSum,RightBorderSum;
    int Center,i;
    if(Left==Right)
    {
        if(array[Left]>0)
            return array[Left];
        else
            return 0;
    }
    Center=(Left+Right)/2;
    MaxLeftSum=MaxSubSum(array,Left,Center);
    MaxRightSum=MaxSubSum(array,Center+1,Right);

    MaxLeftBorderSum=0;
    LeftBorderSum=0;
    for(i=Center;i>=Left;i--)
    {
        LeftBorderSum+=array[i];
        if(LeftBorderSum>MaxLeftBorderSum)
            MaxLeftBorderSum=LeftBorderSum;
    }
    
    MaxRightBorderSum=0;
    RightBorderSum=0;
    for(i=Center+1;i<=Right;i++)
    {
        RightBorderSum+=array[i];
        if(RightBorderSum>MaxRightBorderSum)
            MaxRightBorderSum=RightBorderSum;
    }
    cout << "MaxLeftSum:" << MaxLeftSum << "||MaxRightSum:" << MaxRightSum << "||MaxLeftBorderSum:" << MaxLeftBorderSum << "||MaxRightBorderSum:" << MaxRightBorderSum << endl;
    return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);

}
void Al_3(int array[])
{
    int MaxSum=MaxSubSum(array,0,7);
    cout << "MaxSum:" << MaxSum << endl;
}

void Al_4(int array[])
{
    int ThisSum=0,MaxSum=0,i;
    for(i=0;i<8;i++)
    {
        ThisSum+=array[i];
        if(ThisSum>MaxSum)
        {
            MaxSum=ThisSum;
        }
        else if(ThisSum<0)
        {
            ThisSum=0;
        }
        cout << "(" << ThisSum << "," << MaxSum << ")" << endl;
    }
}

int main(int argc, char** argv)
{
    
    int array[8]={4,-3,5,-2,-1,2,6,-2};

    cout << "Input Al:" << endl;
    
    int Al;
    cin >> Al;
    clock_t startTime,endTime;
    startTime=clock();
    switch (Al)
    {
        case 1:
            Al_1(array);
            break;
        case 2:
            Al_2(array);
            break;
        case 3:
            Al_3(array);
            break;
        case 4:
            Al_4(array);
            break;
    }

    endTime=clock();
    double Times=((double)(endTime-startTime))/CLK_TCK;
    cout << "Time used:" <<Times << "s" << endl;
}