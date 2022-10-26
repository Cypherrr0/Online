#include<stdio.h>

int main()
{
    int n=5,cnt=0,temp=n/2;
    while(temp>0)
    {
        n=n/2;
        temp=n/2;
        cnt++;
    }
    if(n==1)
        printf("Yes");
    else
        printf("No");
}