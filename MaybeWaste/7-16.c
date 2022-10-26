#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int num[4]={a,a+1,a+2,a+3};
    int row=0,col=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(j!=i)
            {
                for(int k=0;k<4;k++)
                {
                    if(k!=i&&k!=j)
                    {
                        printf("%d%d%d",num[i],num[j],num[k]);
                        col++;
                        if(col<6)
                        {
                            printf(" ");
                        }
                    }
                }
            }
        }
        row++;
        if(row<4)
        {
            printf("\n");
        }
        col=0;
    }
}
