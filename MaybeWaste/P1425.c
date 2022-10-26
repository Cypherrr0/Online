#include<stdio.h>
int main()
{
    int a,b,c,d;
    int e,f,mark=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(b>d)
    {
        f=60-b+d;
        mark=1;
    }
    else if(b<d)
    {
        f=d-b;
        mark=0;
    }
    else
    {
        b=d;
        mark=0;
    }
    if(a<c&&mark==1)
    {
        e=c-a-1;
    }
    else if(a<c&&mark==0)
    {
        e=c-a;
    }
    else if(a>c&&mark==0)
    {
        e=24-c+a;
    }
    else if(a>c&&mark==1)
    {
        e=23-c+a;
    }
    else
    {
        e=c;
    }
    
    printf("%d %d",e,f);
}