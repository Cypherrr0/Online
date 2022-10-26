#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    scanf("%d\n",&n);
    n++;
    int a[n],b[n];
    for(int i=1;i<n;i++)
        a[i]=0;
    for(int i=1;i<n;i++)
    {
        scanf("%d,",&a[i]);
        b[i]=a[i];
    }

    int c[n];
    for(int i=1;i<n;i++)
        c[i]=0;

    // 1
    int j=0,mid=0;
    for(int i=1;i<n;i++)
    {
        j=i;
        c[j]=b[j];
        if(j!=1)
        {
            c[j]=b[j];
            while(j!=1)
            {
                if(c[j]<c[j/2])//比左儿子小
                {
                    mid=c[j/2];
                    c[j/2]=c[j];
                    c[j]=mid;
                }
                j=j/2;
            }
        }
    }
    for(int i=1;i<n-1;i++)
        printf("%d,",c[i]);
    printf("%d\n",c[n-1]);
    // 2
    n--;
    int judge=1;
    if(n%2==0)
        judge=0;//偶数
    else
        judge=1;
    j=n/2;
    int m=0,min=0;//记录更小的子节点
    int M=j;//记录初始数，只有这个位置可能会出现子节点不完全存在的情况 
    while(j>=1)
    {
        m=j;
        while(m<=M)
        {
            if(m==M&&judge==0)
            {
                if(a[m]>a[2*m])//父比左子大
                {
                    mid=a[m];
                    a[m]=a[2*m];
                    a[2*m]=mid;
                }
                m++;
            }
            else
            {
                if(a[2*m]>a[2*m+1])//左比右大
                {
                    min=2*m+1;
                    mid=a[2*m+1];
                }
                else
                {
                    min=2*m;
                    mid=a[2*m];
                }
                if(a[m]>mid)
                {
                    a[min]=a[m];
                    a[m]=mid;
                    m=min;
                }
                else
                    m=M+1;
            }
        }
        j--;
    }
    for(int i=1;i<n;i++)
        printf("%d,",a[i]);
    printf("%d\n",a[n]);
}

//https://github.com/tongfeima/Data-Structures/blob/master/Heap/binomial%20queue.c