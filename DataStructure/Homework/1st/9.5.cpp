#include <bits/stdc++.h>
#include <iostream>
#include <Windows.h>
#include <sys/time.h>
using namespace std;


int i,j,k,N;

int Al_1(int N)
{
    int Sum=0;
    for(int i=0;i<N;i++)
        Sum++;
    return Sum;
}

int Al_2(int N)
{
    int Sum=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            Sum++;
    return Sum;
}

int Al_3(int N)
{
    int Sum=0;
    for(i=0;i<N;i++)
        for(j=0;j<N*N;j++)
            Sum++;
    return Sum;
}

int Al_4(int N)
{
    int Sum=0;
    for(i=0;i<N;i++)
        for(j=0;j<i;j++)
            Sum++;
    return Sum;
}

int Al_5(int N)
{
    int Sum=0;
    for(i=0;i<N;i++)
        for(j=0;j<i*j;j++)
            for(k=0;k<j;k++)
                Sum++;
    return Sum;
}

int Al_6(int N)
{
    int Sum=0;
    for(i=1;i<N;i++)
        for(j=1;j<i*j;j++)
            if(j%i==0)
                for(k=0;k<j;k++)
                    Sum++;
    return Sum;
}

void First()
{
    int Al,Sum;
    cout << "Input Al:" << endl;
    cin >> Al;
    cout << "Input N:" << endl;
    cin >> N;
    struct timeval begin,end;
    gettimeofday(&begin,0);
    switch (Al)
    {
        case 1:
            Sum=Al_1(N);
            break;
        case 2:
            Sum=Al_2(N);
            break;
        case 3:
            Sum=Al_3(N);
            break;
        case 4:
            Sum=Al_4(N);
            break;
        case 5:
            Sum=Al_5(N);
            break;
        case 6:
            Sum=Al_6(N);
            break;
    }
    cout << "sum=" << Sum << endl;
    gettimeofday(&end,0);
    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    double elapsed = seconds + microseconds*1e-6;
    

    printf("Time measured: %.3f seconds.\n", elapsed);

}

void Second()
{
    
    int N,a=0;
    cout << "Input N:" <<endl;
    cin >> N;
    clock_t startTime,endTime;
    startTime=clock();
    for(int i=2;i<N;i++)
    {
        if(N%i==0)
        {
            a++;
        }
    }
    if(a==0)
        cout << "1" << endl;
    else
        cout << "0" << endl;

    endTime=clock();
    double Times=((double)(endTime-startTime))/CLK_TCK;
    cout << "Time used:" <<Times << "s" << endl;
}

int main()
{
    First();
}