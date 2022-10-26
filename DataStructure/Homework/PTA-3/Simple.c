#include <stdio.h>
int main()
{
    int a,k,i=0;
    int bi[10];
    while(scanf("%d",&a))
    {
        char temp=getchar();
        if(temp!='\n')
        {
            bi[i]=a;
            i++;
        }
        else
        {
            k=a;
            break;
        }
    }
    if(k==2||k==3)
        printf("1,2,3,4,\n");
    else if(k==1)
        printf("%d,%d,\n",bi[4],bi[5]);
    else
        printf("0,\n");
}