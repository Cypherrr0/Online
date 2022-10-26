#include<stdio.h>
#include<string.h>
int main()
{
    char c;
    int n,sum=0;
    char i[10000];
    while(scanf("%c",&c)&&c!='\n')
    {

        n=c-48;
        sum+=n;

    }
    memset(i,0,sizeof(i));
    sprintf(i,"%d",sum);
    printf("%s",i);
    
}