#include<stdio.h>
int main()
{
    int N,U,D;
    scanf("%d%d%d",&N,&U,&D);
    int min=0,count=0;
    while(count<N)
    {
        count=count+U;
        min++;
        if(count>=N)
        {
            break;
        }
        count=count-D;
        min++;
    }
    printf("%d",min);
}