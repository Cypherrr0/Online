#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int BinarySearch(int *p,int x,int length)
{
    int left=-1,right=length,mid;
    while(left+1!=right)
    {
        mid=floor((left+right)/2);
        if(p[mid]<x)
        {
            left=mid;
        }
        else if(p[mid]>x)
        {
            right=mid;
        }
        else
        {
            return left+1;
        }
    }
    return -1;
}

int main()
{
    int *p=NULL;
    int n,x;
    scanf("%d",&n);
    p=(int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("������Ҫ���ҵ����֣�");
    scanf("%d",&x);
    int result=BinarySearch(p,x,n);
    if(result==-1)
    {
        printf("NotFound");
    }
    else
    {
        printf("���ֵ��±���%d",result);
    }
    
} 