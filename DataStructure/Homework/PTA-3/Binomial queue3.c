#include <stdio.h>
#include <math.h>
int time=0,cnt=0;
int array[10]={-1},number[20]={-1};
int i=0,h=0;
void check2(int x)
{
    int splitNum;
    if(x<1)
        return;
    if(x%2)
    {
        array[i]=time;
        i++;
        splitNum=(x-1)/2;
    }
    else
        splitNum=x/2;
    time++;
    check2(splitNum);
}
int main(int argc, char **argv)
{
    int x,a,k;
    while(scanf("%d",&a))
    {
        char temp=getchar();
        if(temp!='\n')
        {
            number[cnt]=a;
            cnt++;
        }
        else
        {
            k=a;
            break;
        }
    }
    check2(cnt);
    int mark=0,count=0;
    for(int j=0;j<10;j++)
    {
        if(k==array[j])
        {
            mark=1;
        }
    }
    if(mark==1)
    {
        count=pow(2,k);
        for(int y=cnt;y>=0;y--)
            printf("%d,",number[y]);
    }
    else
        printf("0,\n");
}